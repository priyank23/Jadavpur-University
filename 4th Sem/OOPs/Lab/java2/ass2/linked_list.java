package oops.java2.ass2;

class node<X>
{
    X data;
    node<X> next=null;
}
public class linked_list<X>
{
    node<X> n;
    void insert_front(X data)
    {
        if(n==null)
        {
            n=new node<X>();
            n.data=data;
            n.next=null;
            return;
        }
        node<X> temp = new node<X>();
        temp.data=data;
        temp.next=n;
        n=temp; 
    }
    void del_front()
    {
        if(n==null)
        {
            System.out.println("Underflow!");
            return;
        }
        node<X>temp=n;
        n = n.next;
        temp.next=null;
        temp=null;
        System.gc();
    }
    void insert_rear(X data)
    {
        node<X> temp=n;
        while(temp.next!=null)
        {
            temp=temp.next;
        }
        node<X> temp2=new node<X>();
        temp2.data=data;
        temp.next=temp2;
        temp2.next=null;
    }
    void display()
    {
        node<X> temp=n;
        while(temp!=null)
        {
            System.out.println(temp.data);
            temp=temp.next;
        }
    }
}
