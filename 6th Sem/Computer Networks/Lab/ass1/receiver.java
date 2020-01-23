import java.io.*;
import java.util.*;

class Checker
{
    static String out="";
    static boolean VRC(final String input) {
        int parity;
        for (int j = 0; j < input.length() / 9; j++) {
            final String input1 = input.substring(j * 9, (j + 1) * 9);
            parity = 0;
            for (int i = 0; i < input1.length(); i++) {
                if (input1.charAt(i) == '1')
                    parity++;
            }
            if (parity % 2 == 1)
                return false;
            out = out + input1.substring(0, input1.length() - 1);
        }
        return true;
    }
    static boolean LRC(String input) {
        int parity;

        String input1[]=new String[5];
        for(int i=0;i<input.length()/(5*8);i++)
        {
            parity=0;
            out=out+input.substring(4*i*8,4*(i+1)*8);
            for(int j=0;j<5;j++)
            {
                input1[j]=input.substring((5*i+j)*8,(5*i+j+1)*8);
            }
            for(int j=0;j<8;j++)
            {
                for(int k=0;k<5;k++)
                {
                    if(input1[k].charAt(j)=='1') parity++;
                }
                if(parity%2==1) return false;
            }
        }
        return true;
    }

    static boolean checksum(String input)
    {
        out=input.substring(0,input.length()-4);
        int sum=0;
        for(int i=0;i<(input.length()/4);i++)
        {
            sum+=Integer.parseInt(input.substring(i*4,(i+1)*4),2);
        }
        String x=Integer.toBinaryString(sum);
        int y=Integer.parseInt(x.substring(0,x.length()-4),2),z=Integer.parseInt(x.substring(x.length()-4,x.length()),2);
        x=Integer.toBinaryString(y+z);
        if(Integer.parseInt(x,2)==15) return true; 
        return false;
    }
}

class Receiver {
    static String readFile(final String filename) throws IOException {
        File f = new File(filename);
        Scanner s = new Scanner(f);
        String str = s.nextLine();
        return str;
    }

    public static void main(final String[] args) throws IOException {
        String str = readFile("intermediate.txt");
        boolean res = Checker.checksum(str);
        if(res==false) System.out.println("Error detected!!");
        else {
            System.out.println("No Error detected!!\n Message Receiver: "+Checker.out);
        }
    }
}