import java.io.*;
import java.util.*;

class error_module
{
    String VRC(String input,int frameLen)
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
        int y=Integer.parseInt(x.substring(0,x.length()-frameLen),2),z=Integer.parseInt(x.substring(x.length()-4,x.length()),2);
        x=Integer.toBinaryString(y+z);
        for(int i=0;i<4-x.length();i++) x='0'+x;
        for(int i=0;i<x.length();i++)
        {
            if(x.charAt(i)=='0') output+='1';
            else output+='0';
        }
        return output;
    }
}

class files 
{
    String readFile(String filename) throws IOException
    {

        File f=new File(filename);
        Scanner s=new Scanner(f);
        String str=s.nextLine();
        return str;
    }
    void WriteFile(String filename,String output) throws IOException
    {
        // System.out.println(output);
        FileWriter fw=new FileWriter(filename,false);
        PrintWriter outf=new PrintWriter(fw);
        outf.println(output);
        outf.close();
    }
}

class sender
{
    public static void main(String[] args) throws IOException
    {
        files f=new files();
        error_module er=new error_module();
        String str=f.readFile("message.txt");
        // System.out.println(str);
        int len=4;
        // System.out.println(len);
        str=er.checksum(str,len);
        f.WriteFile("intermediate.txt",str);
    }
}