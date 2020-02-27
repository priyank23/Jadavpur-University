package ass2;
import ass1.*;
import java.net.*;
import java.io.*;

class ClientSide
{
    private Socket socket =null;
    private DataInputStream input =null;
    private DataOutputStream out = null;
    private DataInputStream input2 =null;

    ClientSide(String address, int port) throws IOException
    {
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
            frames[j]=val.substring(j*9,(j+1)*9);
        }
        return frames;
    }
    String decode(String frame)
    {
        if(!ass1.Checker.VRC(frame))
            return "Corrupted";
        return ass1.Checker.out;
    }
    void saw_send(String[] frames) throws IOException
    {
        // out.writeUTF(socket.getLocalAddress().toString());  //Sending IP of the Station as the first frame
        for(int i=0;i<frames.length;i++)
        {
            System.out.println("Sending frame: " + frames[i]);
            out.writeUTF(frames[i]);
            String ack=input2.readUTF();
            if(!ack.equals("Received"))
            {
                i--;
                System.out.println("Sending Frame again...");
            }
            System.out.println("Sending next frame");
        }
        out.writeUTF("010101110");  // 010101110 denotes the message has ended
    }
    void saw_receive() throws IOException
    {
        String frame=input2.readUTF();
        System.out.println(socket);
        System.out.println(socket.getInetAddress().toString());
        System.out.println(frame);
        if(!frame.equals(socket.getInetAddress().toString())) 
        {
            System.out.println("Rejecting current frame in the channel");
            return;
        }
        
        String msg="";
        while(!frame.equals("010101110"))  //checking for message end
        {
            frame=input2.readUTF();
            System.out.println(frame);
            String temp=decode(frame);
            if(temp.equals("Corrupted"))
            {
                System.out.println("Frame Corrupted");
                out.writeUTF("Corrupted");
            }
            else
            {
                System.out.println("Frame: "+temp+" sending ACK...");
                ass1.Checker.out="";
                out.writeUTF("Received");
                msg=msg+temp;
            }
        }
        System.out.println("Message Received Successfully.");
        ass1.files f = new ass1.files();
        f.writeFile("./ass2/received messages/"+socket.getLocalAddress().toString(),msg);
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
        System.out.println(c);
        if(c.equals("Y") || c.equals("y"))
        {
            System.out.println("Enter receiver's IP");
            String IP=input.readLine();
            System.out.println("Sending..");
            out.writeUTF("/"+IP);
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
class Client
{
    public static void main(String args[]) throws IOException
    {
        DataInputStream in =new DataInputStream(System.in);
        System.out.println("Enter Client IP");
        String IP = in.readLine();
        ClientSide client = new ClientSide(IP, 5000);
        String c;
        do
        {
        client.run();
        System.out.println("Do you want to continue?[y/n]");
        c=in.readLine();
        }while(c.equals("Y") || c.equals("y"));
        client.close();
    }
}