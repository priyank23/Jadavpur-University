package ass1;
import java.io.*;
import java.util.*;



class Receiver {
    static String readFile(final String filename) throws IOException {
        File f = new File(filename);
        Scanner s = new Scanner(f);
        String str = s.nextLine();
        return str;
    }

    public static void main(final String[] args) throws IOException {
        String str = readFile("./ass1/intermediate.txt");
        int opt=str.charAt(0)-48;
        boolean res=false;
        str=str.substring(1);
        // System.out.println(str);
        switch(opt)
        {
            case 1:
                res=Checker.VRC(str);
                break;
            case 2:
                res=Checker.LRC(str);
                break;
            case 3:
                res=Checker.checksum(str);
                // System.out.println(1);
                break;
            case 4:
            {
                int opt2=str.charAt(0)-48;
                str=str.substring(1);
                int in[]=new int[str.length()];
                for(int i=0;i<str.length();i++)
                {
                    in[i]=str.charAt(i)-48;
                }
                res = Checker.CRC(in,opt2);
                break;
            }
        }
        if(res==false) System.out.println("Error detected!!");
        else {
            System.out.println("No Error detected!!\n Message Received: "+Checker.out);
        }
    }
}