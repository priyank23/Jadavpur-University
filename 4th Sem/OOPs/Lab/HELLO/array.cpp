#include<iostream>
#include<math.h>
using namespace std;
class ARRAY{
  int arraysize;
  int *p;

  public:



    ARRAY(int n )
    {
      arraysize=n;
      p= (int *)malloc(arraysize * sizeof(int));
      for(int i=0;i<arraysize;i++)
      p[i]=0;
    }
    ARRAY (const ARRAY &object)
    {
      arraysize=object.arraysize;
      p= (int *)malloc(arraysize * sizeof(int));
      for(int i=0;i<arraysize;i++)
      p[i]=object.p[i];

    }
    ARRAY(int *arr, int n)
      {
        arraysize=n;
        p= (int *)malloc(arraysize * sizeof(int));
        for(int i=0;i<arraysize;i++)
        p[i]=arr[i];
      }
    void displayArray(){
      for(int i=0;i<arraysize;i++)
      cout<<p[i]<<" ";
      cout<<endl;
    }
    void insertItem(){
      cout<<"Insert "<<arraysize<<" numbers"<<endl;
      for(int i=0;i<arraysize;i++)
      {
        cin>>p[i];
      }

    }

    ARRAY operator +(const ARRAY &obj)
    {
      ARRAY add(max(obj.arraysize,arraysize));


      int traverselimit=min(obj.arraysize,arraysize);
      for(int i=0;i<traverselimit;i++)
      {
        add.p[i]=p[i]+obj.p[i];
      }
      if(arraysize>obj.arraysize)
      {
        for(int i=traverselimit;i<max(obj.arraysize,arraysize);i++)
        add.p[i]=p[i];
      }
      else
      {
        for(int i=traverselimit;i<max(obj.arraysize,arraysize);i++)
        add.p[i]=obj.p[i];
      }
      return add;
    }

    ARRAY operator -(const ARRAY &obj)
    {
      ARRAY sub(max(obj.arraysize,arraysize));

      int traverselimit=min(obj.arraysize,arraysize);
      for(int i=0;i<traverselimit;i++)
      {
        sub.p[i]=p[i]-obj.p[i];
      }
      if(arraysize>obj.arraysize)
      {
        for(int i=traverselimit;i<max(obj.arraysize,arraysize);i++)
        sub.p[i]=p[i];
      }
      else
      {
        for(int i=traverselimit;i<max(obj.arraysize,arraysize);i++)
        sub.p[i]=-obj.p[i];
      }
      return sub;
    }
    int operator [](int index)
    {
      if(index>=arraysize)
      {
        cout<<"Error! Invalid Index"<<endl;
      }
      else
      {
        return p[index];
      }
    }
    ARRAY operator *(int val)
    {
      ARRAY mult(arraysize);
      for(int i=0;i<arraysize;i++)
      mult.p[i]=p[i]*val;
      return mult;
    }
    friend ARRAY operator *(int val, ARRAY arr);

};
 ARRAY operator *(int val, ARRAY arr)
 {
   return arr*val;
 }
int main(){


  ARRAY a(5);
  a.displayArray();
  cout<<endl<<"First ARRAY 'a' has been initiated with all zero \n Now time to insert in 'a'"<<endl;
  a.insertItem();
    cout<<endl<<"Now the ARRAY 'a' is : "<<endl;
  a.displayArray();

  cout<<endl<<"ARRAY'dj' is copy-constructed from 'a'"<<endl;
  ARRAY dj(a);
  dj.displayArray();


  int arr[7];
  cout<<"Enter the values in C language array of size "<<7<<" :"<<endl;
  for(int i=0;i<7;i++)
  cin>>arr[i];
    cout<<endl<<"Now forming the ARRAY 'b' from whatever you gave in a real array"<<endl;
  ARRAY b(arr,7);
  b.displayArray();
  ARRAY add=a+b;
  add.displayArray();
  ARRAY sub=a-b;
  sub.displayArray();
  cout<<endl<<sub[3]<<endl<<endl;
  ARRAY mult=a*5;
  mult.displayArray();
  ARRAY mult2=5*b;
    mult2.displayArray();




}
