package ass2;

import java.io.*;
import java.net.*;
import java.util.Vector;

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
                for(ClientHandler x: ServerSide.clients)
                {   
                    System.out.println("Checking: " + x.IP + " " + IP);
                    if(!x.IP.equals(IP)){
                    System.out.println("Sending to :" +x.IP);
                    x.out.writeUTF(line);
                    }
                }
            }
        }
        catch(IOException e)
        {
            e.printStackTrace();
        }
    }
}