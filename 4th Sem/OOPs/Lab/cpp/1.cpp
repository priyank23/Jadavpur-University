#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
class time1{
private:
	int hour,min,sec;
	string s,aps;

public:
	int format24=1,flag=0;
	time1(){
		hour=0;
		min=0;
		sec=0;
		s='\0';
		aps='\0';
		}
	void input(){
		cout<<"Enter the time in (hh:mm:ss) format.\n";
		cin>>s;
		for(int i=0;i!=s.length();i++){
			if(s[i]=='a' || s[i]=='p'){
				format24=0;
				aps=s.substr(i,i+1);
				break;
				}
			if(flag==0 && s[i]!=':')
			{
				hour=pow(10,i)*hour+(s[i]-48);
			}
			if(flag==1 && s[i]!=':')
			{
				min=pow(10,i-3)*min+(s[i]-48);
			}
			if(flag==2 )
			{
				sec=pow(10,i-6)*sec+(s[i]-48);
			}
			if(s[i] == ':') flag++;	
			}
			if(aps=="am" && hour==12) hour=0;
			if(format24=1 && hour==24) hour =0; 
		if(hour<0 ||hour>=24||min<0||min>=60||sec<0||sec>=60) cout<<"Wrong Input!!!\n Chii yarr!! Time dekna to seekh le...\n";
	}
	void display_time(){
		if(format24==1) cout<<"Time: "<<hour<<":"<<min<<":"<<sec<<endl;
		else cout<<"Time: "<<hour<<":"<<min<<":"<<sec<<" "<<aps<<endl;
	}
	void add_time(){
		int min_add=0;
		cout<<"\nEnter minutes to be added";
		cin>>min_add;
		min_add%=1440;
		min+=min_add;
		if(min>60){
			hour+=min/60;
			hour%=24;
			min=min%60;
			}
		if(format24==1 && hour>=12){
			hour-=12;
			if(aps[0]=='a'){ aps[0]='p';if(hour==0) hour=12;}
			if(aps[0]=='p') aps[0]='a';
			}
		display_time();
	}
};
int main()
{
	time1 t;
	t.input();
	t.display_time();
	t.add_time();
	return 0;
}
