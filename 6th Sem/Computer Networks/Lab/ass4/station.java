package ass4;
import java.net.*;
import java.io.*;
import java.util.Random;

    

class ClientSide
{
    Socket socket =null;
    DataInputStream input =null;
    DataOutputStream out = null;
    DataInputStream input2 =null;
    int n;
    int stnChip[];
    int rstnChip[];
    int frame[]=new int[8];
    int x=0;

    ClientSide(String address, int port) throws IOException,InterruptedException
    {
        socket =new Socket(address,port);
        input2 =new DataInputStream(new BufferedInputStream(socket.getInputStream()));
        String msg = input2.readUTF();
        if(msg.equals("Rejected"))
        {
            System.out.println("Connection Refused");
            System.exit(1);
        }
        n=Integer.parseInt(msg);
        stnChip=new int[n];
        rstnChip=new int[n];
        System.out.println("Connected");
        System.out.print("Allocated Chip Set:\t[");
        for(int i=0;i<n;i++)
        {
            stnChip[i]=input2.read();
            if(stnChip[i]==255) stnChip[i]=-1;
            System.out.print(stnChip[i]);
            System.out.print(" ");
        }
        System.out.print("]\nReceiver Chip Set:\t[");
        for(int i=0;i<n;i++)
        {
            rstnChip[i]=input2.read();
            if(rstnChip[i]==255) rstnChip[i]=-1;
            System.out.print(rstnChip[i]);
            System.out.print(" ");
        }
        System.out.println("]\n");
        input = new DataInputStream(System.in);
        out = new DataOutputStream(socket.getOutputStream());
        sender();
    }
    public void Receiver() throws IOException
    {
        System.out.println("Value of x:"+Integer.toString(x));
        int received[]=new int[n];
            frame[x]=0;
            System.out.println("Received code Word");
            for(int j=0;j<n;j++) 
            {
                received[j]=input2.read();
                if(received[j]==255) received[j]=-1;
                frame[x]+=received[j]*rstnChip[j];
                System.out.print(received[j]);
            }
            if(frame[x]!=0) frame[x]/=n;
            else x--;
            x++;
            System.out.println();
    } 
    public void sender()
    {
        try{
        int frame[]=new int[8];
        int toSend[][]=new int[2][n];
        for(int i=0;i<n;i++)
        {
            toSend[0][i]=stnChip[i];
            toSend[1][i]=(-1)*stnChip[i]; 
        }
        Random rand=new Random();
        System.out.println("Sending frame");
        for(int i=0;i<8;i++)
        {
            Double r=rand.nextDouble();
            if(r<0.5) frame[i]=0;
            else frame[i]=1;
            System.out.print(frame[i]);
        }
        System.out.println();
        for(int i=0;i<8;i++)
        {
            Double r=rand.nextDouble();
            if(r>0.25)
            {
                if(frame[i]==0) 
                    for(int j=0;j<n;j++){ out.write(toSend[1][j]);System.out.print(toSend[1][j]);}
                else
                    for(int j=0;j<n;j++) {out.write(toSend[0][j]);System.out.print(toSend[0][j]);}
            }
            else
            {
                i--;
                for(int j=0;j<n;j++){ out.write(0); System.out.print(0);}
            }
            System.out.println();
            if(x<8) Receiver();
        }
        System.out.println("Message Sent.");
        while(x<8){
            Receiver();
        }
        
        System.out.print("\nFinal Received Frame: ");
        for(int i=0;i<8;i++) System.out.print(frame[i]);
    }
    catch(Exception e) {}
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
    public static void main(String args[]) throws IOException,InterruptedException
    {
        DataInputStream in =new DataInputStream(System.in);
        System.out.println("Enter Client IP");
        String IP = in.readLine();
        
        ClientSide client = new ClientSide(IP, 5000);
        client.close();
    }
}