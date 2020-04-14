package ass3;
import ass1.*;
import java.net.*;
import java.io.*;

class ClientSide
{
    private Socket socket =null;
    private DataInputStream input =null;
    private DataOutputStream out = null;
    private DataInputStream input2 =null;
    private String stnID="000";
    private String rstnID="000";

    ClientSide(String address, int port) throws IOException
    {
        stnID=Integer.toBinaryString(Integer.parseInt(address.substring(8)));
        while(stnID.length()<3) stnID="0"+stnID;
        System.out.println("Station ID: " +stnID);
        socket =new Socket(address,port);
        input2 =new DataInputStream(new BufferedInputStream(socket.getInputStream()));
        String msg = input2.readUTF();
        if(msg.equals("Rejected"))
        {
            System.out.println("Connection Refused");
            System.exit(1);
        }
        System.out.println("Connected");
        System.out.println(socket);
        input = new DataInputStream(System.in);
        out = new DataOutputStream(socket.getOutputStream()); 
    }
    String[] encode(String fileName) throws IOException
    {    
        ass1.error_module er = new ass1.error_module();
        ass1.files f = new ass1.files();
        String val=f.readFile(fileName);
        val=er.VRC(val,8);
        String[] frames = new String[val.length()/9];
        for(int j=0;j<val.length()/9;j++)
        {
            frames[j]=rstnID+val.substring(j*9,(j+1)*9)+stnID;
        }
        return frames;
    }
    String decode(String frame)
    {
        if(!frame.substring(0,3).equals(stnID)) return "REJECT";
        rstnID=frame.substring(frame.length()-3);
        frame=frame.substring(3,frame.length()-3);
        System.out.println("Receiving from "+rstnID+": "+frame);
        if(!ass1.Checker.VRC(frame))
            return "Corrupted";
        return ass1.Checker.out;
    }
    void saw_send(String[] frames) throws IOException
    {
        // out.writeUTF(socket.getLocalAddress().toString());  //Sending IP of the Station as the first frame
        for(int i=0;i<frames.length;i++)
        {
            // sense();
            System.out.println("Sending frame: " + frames[i]);
            out.writeUTF(frames[i]);
            String ack=input2.readUTF();
            //while(ack.substring(3,ack.length()-3).equals("Received")&& !ack.substring(0,3).equals(stnID)) ack=input2.readUTF();
            while(!ack.equals(stnID+"Received"+rstnID))
            {
                /*
                System.out.println("Sending Frame again...");
                out.writeUTF(frames[i]);*/
                ack=input2.readUTF();
            }
            System.out.println("Sending next frame");
        }
        String ack="000";
        while(!ack.equals(stnID+"Received"+rstnID))
        {
            // sense();
            System.out.println("Sending frame: 010101110");
            out.writeUTF(rstnID+"010101110"+stnID);  // 010101110 denotes the message has ended
            while(!ack.substring(0,3).equals(stnID)) ack=input2.readUTF();
        }
        System.out.println("Message Sent.");
    }
    void saw_receive() throws IOException
    {
        String frame="";
        String msg="";
        frame=input2.readUTF();
        while(!frame.equals(stnID+"010101110"+rstnID))  //checking for message end
        {
            System.out.println("Read frame:"+frame);
            String temp=decode(frame);
            ass1.Checker.out="";
            // sense();
            if(temp.equals("REJECT")){System.out.println("Rejecting.");}
            else if(temp.equals("Corrupted") && !frame.equals(stnID+"010101110"+rstnID))
            {
                System.out.println("Frame Corrupted");
                out.writeUTF(rstnID+"Corrupted"+stnID);
            }
            else if(!frame.equals(stnID+"010101110"+rstnID))
            {
                System.out.println("Decoded frame: "+temp+" sending ACK...");
                out.writeUTF(rstnID+"Received"+stnID);
                msg=msg+temp;
            }
            frame=input2.readUTF();
        }    
        // sense();
        out.writeUTF(rstnID+"Received"+stnID);
        System.out.println("Message Received Successfully.");
        ass1.files f = new ass1.files();
        f.writeFile("./ass2/received messages/"+rstnID,msg);
    }
    void sender() throws IOException
    {
        String frames[] = encode("./ass2/message.txt");
        saw_send(frames);
    }
    void run() throws IOException
    {
        System.out.println("Want to send?(Y/n)");
        String c=input.readLine();
        if(c.equals("Y") || c.equals("y"))
        {
            System.out.println("Enter receiver's IP");
            String IP=input.readLine();
            rstnID=Integer.toBinaryString(Integer.parseInt(IP.substring(8)));
            while(rstnID.length()<3) rstnID="0"+rstnID;
            System.out.println("Station ID: " +rstnID);
            System.out.println("Sending..");
            saw_send(encode("./ass2/message.txt"));
            System.out.println("Message Sent successfully");
        }
        else
        {
            System.out.println("Receiving..");
            saw_receive();
        }
    }
    void close() throws IOException
    {
        out.writeUTF("close");
        input.close();
        input2.close();
        out.close();
        System.out.println("Client IP: " + socket.getLocalAddress() +" is terminated.");
        socket.close();
    }
}
class station
{
    public static void main(String args[]) throws IOException
    {
        DataInputStream in =new DataInputStream(System.in);
        System.out.println("Enter Client IP");
        String IP = in.readLine();
        
        ClientSide client = new ClientSide(IP, 5000);
        String c="y";
        client.run();
        //System.out.println("Do you want to continue?[y/n]");
        // c=in.readLine();
        client.close();
    }
}