package ass4;
import ass1.files;
//Setting station id as a 3 bit encoded header | Ex- 010 represents station number 2
import java.io.*;
import java.util.*;

class Channel {
    static int data[][],rsid[];
    static int n=0,a=0;
    static WalshCode wCode;
    static int sentBit[];
    static int lastBit[],lastReceived[];
    static int receivedMessage[][];
    private boolean done[];
    private Scanner s=null;

    Channel() throws IOException {
        System.out.println("Enter number of stations:");
        s=new Scanner(System.in);
        n=s.nextInt();
        wCode = new WalshCode(n);
        done=new boolean[n];
        rsid = new int[n];
        for(int i=0;i<n;i++) done[i]=false;
        System.out.println("SSID\tRSID\tChip Set\n------------------------");
        for(int i=0;i<n;i++) {
            Random rand=new Random();
            int r=rand.nextInt(n-1);
            while(done[r] || r==i) r=(r+1)%n;
            done[r]=true;
            rsid[r]=i;
            System.out.print("#"+Integer.toString(i)+"\t#"+Integer.toString(r)+"\t");
            for(int j=0;j<n;j++) {
                System.out.print(wCode.wc[i][j]);
                System.out.print(" ");
            }
            System.out.println();
        }
        lastBit = new int[n];
        lastReceived = new int[n];
        for(int i=0;i<n;i++) {
            lastBit[i]=-1;
            lastReceived[i] = 0;
        }
        for(int i=0;i<done.length;i++) done[i]=false;
        station();
    }

    void station() throws IOException{
        initialise_data();
        sentBit = new int[n]; 
        receivedMessage = new int[n][8];
        while(!checkDone()) {
            send();
            receive();
        }
        printSummary();
    }

    //generating random frame of 8 bits to send for each station
    void initialise_data() throws IOException { 
        data = new int[n][8];
        ass1.files f = new ass1.files();
        String s = "";
        for(int i=0;i<n;i++) {
            s+="Station #"+Integer.toString(i)+"\n";
            for(int j=0;j<8;j++) {
                Random rand=new Random();
                double r = rand.nextDouble();
                if(r<0.5) data[i][j]=0;
                else data[i][j]=1;
                s+=Integer.toString(data[i][j]);
            }
            if(i < n-1) s+="\n\n";
        }
        f.writeFile("./ass4/input.txt",s);
    }

    //sending data to the channel
    void send() {
        clearSentBits();
        Random rand = new Random();
        System.out.println("\nSSID#\tBit Sent\tSentData\n--------------------------------");
        for(int i=0;i<n;i++) {
            if(lastBit[i]<7) {
                Double r=rand.nextDouble();
                if(r>0.25) {
                    System.out.print("#"+Integer.toString(i)+"\tBit["+Integer.toString(lastBit[i]+1)+"]: "+Integer.toString(data[i][lastBit[i]+1])+"\t");
                    if(data[i][++lastBit[i]]==0) 
                        for(int j=0;j<n;j++) {
                            sentBit[j] += -1*wCode.wc[i][j];
                            System.out.print(-1*wCode.wc[i][j]);
                            System.out.print(" ");
                        }
                    else
                        for(int j=0;j<n;j++) {
                            sentBit[j] += wCode.wc[i][j];
                            System.out.print(wCode.wc[i][j]);
                            System.out.print(" ");
                        }
                    System.out.println();
                }
            }
            if(lastBit[i]==7) done[i]=true;
        }
        System.out.println();
    }
    void receive() {
        for(int i=0;i<n;i++) {
            int val=0;
            if(lastReceived[i]<8){
                for(int j=0;j<n;j++) {
                    val += wCode.wc[rsid[i]][j]*sentBit[j];
                }
                if(val!=0) {
                    receivedMessage[i][lastReceived[i]++] = ((val/n)+1)/2;
                }
            }
        }
    }

    void printSummary() {
        System.out.println("\nData Transfer Summary");
        System.out.println("-------------------------------\nRSID\tSSID\tData\n-------------------------------");
        for(int i=0;i<n;i++) {
            System.out.print("#"+Integer.toString(i)+"\t#"+Integer.toString(rsid[i])+"\t");
            for(int j=0;j<8;j++) {
                System.out.print(receivedMessage[i][j]);
                System.out.print(" ");
            }
            System.out.println();
        }
    }
    void clearSentBits() {
        for(int i=0;i<n;i++) sentBit[i]=0;
    }
    boolean checkDone() {
        for(int i=0;i<done.length;i++) {
            if(!done[i]) return false;
        }
        return true;
    }
}
class channel {
    public static void main(String args[]) throws IOException {
        Channel server = new Channel();
    }
}
