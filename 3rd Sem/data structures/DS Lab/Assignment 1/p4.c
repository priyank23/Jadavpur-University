/*Program to print 60000 distint random numbers in a file*/
#include<stdio.h>
#include<time.h>
#define Int unsigned int
#define size 60000

int main(void)                                                   //main begins here
{
	Int num,i;                                         
	FILE *fp;                                                    //file pointer declared 
	srand(time(0));                                              //rand() function seeded with time(0) to prodece different random numbers
	fp=fopen("p4.txt","w");                                      //p4.txt is opened in write mode 
	fprintf(fp,"The random numbers generated are as follows:\n");
	for(i=0;i<size;i++)                                          //random numbers are calculated and printed in the file in this loop
	{
		num=(rand()%size)+1;     
		fprintf(fp,"%u\n",num);
	}
	fclose(fp);                                                  //file pointer closed 
}
