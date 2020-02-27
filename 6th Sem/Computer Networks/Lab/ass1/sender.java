package ass1;

import java.io.*;
import java.util.*;

class sender
{
    public static void main(String[] args) throws IOException
    {
        File F=new File("./ass1/intermediate.txt");
        error_module er=new error_module();
        files f=new files();
        String str=f.readFile("./ass1/message.txt");
        // System.out.println(str);
        int len=1;
        System.out.println(" Enter any option.\n 1. VRC\n 2. LRC\n 3. CheckSum\n 4. CRC\n\nYour Choice: ");
        Scanner s=new Scanner(System.in);
        int opt=s.nextInt(),opt2=0;
        switch(opt)
        {
            case 1:
                str=er.VRC(str,8);
                break;
            
            case 2:
                str=er.LRC(str,8);
                break;
            
            case 3:
                str=er.checksum(str,4);
                break;

            case 4:{
                System.out.println("Select divisor (1-8): ");
                opt2=s.nextInt();
                int in[]=new int[str.length()];
                for(int i=0;i<str.length();i++)
                {
                    in[i]=str.charAt(i)-48;
                }
                int[] out=error_module.CRC(in,opt2);
                for(int i=0;i<out.length;i++)
                {
                    str+=(char)(out[i]+48);
                }
                break;
            }
        }
        System.out.println("\nMessage Sent Successfully!!!");
        FileWriter fw=new FileWriter(F);
        fw.write(Integer.toString(opt));
        if(opt==4) fw.write( Integer.toString(opt2));
        fw.write(str);
        fw.close();
    }
}