#include<bits/stdc++.h>

using namespace std;

string search(string dict[5][15],string token,int len[5])
{
    int ans=-1;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<len[i];j++)
        {
            if(dict[i][j]==token){ ans=i; break;}
        }
    }
    if(ans==0) return "Noun";
    if(ans==1) return "verb";
    if(ans==2) return "pronoun";
    if(ans==3) return "adjective";
    if(ans==4) return "article";
    return "others";
}
int main()
{
    string dict[5][15];//noun,verb,pronoun,adjective,article;
    int len[5];
    ifstream fp;
    fp.open("./dict.txt",ios::in);
    if(fp.is_open())
    {
        for(int i=0;i<5;i++)
        {
            string temp;
            getline(fp,temp);
            int n=temp.length();
            char tmp[n+1];
            strcpy(tmp,temp.c_str());
            char *token=strtok(tmp," ");
            int j=0;
            token=strtok(NULL," ");
            while(token!=NULL)
            {
                dict[i][j++]=token;
                token=strtok(NULL," ");
            }
            len[i]=j;
        }
    }
    fp.close();

    cout<<"\n\033[1;4;33m\tParaNo.\tLineNo\tWordNo\tWord\t\tType\n\n\033[0m";
    cout<<"\033[34m";
    fp.open("para.txt",ios::in);
    if(fp.is_open())
    {
        string temp;
        int pno=0;
        while(getline(fp,temp))
        {
            pno++;
            int lno=1,wordno=1;
            int n=temp.length();
            char tmp[n+1];
            strcpy(tmp,temp.c_str());
            char* token=strtok(tmp,", ");
            while(token!=NULL)
            {
                string x(token);
                bool flag=false;
                if(x[x.length()-1]=='.')
                {
                    flag=true;
                    x[x.length()-1]='\0';
                    strcpy(token,x.c_str());
                }
                    cout<<'\t'<<pno<<'\t'<<lno<<'\t'<<wordno<<'\t'<<token;
                    string type=search(dict,token,len);
                    string tm=token;
                    if(tm.length()<8)
                    cout<<"\t\t"<<type<<endl;
                    else cout <<"\t"<<type<<endl;
                    wordno++;
                if(flag==true) lno++;
                token=strtok(NULL,", ");
            }
        }
    }
    cout<<"\033[0m";
    fp.close();
    return 0;
}