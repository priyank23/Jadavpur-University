package ass4;

class WalshCode
{
    int num_of_stations;
    int wc[][];
    WalshCode(int n)
    {
        int a=1;
        while(n>a) a*=2;
        num_of_stations=a;
        generate();
        print();
    }
    void generate()
    {
        wc = new int[num_of_stations][num_of_stations];
        wc[0][0]=1;
        int prev=1,next=2;
        while(next<=num_of_stations)
        {
            for(int i=prev;i<next;i++)
                for(int j=0;j<prev;j++) wc[i][j]=wc[i-prev][j];
            
            for(int i=0;i<prev;i++)
                for(int j=prev;j<next;j++)  wc[i][j]=wc[i][j-prev];
            
            for(int i=prev;i<next;i++)
                for(int j=prev;j<next;j++)  wc[i][j]=(-1)*wc[i-prev][j-prev];
            prev=next;
            next*=2;
        }
    }
    void print()
    {
        System.out.println("The Walsh Code"+Integer.toString(num_of_stations)+" being used:");
        for(int i=0;i<num_of_stations;i++){
            for(int j=0;j<num_of_stations;j++) System.out.print(wc[i][j]);
            System.out.println();}
    }
}