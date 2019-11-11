/*Program to sort names of students alphabetically and print the largest and smallest names*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE* fin;
	fin=fopen("p5_input.txt","r");
	int n=15,j=0,x[n],i;
	char name[n][20],dummy1[20],dummy2[20],temp[20];
	fscanf(fin,"%s\t%s\n",&dummy1,&dummy2);
	
	for(i=0;i<n;i++)								//input taken from file p5_input.txt
	{
		fscanf(fin,"%d\t%s\n",&x[i],&name[i]);
	}
	
	for(i=0;i<n-1;i++)								//sorting done here
	{
		for(j=i+1;j<n;j++)
		{
			if(strcmp(name[i],name[j])>0)
			{
				int temp2=x[i];
				x[i]=x[j];
				x[j]=temp2;
				strcpy(temp,name[i]);
				strcpy(name[i],name[j]);
				strcpy(name[j],temp);
			}
		}
	}
	
	int min=strlen(name[0]),mini=999,max=strlen(name[0]),maxi=-1;
	
	for(i=0;i<n;i++)								//finding smallest name
	{
		if(strlen(name[i])<min)
		{
			min=strlen(name[i]);
			mini=i;
		}
	}
	
	for(i=0;i<n;i++)								//finding largest name			
	{
		if(strlen(name[i])>max)
		{
			max=strlen(name[i]);
			maxi=i;
		}
	}
	
	printf("Max and min length characters are %s and %s with lengths %d and %d respectively.\n",name[maxi],name[mini],max,min);
	fclose(fin);
	FILE* fout=fopen("p5_output.txt","w");			//printing result in the file p5_output.txt
	fprintf(fout,"RollNo\tName\n");
	for(i=0;i<n;i++)
		fprintf(fout,"%d\t%s\n",x[i],name[i]);
		
	fclose(fout);
	return 0;
	
}
