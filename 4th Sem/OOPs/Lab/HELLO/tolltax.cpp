#include<iostream>
#include<tuple>
#include <vector>
/*

std::tuple<int, int, int> tpl;

std::get<0>(tpl) = 1;
std::get<1>(tpl) = 2;
std::get<2>(tpl) = 3;

*/
using namespace std;
template <class T> class TOLLTAX;

template <class T> class TOLLTAX{
  vector<tuple<T,long,bool>> TollQueue;
public:
   void TakePrepaid()
  {
    T carnumber;
    cout<<"Enter the car number : ";
    cin>>carnumber;
    cout<<"Enter the number of wheels :";
    int wheel;
    cin>>wheel;
    long amount=wheel*100;

    tuple<T,long,bool> car;
    get<0>(car)=carnumber;
    get<1>(car)=amount;
    get<2>(car)=true;

    TollQueue.push_back(car);
  }
  void ReceiveToll()
  {
    T carnumber;
    cout<<"Enter the car number : ";
    cin>>carnumber;
    int dect=0;
    for(int i=0;i<TollQueue.size();i++)
    {
      if(carnumber==get<0>(TollQueue[i]) && get<2>(TollQueue[i])==true)
      {
        get<2>(TollQueue[i])=false;
        dect=1;
        cout<<"You have already done the prepaid. Happy Journey!"<<endl;

        break;
      }
    }
    if(dect==0){
    int wheel;
    cout<<"Enter the number of wheels : ";
    cin>>wheel;
    long amount=wheel*100;
    tuple<T,long,bool> car;
    get<0>(car)=carnumber;
    get<1>(car)=amount;
    get<2>(car)=false;
    cout<<"Toll Taken. Happy Journey :P"<<endl;

      TollQueue.push_back(car);
    }
  }
  void DisplayChart()
  {
    cout<<endl<<endl;
    long total=0;
    cout<<"CarNumber\tCarToll"<<endl;
    for(int i=0;i<TollQueue.size();i++)
    {
      cout<<get<0>(TollQueue[i])<<"\t"<<get<1>(TollQueue[i])<<"     "<<get<2>(TollQueue[i])<<endl;
      total=total+get<1>(TollQueue[i]);
    }
    cout<<endl<<"Total amount = "<<total<<endl;
  }

};
class MenuDrive{
public:
  static void Drive(){
    TOLLTAX<int> a;
    while (1) {
      cout<<"Press 1 to Take a prepaid"<<endl;
      cout<<"Press 2 to Receive a toll"<<endl;
      cout<<"Press 3 to display chart"<<endl;
      cout<<"Press 4 to exit"<<endl;
      int x;
      cin>>x;
      if(x==4)
      break;
      if(x==1)  a.TakePrepaid();
      if(x==2) a.ReceiveToll();
      if(x==3)   a.DisplayChart();
      /* code */
    }
  }
};
int main(){
  MenuDrive::Drive();
}
