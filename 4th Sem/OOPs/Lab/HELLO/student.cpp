#include<iostream>
#include<vector>
#include <sstream>  // for string streams
#include <string>
#include <algorithm>
using namespace std;
class STUDENT;
std::vector<STUDENT> stud;

class STUDENT{
  string roll;
  string name;
  string course;
  string admission_date;

  int marks_1;
  int marks_2;
  int marks_3;
  int marks_4;
  int marks_5;
  long total;
public:
  bool operator <(const STUDENT &other) const{
    return total<other.total;
  }
  string retRoll()
  {
    return roll;
  }
  void getRoll()
  {
    cout<<"Enter the roll number :"<<endl;
    cin>>roll;
  }
  void getName(){

    cout<<"Enter the name : ";
    cin.ignore();
    getline(cin,name);
  }
  void getCourse(){

    cout<<"Enter the course :";
    cin>>course;
  }
  void getAdmission_date(){

    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    /*
    int tm_mday;
int tm_mon;
int tm_year;*/
    admission_date=to_string(timePtr->tm_mday)+"/"+to_string(timePtr->tm_mon+1)+"/"+to_string(timePtr->tm_year+1900);
  }
  void getMarks1()
  {
    cout<<"Enter the marks in first subject :";
    cin>>marks_1;
  }
  void getMarks2()
  {
    cout<<"Enter the marks in second subject :";
    cin>>marks_2;
  }
  void getMarks3()
  {
    cout<<"Enter the marks in third subject :";
    cin>>marks_3;
  }
  void getMarks4()
  {
    cout<<"Enter the marks in fourth subject :";
    cin>>marks_4;
  }
  void getMarks5()
  {
    cout<<"Enter the marks in fifth subject :";
    cin>>marks_5;
  }
  void calcTotal()
  {
    total=marks_1+marks_2+marks_3+marks_4+marks_5;
  }
  static void StartAdmission(){
    cout<<"Enter the number of students you want to admit!"<<endl;
    int g;
    cin>>g;
    STUDENT s;
    while(g--){
        s.getCourse();
        int cnt=0;
        for(int i=0;i<stud.size();i++)
        {
          if(stud[i].course==s.course)
          cnt++;
        }
        ostringstream str1;

        cnt++;
        str1<<cnt;
        s.roll=s.course+str1.str();
        s.getName();
        s.getAdmission_date();
        stud.push_back(s);
        cout<<endl<<endl<<"Admission successfully done! "<<endl;
        int vec_size=stud.size()-1;
        cout<<stud[vec_size].roll<<"\t"<<stud[vec_size].name<<"\t"<<stud[vec_size].course<<"\t"<<stud[vec_size].admission_date<<endl<<endl;

}


  }
  static void generateSheet(){
    cout<<"Enter the number of students you want to generate marksheet !"<<endl;
    int g;
    cin>>g;
    STUDENT s;
    while(g--){
      int flag=0;
      s.getRoll();
      for(int i=0;i<stud.size();i++)
      {
        if(stud[i].roll==s.roll)
        {
          flag=1;
          stud[i].getMarks1();
          stud[i].getMarks2();
          stud[i].getMarks3();
          stud[i].getMarks4();
          stud[i].getMarks5();
          stud[i].calcTotal();
        }
      }
      if(flag==1){

      }
      else{
        cout<<"Student doesnot exists :(";

      }

    }
  }
   void displayMyResult(){
    cout<<"Roll Number : "<<roll<<endl;
    cout<<"Name : "<<name<<endl;
    cout<<"Course : "<<course<<endl;
    cout<<"Admission Date : "<<admission_date<<endl;
    cout<<"subject 1: "<<marks_1<<endl;
    cout<<"subject 2: "<<marks_2<<endl;
    cout<<"subject 3: "<<marks_3<<endl;
    cout<<"subject 4: "<<marks_4<<endl;
    cout<<"subject 5: "<<marks_5<<endl;
    cout<<endl<<endl<<"Total: ====>>"<<total<<endl<<endl;
  }
  static void displaySheet(){
    cout<<"Enter the number of students you want to display marksheet !"<<endl;
    int g;
    cin>>g;
    STUDENT s;
    while(g--){
      int flag=0;
      s.getRoll();
      for(int i=0;i<stud.size();i++)
      {
        if(stud[i].roll==s.roll)
        {
          flag=1;
          stud[i].displayMyResult();
        }
      }
      if(flag==1){
      }
      else{
        cout<<"Student doesnot exists :(";

      }

    }
  }
  static void deptTopper(){
      cout<<"Enter the Department :";
      string myDept;
      cin>>myDept;
      int max_index=0;
    long  max=0;
     int chck=0;
      for(int i=0;i<stud.size();i++)
      {
        if(stud[i].total>max && stud[i].course==myDept)
        {
          max=stud[i].total;
          max_index=i;
          chck=1;
        }
      }
      if(chck==1){
      cout<<endl<<stud[max_index].name<<" is the "<<myDept<<" Departmental Topper _/\\_ "<<endl<<endl;
      stud[max_index].displayMyResult();
    }
    else
    cout<<"Department doesnot exists in this University"<<endl;
  }
  static void univTopper(){
  int  max_index=0;
  long  max=0;
    for(int i=0;i<stud.size();i++)
    {
      if(stud[i].total>max)
      {
        max=stud[i].total;
        max_index=i;
      }
    }
    cout<<endl<<stud[max_index].name<<" is the University Topper _/\\_"<<endl<<endl;
    stud[max_index].displayMyResult();

  }
  static void DepartmentMeritList(){
    vector<STUDENT> StudentOfMyDept;
    cout<<"Enter the Department :";
    string myDept;
    cin>>myDept;
    int chck=0;
    for(int i=0;i<stud.size();i++)
    {
      if(stud[i].course==myDept)
      {
        chck=1;
        StudentOfMyDept.push_back(stud[i]);
      }

    }
    sort(StudentOfMyDept.begin(),StudentOfMyDept.end());
    if(chck==1)
    {
      cout<<"Department ==>  "<<myDept<<endl;
      cout<<"Roll\tName\tTotal"<<endl;
    }
    for(int i=StudentOfMyDept.size()-1;i>=0;i--)
    {

        cout<<StudentOfMyDept[i].roll<<"\t"<<StudentOfMyDept[i].name<<"\t"<<StudentOfMyDept[i].total<<endl;

    }
    if(chck==0)
    {
      cout<<"Department doesnot exists in this University"<<endl;return;
    }
    //for(int i)

  }
  static void UniversityMeritList(){
    vector<STUDENT> StudentOfMyUniv;
    for(int i=0;i<stud.size();i++)
    {
        StudentOfMyUniv.push_back(stud[i]);
    }
    sort(StudentOfMyUniv.begin(),StudentOfMyUniv.end());

      cout<<"<== University MeritList ==>  "<<endl;
      cout<<"Roll\tName\tTotal"<<endl;

    for(int i=StudentOfMyUniv.size()-1;i>=0;i--)
    {

        cout<<StudentOfMyUniv[i].roll<<"\t"<<StudentOfMyUniv[i].name<<"\t"<<StudentOfMyUniv[i].total<<endl;
    }
  }

};
class MenuDrive{
public:
  static int Drive(){
    int dect=0;
    cout<<endl<<endl;
  cout<<"1. Press 1 to start Admission"<<endl;
  cout<<"2. Press 2 to generate MarksSheet"<<endl;
  cout<<"3. Press 3 to display MarksSheet"<<endl;

  cout<<"4. Press 4 to find Dept Topper"<<endl;
  cout<<"5. Press 5 to find University Topper"<<endl;
  cout<<"6. Press 6 to find Departmental MeritList"<<endl;
  cout<<"7. Press 7 to find University MeritList"<<endl;
  cout<<"8. Press 8 to exit"<<endl;
  cout<<endl<<endl;
  int x;
  cin>>x;
  if(x==1){
    STUDENT::StartAdmission();
  }
  if(x==2){
    STUDENT::generateSheet();
  }
  if(x==3){
    STUDENT::displaySheet();
  }
  if(x==4){
    STUDENT::deptTopper();
  }
  if(x==5){
    STUDENT::univTopper();
  }
  if(x==6){
    STUDENT::DepartmentMeritList();
  }
  if(x==7){
    STUDENT::UniversityMeritList();
  }
  if(x==8){
    dect=1;
  }
  else
  {

  }
  return dect;
}


};

int main(){
  while(1)
  if(MenuDrive :: Drive()) break;
}
