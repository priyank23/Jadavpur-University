package ass3;

class stack
{
    private int[] st;
    private int tos;
    stack(int size)
    {
        st=new int[size];
        tos=-1;
    }
    void push(int c)
    {
        st[++tos]=c;
    }
    int pop()
    {
        return st[tos--];
    }
    boolean isEmpty()
    {
        return (tos==-1);
    }
    int peek()
    {
        return st[tos];
    }
}
