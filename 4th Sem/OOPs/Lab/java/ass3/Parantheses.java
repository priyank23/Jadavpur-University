package ass3;
import java.io.*;
class parantheses
{ 
    public static void main(String[] args) throws IOException
    {
        String s;
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        s=br.readLine();
        stack st=new stack(s.length());
        st.push(s.charAt(0));
        for(int i=1;i<s.length();i++)
        {
            if(st.isEmpty())
            {
                st.push(s.charAt(i));
                i++;
            }
            int c=st.peek();
            if(c=='(' && s.charAt(i)==')')
            {
                st.pop();
            }
            else if(c==(s.charAt(i)-2))
            {
                st.pop();
            }
            else
            {
                st.push(s.charAt(i));
            }
        }
        /*while(!st.isEmpty())
        {
            System.out.print(st.pop());
        }*/
        System.out.println("\n"+st.isEmpty());
    }
}
