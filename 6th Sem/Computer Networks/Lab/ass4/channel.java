package ass4;
//Setting station id as a 3 bit encoded header | Ex- 010 represents station number 2
import java.io.*;
import java.net.*;
import java.util.Vector;
import java.util.Random;
import java.util.concurrent.TimeUnit;
import java.text.ParseException;

class ServerSide
{
    static int bits[],num;
    static int n=0,a=0;
    static WalshCode wCode;
    private Socket socket = null;
    private ServerSocket server = null;
    private DataInputStream in =null;
    private DataOutputStream out =null;
    static Vector<String> v = new Vector<String>();
    static Vector<ClientHandler> clients = new Vector<ClientHandler>();
    private boolean done[];

    ServerSide(int port) throws IOException
    {
        System.out.println("Enter number of stations:");
        in=new DataInputStream(System.in);
        n=in.read()-48;
        System.out.println(n);
        in.close();
        wCode = new WalshCode(n);
        bits=new int[n];
        done=new boolean[n];
        for(int i=0;i<n;i++) done[i]=false;
        clearBits();
        server = new ServerSocket(port);
        System.out.println("Server Started!");
        System.out.println("Waiting for a client ...");
        for(int i=0;i<n;i++)
        {
            socket = server.accept();
            if(v.contains(socket.getLocalAddress().toString()))
            {
                System.out.println("Duplicate IP tried to connect!!");
                out = new DataOutputStream(socket.getOutputStream());
                out.writeUTF("Rejected");
                out.close();
                i--;
                socket.close();
            }
            else
            {
                v.add(socket.getLocalAddress().toString());
                System.out.println("New Client connected: "+ socket.getLocalAddress());
                in =new DataInputStream(new BufferedInputStream(socket.getInputStream()));
                out = new DataOutputStream(socket.getOutputStream());
                out.writeUTF(Integer.toString(n));
                String Chip;
                System.out.print("Chip Set Alloted:\t[");
                for(int j=0;j<n;j++)
                {
                    System.out.print(wCode.wc[i][j]);
                    System.out.print(" ");
                    out.write(wCode.wc[i][j]);   
                }
                System.out.println("]");

                Random rand=new Random();
                int r=rand.nextInt(n-1);
                int t=0;
                while((done[r] || r==i )&& t<n) {r=(r+1)%n;t++;}
                
                if(t==n) {done[i]=true;r=i;}
                System.out.println("Sending to station #"+Integer.toString(r));
                for(int j=0;j<n;j++)
                {
                    System.out.print(wCode.wc[r][j]);
                    System.out.print(" ");
                    out.write(wCode.wc[r][j]);
                }
                ClientHandler ch = new ClientHandler(socket, in, out,n);
                clients.add(ch);
                ch.start();
            }
        }
        while(!clients.isEmpty());
    }
    static void clearBits()
    {
        for(int i=0;i<n;i++) bits[i]=0;
        num=n;
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
    Random rand;
    int n;
    

    ClientHandler(Socket s, DataInputStream input, DataOutputStream output,int n)
    {
        this.s =s;
        in = input;
        out= output;
        rand=new Random();
        this.n=n;
    }

    public void run()
    {
        IP = s.getLocalAddress().toString();
        try
        {
            for(int i=0;i<8;i++)
            { 
                boolean ok=false;
                for(int j=0;j<n;j++)
                {
                    int val=in.read();
                    if(val==255) val=-1;
                    System.out.println(val);
                    ServerSide.bits[j]+=val;
                    if(val!=0) ok=true; 
                }
                if(!ok) i--; 
                ServerSide.num=ServerSide.num-1;
                System.out.println(ServerSide.num);
                if(ServerSide.num==ServerSide.a){
                    try
                    {
                        for(ClientHandler x: ServerSide.clients)
                        {   
                            System.out.println("Sending to :" +x.IP);
                            for(int j=0;j<n;j++) {x.out.write(ServerSide.bits[j]);System.out.print(ServerSide.bits[j]);}
                        }
                    }
                    catch(Exception e)
                    {}
                    ServerSide.clearBits();
                }
            }
            ServerSide.clients.remove(this);
            ServerSide.a++;
            in.close();
            out.close();
            s.close();
        }
        catch(IOException e)
        {
            e.printStackTrace();
        }
        catch(InterruptedException e){}
    }
}