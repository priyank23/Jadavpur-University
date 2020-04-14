package ass3;
//Setting station id as a 3 bit encoded header | Ex- 010 represents staion number 2
import java.io.*;
import java.net.*;
import java.util.Vector;
import java.util.Random;
import java.util.concurrent.TimeUnit;
import java.text.ParseException;

class ServerSide
{
    static long time=0;
    static long bits=0;
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
    int K;
    Random rand;
    

    ClientHandler(Socket s, DataInputStream input, DataOutputStream output)
    {
        this.s =s;
        in = input;
        out= output;
        K=8;
        rand=new Random();
    }
    void sense() throws InterruptedException
    {
        System.out.println(IP+" Sensing Channel...");
        int i=0;
        int rand_int=1;
        rand_int=rand.nextInt(10);                   // uncomment this line for non-persistent
        while(ServerSide.busy!=0){sleep((rand_int++)*100);i++;}
       // System.out.println(IP+" Clear to Send after "+Double.toString(i*rand_int*0.1)+"s");
    //    ServerSide.busy=1;  //comment this line for p-persistent
    }       
    boolean after_sense(double p) throws InterruptedException //p-persistent protocol after sensing the channel free
    {
        if(p==0) return true;
        double R=rand.nextDouble();
        if(R<=p) return true;
        sleep(1000);
        if(ServerSide.busy==1) return false;
        ServerSide.busy=1;
        return true;
    }
    void back_off() throws InterruptedException
    {
            int r=rand.nextInt((int)java.lang.Math.pow(2,K)-1);
            sleep(r*100);
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
                    ServerSide.v.remove(IP);
                    ServerSide.clients.remove(this);
                    in.close();
                    out.close();
                    s.close();
                    System.out.println("Client IP:"+IP+": Connection is now terminated");
                    if(ServerSide.v.isEmpty()) 
                    {
                        double d = (ServerSide.bits*1000)/(1.0*ServerSide.time);
                        System.out.println("Time Elapsed: "+Long.toString(ServerSide.time)+"Bits transferred: "+Long.toString(ServerSide.bits)+"Throughput of the system:"+Double.toString(d));
                    }
                    return;
                }
                System.out.println("Client IP:"+IP+": "+line);
                long start=System.nanoTime();
                boolean ok2=true;
                while(true){
                    sense();
                    boolean ok=after_sense(0.8);
                    if(!ok)
                    {
                        K--;
                        if(K!=0) back_off();
                        else {ok2=false;K=8;break;}
                    }
                    else {K=8;break;}
                }
                sleep(1000);
                
                // if(!ok2) out.writeUTF("COLLISION");
                // else
                {
                    try
                    {
                        for(ClientHandler x: ServerSide.clients)
                        {   
                            sleep(100);
                            if(ServerSide.v.contains(x.IP) && !x.IP.equals(IP) ){
                            System.out.println("Sending "+line+" to " +x.IP+"\n");
                            x.out.writeUTF(line);
                            }
                        }
                    }
                    catch(Exception e)
                    {}
                }
                long elapsedTime = TimeUnit.NANOSECONDS.toMillis(System.nanoTime() - start);
                ServerSide.time+=elapsedTime;
                ServerSide.bits+=line.length();
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