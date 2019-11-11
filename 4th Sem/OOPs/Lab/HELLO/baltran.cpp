#include<iostream>
#include<string>
#include<vector>
using namespace std;
string SystemDate()
{
  time_t t = time(NULL);
  tm* timePtr = localtime(&t);
  string date=to_string(timePtr->tm_mday)+"/"+to_string(timePtr->tm_mon+1)+"/"+to_string(timePtr->tm_year+1900);
  return date;
}
class BALANCE;
vector<BALANCE> bal;
class TRANSACTION;
vector <TRANSACTION> tran;
class BALANCE{
  long accn_no;
  double balance;
  string last_date_of_updation;
public:
  double retbalance()
  {
    return balance;
  }
  static int SearchAccount(long number)
  {
    for(int i=0;i<bal.size();i++)
    {
      if(bal[i].accn_no==number)
      {
        return i;
        break;
      }
    }
    return -1;
  }
  static void CreateAccount()
  {
    BALANCE b;
    b.accn_no=bal.size();
    cout<<"Enter the first amount : "<<endl;
    cin>>b.balance;
    b.last_date_of_updation=SystemDate();
    bal.push_back(b);

  }
  static void ShowBalances()
  {
    if(bal.size()!=0){
    cout<<"Whole Bank Balance Summery"<<endl;
    cout<<endl;
    cout<<"account number"<<"\t"<<"last_date_of_updation"<<"\t"<<"balance"<<endl;
    for(int i=0;i<bal.size();i++)
    {
      cout<<bal[i].accn_no<<"\t"<<bal[i].last_date_of_updation<<"\t"<<bal[i].balance<<endl;
    }
  }
  }
friend class TRANSACTION;
};
class TRANSACTION{
  long t_no;
  string t_date;
  double t_amount;
  string t_type;
public:
  static void transact()
  {
    cout<<"Enter the account number : "<<endl;
    long number;
    cin>>number;
    int index= (BALANCE::SearchAccount(number));
    if(index>=0)
    {
      cout<<"1. Credit"<<endl;
      cout<<"2. Debit"<<endl;
      int x;
      cin>>x;
      if(x==1)
      {
        cout<<"Enter the amount you want to credit"<<endl;
        double amount;
        cin>>amount;
        bal[index].balance=bal[index].balance+amount;
        bal[index].last_date_of_updation=SystemDate();
        TRANSACTION t;
        t.t_no=bal[index].accn_no;
        t.t_amount=amount;
        t.t_date=SystemDate();
        t.t_type="Credit";
        tran.push_back(t);
        cout<<"TRANSACTION successfully done. Amount "<<amount<<" is successfully Credited to your "<<t.t_amount<<" bank account"<<endl;

      }
      if(x==2)
      {
        cout<<"Enter the amount you want to debit"<<endl;
        double amount;
        cin>>amount;
        if(amount<=bal[index].balance){
        bal[index].balance=bal[index].balance-amount;
        bal[index].last_date_of_updation=SystemDate();
        TRANSACTION t;
        t.t_no=bal[index].accn_no;
        t.t_amount=amount;
        t.t_date=SystemDate();
        t.t_type="Debit";
        tran.push_back(t);
          cout<<"TRANSACTION successfully done. Amount "<<amount<<" is successfully Dedited from your "<<t.t_amount<<" bank account"<<endl;
      }
        else
        cout<<"TRANSACTION cannot be done due to insufficient BALANCE :"<<endl;
      }
    }
    else
    {
      cout<<"TRANSACTION unsuccessful due to invalid Accnt Number"<<endl;
    }
  }
  static void ShowTransaction()
  {
    if(tran.size()!=0){
    cout<<"Whole Bank Transaction Summery"<<endl;
    cout<<endl;
    cout<<"accn_no"<<"\t"<<"amount of transact"<<"\t"<<"date of tran"<<"\t"<<"type_of_tran"<<"\t"<<endl;
    for(int i=0;i<tran.size();i++)
    cout<<tran[i].t_no<<"\t"<<tran[i].t_amount<<"\t"<<tran[i].t_date<<"\t"<<tran[i].t_type<<"\t"<<endl;
  }
  }
};
class MenuDrive{
public:
  static void Drive(){
    while(1){
    cout<<endl<<endl;
    cout<<"1. Enter 1 to create an account ."<<endl;
    cout<<"2. Enter 2 to do a Transaction ."<<endl;
    cout<<"3. Enter 3 to Display Bank BALANCE details of all customers."<<endl;
    cout<<"4. Enter 4 to Display all TRANSACTION done by bank"<<endl;
    cout<<"5. Enter 5 to exit"<<endl<<endl;;
    int x;
    cin>>x;
    if(x==1)
    {
      BALANCE::CreateAccount();
    }
    else if(x==2)
    {
      TRANSACTION::transact();
    }
    else if(x==3)
    {
      BALANCE::ShowBalances();
    }
    else if(x==4){
      TRANSACTION::ShowTransaction();
    }
    else if(x==5){
      break;
    }
    else{

    }


  }
  }
};

int main()
{
  MenuDrive::Drive();
}
