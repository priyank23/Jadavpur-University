package oops.java2.ass2;

import oops.java.ass1;
import java.io.*;

class LinkedListString
{
    linked_list<String> l=new linked_list<String>();
    void insert() throws IOException
    {
        System.out.println("1. Insert_front.\n2. Insert_rear.\n\nEnter your choice.");
        BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
        int ch=Integer.parseInt(bf.readLine());
        System.out.println("Enter the String.");
        String s=bf.readLine();
        if(ch==1)
        {
            l.insert_front(s);
        }
        else if(ch==2)
        {
            l.insert_rear(s);
        }
        l.display();
    }
    void delete_front()
    {
        l.del_front();
        l.display();
    }
}
class LinkedListMain
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
        LinkedListString l=new LinkedListString();
        int x=1;
        while(x==1)
        {
            System.out.println("Creating List of String...");
            l.insert();
            System.out.println("Enter 1 to continue.");
            x=Integer.parseInt(bf.readLine());
        }
        l.delete_front();
    }
}