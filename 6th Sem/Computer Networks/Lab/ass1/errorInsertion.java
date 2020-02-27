package ass1;
import java.io.*;
import java.util.*;
class ErrorHandling 
{
    static void insert() throws IOException
    {
        files f=new files();
        String msg=f.readFile("./ass1/intermediate.txt");
        System.out.println("Read message : " + msg);
        if(msg.length()<=2) return;
        System.out.println("Choose the type of error to insert.\n 1. Single Bit\n 2. Burst\n");
        Scanner s=new Scanner(System.in);
        int type=s.nextInt();
        Random r=new Random();
        int pos=r.nextInt(msg.length()-2)+2;
        System.out.println("Position of error : " + Integer.toString(pos));
        switch(type)
        {
            case 1:
                String msg2=msg.substring(0,pos)+Integer.toString(error_module.exor((int)msg.charAt(pos)-48,1))+msg.substring(pos+1);
                msg=msg2;
                break;
            
            case 2:
                System.out.println("Length of Burst Error: ");
                int length=s.nextInt();
                while(length--!=0)
                {
                    msg2=msg.substring(0,pos)+Integer.toString(error_module.exor((int)msg.charAt(pos)-48,1))+msg.substring(pos+1);
                    msg=msg2;
                    pos++;
                }
                break;
        }
        f.WriteFile("./ass1/intermediate.txt",msg);
    }
    public static void main(String[] args) throws IOException
    {
        insert();
    }
}