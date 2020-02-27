package ass1;
import java.io.*;
import java.util.*;
public class files 
{
    public String readFile(String filename) throws IOException
    {
        File f=new File(filename);
        Scanner s=new Scanner(f);
        String str=s.nextLine();
        return str;
    }
    public void writeFile(String filename,String output) throws IOException
    {
        // System.out.println(output);
        FileWriter fw=new FileWriter(filename,false);
        PrintWriter outf=new PrintWriter(fw);
        outf.println(output);
        outf.close();
    }
}