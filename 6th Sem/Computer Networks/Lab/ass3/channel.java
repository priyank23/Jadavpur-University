package ass3;
//Setting station id as a 3 bit encoded header | Ex- 010 represents staion number 2
import java.io.*;
import java.net.*;
import java.util.Vector;
import java.util.Random;

class ServerSide
{
    static int busy=0;
    private Socket socket = null;
    private ServerSocket server = null;
    private DataInputStream in =null;
    private DataOutputStream out =null;
    static Vector<String> v = new Vector<String>();
    static Vector<ClientHandler> clients = new Vector<ClientHandler>();

    ServerSide(int port) throws IOException
    {
        
        server = new ServerSocket(port);
        System.out.println("Server Started!");
        System.out.println("Waiting for a client ...");
        while(true)
        {    
            socket = server.accept();
            if(v.contains(socket.getLocalAddress().toString()))
            {
                System.out.println("Duplicate IP tried to connect!!");
                out = new DataOutputStream(socket.getOutputStream());
                out.writeUTF("Rejected");
                out.close();
                socket.close();
            }
            else
            {
                v.add(socket.getLocalAddress().toString());
                System.out.println("New Client connected: "+ socket.getLocalAddress());
                in =new DataInputStream(new BufferedInputStream(socket.getInputStream()));
                out = new DataOutputStream(socket.getOutputStream());
                out.writeUTF("Accepted");
                ClientHandler ch = new ClientHandler(socket, in, out);
                clients.add(ch);
                ch.start();
            }
        } 
    }
}
class channel
{
    public static void main(String args[]) throws IOException
    {
        ServerSide server = new ServerSide(5000);
    }
}
//Assuming Transmission time tp=3s max
class ClientHandler extends Thread
{
    DataInputStream in;
    DataOutputStream out;
    Socket s;
    String IP;
    

    ClientHandler(Socket s, DataInputStream input, DataOutputStream output)
    {
        this.s =s;
        in = input;
        out= output;
    }
    void sense() throws InterruptedException
    {
        System.out.println(IP+" Sensing Channel...");
        int i=0;
        while(ServerSide.busy!=0){sleep(100);i++;}
        System.out.println(IP+" Clear to Send after "+Double.toString(i*0.1)+"s");
        ServerSide.busy=1;
    }
    void clear()
    {
        ServerSide.busy=0;
    }
    public void run()
    {
        IP = s.getLocalAddress().toString();
        String line = "";
        try
        {
            while(true)
            {
                line = in.readUTF();
                if (line.equals("close")|| line.equals("DONE")) 
                {
                    System.out.println("Client IP:"+IP+": Connection is now terminated");
                    ServerSide.v.remove(IP);
                    ServerSide.clients.remove(this);
                    s.close();
                    in.close();
                    out.close();
                    return;
                }
                System.out.println("Client IP:"+IP+": "+line);
                /*
                if(line.charAt(0)=='/' || line.substring(3,line.length()-3).equals("Received"))
                {
                    sense();
                    for(ClientHandler x: ServerSide.clients)
                    {   
                        System.out.println("Checking: " + x.IP + " " + IP);
                        if(!x.IP.equals(IP)){
                        System.out.println("Sending "+line+" to " +x.IP);
                        x.out.writeUTF(line);
                        }
                    }
                    clear();
                    continue;
                }*/

                sense();
                sleep(1000);
                /*  Inducing corruption to the bits
                Random rand = new Random();
                int rand_int,rand_int2;
                rand_int=rand.nextInt(100);
                rand_int2 = rand.nextInt(8);
                if(rand_int<40) {
                    System.out.println("Corrupting...");
                    line= line.substring(0,rand_int2) + Integer.toString(((line.charAt(rand_int2)-48)^1)) +line.substring(rand_int2+1);
                }    */
                for(ClientHandler x: ServerSide.clients)
                {   
                    // System.out.println("Checking: " + x.IP + " " + IP);
                    if(!x.IP.equals(IP) && ServerSide.v.contains(x.IP)){
                    System.out.println("Sending "+line+" to " +x.IP+"\n");
                    x.out.writeUTF(line);
                    }
                }
                line=" ";
                clear();
            }
        }
        catch(IOException e)
        {
            e.printStackTrace();
        }
        catch(InterruptedException e)
        {
            e.printStackTrace();
        }
    }
}