package ass2;

import java.io.*;
import java.net.*;
import java.util.Vector;
import java.util.Random;

class ServerSide
{
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
class Server
{
    public static void main(String args[]) throws IOException
    {
        ServerSide server = new ServerSide(5000);
    }
}

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
    public void run()
    {
        IP = s.getLocalAddress().toString();
        String line = "";
        try
        {
            while(true)
            {
                line = in.readUTF();
                if (line.equals("close")) 
                {
                    System.out.println("Client IP:"+IP+": Connection is now terminated");
                    ServerSide.v.remove(IP);
                    s.close();
                    in.close();
                    out.close();
                    return;
                }
                System.out.println("Client IP:"+IP+": "+line);
                System.out.println(s);
                if(line.charAt(0)=='/' || line.equals("Received"))
                {
                    for(ClientHandler x: ServerSide.clients)
                    {   
                        System.out.println("Checking: " + x.IP + " " + IP);
                        if(!x.IP.equals(IP)){
                        System.out.println("Sending "+line+" to " +x.IP);
                        x.out.writeUTF(line);
                        }
                    }
                    continue;
                }
                Random rand = new Random();
                int rand_int,rand_int2;
                try
                {
                    sleep(3000);
                    rand_int=rand.nextInt(100);
                    rand_int2 = rand.nextInt(8);
                    if(rand_int<40) {
                        System.out.println("Corrupting...");
                        line= line.substring(0,rand_int2) + Integer.toString(((line.charAt(rand_int2)-48)^1)) +line.substring(rand_int2+1);
                    }    
                    for(ClientHandler x: ServerSide.clients)
                    {   
                        System.out.println("Checking: " + x.IP + " " + IP);
                        if(!x.IP.equals(IP)){
                        System.out.println("Sending "+line+" to " +x.IP);
                        x.out.writeUTF(line);
                        }
                    }
                }
                catch (InterruptedException e)
                {
                    e.printStackTrace();
                }
            }
        }
        catch(IOException e)
        {
            e.printStackTrace();
        }
    }
}