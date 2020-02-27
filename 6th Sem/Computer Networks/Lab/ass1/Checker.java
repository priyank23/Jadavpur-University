package ass1;
import java.io.*;
import java.util.*;
public class Checker
{
    public static String out="";
    public static boolean VRC(final String input) {
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
            out = out + input1.substring(0, 8);
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
        if(x.equals("1111")) return true;
        int y,z=0;
       if(x.length()>4) {y=Integer.parseInt(x.substring(0,x.length()-4),2);z=Integer.parseInt(x.substring(x.length()-4,x.length()),2);}
       else y=Integer.parseInt(x);
       x=Integer.toBinaryString(y+z);
        if(Integer.parseInt(x,2)==15) return true; 
        return false;
    }

    static boolean CRC(int data[],int choice)
    {
        out="";
        int remainder[] = error_module.CRC(data, choice);

        for(int i=0 ; i < remainder.length ; i++) {
			if(remainder[i] != 0) {
				// If remainder is not zero then there is an error
				//System.out.println("There is an error in received data...");
				return false;
			}
        }
        for(int i=0;i<data.length-error_module.cp[choice-1].length();i++) out=out+(char)(data[i]+48);
        return true;
    }
}