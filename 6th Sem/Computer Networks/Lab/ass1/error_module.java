package ass1;
import java.io.*;
import java.util.*;
public class error_module
{
    public String VRC(String input,int frameLen)
    {
        String output="";
        int parity;
        for(int j=0;j<input.length()/frameLen;j++)
        {
            String input1=input.substring(j*frameLen,(j+1)*frameLen);
            // System.out.println(input1);
            parity=0;
            for(int i=0;i<input1.length();i++)
            {
                if(input1.charAt(i)=='1') parity++;
            }
            if(parity%2==0) output= output+input1+'0';
            else output=output+input1+'1';
        }
        return output;
    }


    String LRC(String input,int frameLen)
    {
        String output="";
        String input1[]=new String[4];

        for(int i=0;i<input.length()/(4*frameLen);i++)
        {
            output+=input.substring(4*i*frameLen,4*(i+1)*frameLen);
            for(int j=0;j<4;j++)
            {
                input1[j]=input.substring((4*i+j)*frameLen,(4*i+j+1)*frameLen);
            }

            String intermediate="";

            for(int j=0;j<frameLen;j++)
            {
                int parity=0;
                for(int k=0;k<4;k++)
                {
                    if(input1[k].charAt(j)=='1') parity++;
                }
                if(parity%2==0) intermediate=intermediate+'0';
                else intermediate=intermediate+'1';
            }
            output+=intermediate;
        }
        return output;
    }

    String checksum(String input,int frameLen)
    {
        String output=input;
        int sum=0;

        for(int i=0;i<input.length()/frameLen;i++)
        {
            sum+=Integer.parseInt(input.substring(i*frameLen,(i+1)*frameLen),2);
        }
        String x=Integer.toBinaryString(sum);
        System.out.println(sum);
        while(x.length()>4){
        int y=Integer.parseInt(x.substring(0,x.length()-frameLen),2),z=Integer.parseInt(x.substring(x.length()-4),2);
        System.out.println(Integer.toString(y)+'\n'+Integer.toString(z));
        x=Integer.toBinaryString(y+z);}
        System.out.println(x.length());
        while(x.length()<4) x='0'+x;
        System.out.println(x);
        for(int i=0;i<x.length();i++)
        {
            if(x.charAt(i)=='0') output+='1';
            else output+='0';
        }
        return output;
    }
    static String cp[]={"11","10011","110101","100101","1000011","10001001","100000111","110001101","100110001"};

    static int[] CRC(int old_data[], int choice) {
        if(cp[choice-1].length()>=old_data.length) return null;
        int divisor[]=new int[cp[choice-1].length()];
        for(int i=0;i<cp[choice-1].length();i++) divisor[i]=(int)cp[choice-1].charAt(i) - 48;
        int remainder[] , i;
        int data[] = new int[old_data.length + divisor.length];
        System.arraycopy(old_data, 0, data, 0, old_data.length);
        // Remainder array stores the remainder
        remainder = new int[divisor.length];
        // Initially, remainder's bits will be set to the data bits
        System.arraycopy(data, 0, remainder, 0, divisor.length);
        
        // Loop runs for same number of times as number of bits of data
        // This loop will continuously exor the bits of the remainder and
        // divisor
        for(i=0 ; i < old_data.length ; i++) {
            if(remainder[0] == 1) {
                // We have to exor the remainder bits with divisor bits
                for(int j=1 ; j < divisor.length ; j++) {
                    remainder[j-1] = exor(remainder[j], divisor[j]);
                }
            }
            else {
                // We have to exor the remainder bits with 0
                for(int j=1 ; j < divisor.length ; j++) {
                    remainder[j-1] = exor(remainder[j], 0);
                }
            }
            // The last bit of the remainder will be taken from the data
            // This is the 'carry' taken from the dividend after every step
            // of division
            remainder[divisor.length-1] = data[i+divisor.length];
        }
        return remainder;
    }

    static int exor(int a, int b) {
		if(a == b) return 0;
		return 1;
	}
}
