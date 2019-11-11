#include<iostream>
#include<string>
#include<math.h>
using namespace std;
class STRING{
  char *c;
  int stringlength;
public:
  STRING ()
  {
    stringlength=0;
    //*c=NULL;
  }
  STRING( const STRING &object)
  {
    stringlength=object.stringlength;
    c=(char*)malloc((stringlength+1)*sizeof(char));
    for(int i=0;i<=stringlength;i++)
    c[i]=object.c[i];
  }
  STRING (string s)
  {
    stringlength=s.length();
    c=(char*)malloc((stringlength+1)*sizeof(char));
    for(int i=0;i<stringlength;i++)
    c[i]=s[i];
    c[stringlength]='\0';

  }
  STRING operator+(STRING str)
  {
    STRING s;
    s.stringlength=stringlength+str.stringlength;
    s.c=(char*)malloc((s.stringlength+1)*sizeof(char));
    for(int i=0;i<stringlength;i++)
    s.c[i]=c[i];
    for(int i=stringlength;i<s.stringlength;i++)
    s.c[i]=str.c[i-stringlength];
    return s;
  }

  char operator [](int index)
  {
    if(index>=stringlength)
    {
      cout<<"Error! Invalid Index"<<endl;
    }
    else
    {
      return c[index];
    }
  }
  int retlength()
  {
    return stringlength;
  }
  friend istream & operator >> (istream &in,  STRING &obj);
  friend ostream & operator << (ostream &out,  STRING obj);
  friend bool operator >(STRING str1,STRING str2);
  friend bool operator <(STRING str1,STRING str2);

};
istream & operator >> (istream &in,  STRING &obj)
{
  string s;
  cin>>s;
  STRING mystring(s);
  obj=mystring;
  return in;
}
ostream & operator << (ostream &out,  STRING obj)
{
  for(int i=0;i<obj.stringlength;i++)
  cout<<obj.c[i];
  return out;
}
bool operator <(STRING str1,STRING str2)
{
  for(int i=0;i<min(str1.stringlength,str2.stringlength);i++)
  {
    if (str1.c[i]<str2.c[i])
     {
       return true;
     }
     if (str1.c[i]>str2.c[i])
      {
        return false;
      }
  }
  if(str1.stringlength>=str2.stringlength) return false;
  if(str1.stringlength<str2.stringlength) return true;
}
bool operator >(STRING str1,STRING str2)
{
  for(int i=0;i<min(str1.stringlength,str2.stringlength);i++)
  {
    if (str1.c[i]>str2.c[i])
     {
       return true;
     }
     if (str1.c[i]<str2.c[i])
      {
        return false;
      }
  }
  if(str1.stringlength>str2.stringlength) return true;
  if(str1.stringlength<=str2.stringlength) return false;
}

int main()
{
  STRING a;
  STRING b("abcde");
  STRING c=b;
  cin>>a;
  cout<<a<<endl;
  cout<<b<<endl;
  cout<<c<<endl;
if(a>c) cout<<"a>c"<<endl;
if(a<c) cout<<"a<c"<<endl;
for(int i=0;i<a.retlength();i++)
cout<<a[i];
cout<<endl;


}
