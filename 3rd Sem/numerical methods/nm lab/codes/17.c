/*Program to implement forward interpolation technique*/
#include<stdio.h>
#include<math.h>

int fact(int n)    //function to find the factorial of n
{
	int f=1,i;
	for(i=2;i<=n;i++)
		f*=i;
	return f;	
}
int main(void)     //main begins
{
	FILE *fp;
	fp=fopen("17.txt","w");   //file opened to print the data in it
	int n=4,i,j;
	printf("Enter the values of the function as x,f(x)\n");  //inputs taken
	float x[4];
	float y[4][4];
	for(i=0;i<4;i++)
		scanf("%f%f",&x[i],&y[i][0]);
	for(i=1;i<n;i++)      //difference table created
		for(j=0;j<n-i;j++)
			y[j][i]=y[j+1][i-1]-y[j][i-1];
	fprintf(fp,"    x\t\t   f(x)\t\t  df(x)\t\td1f(x)  \td2f(x)\n");
	for(i=0;i<n;i++)     //difference table printed
	{
		fprintf(fp,"%f\t",x[i]);
		for(j=0;j<n-i;j++)
			fprintf(fp,"%f\t",y[i][j]);
		fprintf(fp,"\n");	
	}
	float val;     //interpolated value taken from the user
	printf("Enter the value to interpolat at:(between %f and %f)\n",x[0],x[3]);
	scanf("%f",&val);
	float sum=y[0][0];
	float u=(val-x[0])/(x[1]-x[0]);   //height is found
	for(i=1;i<n;i++)
	{
		sum+=(u*y[0][i])/fact(i);    //formula of the technique implemented here
		u*=(u-1);
	}
	printf("Value at %f is %f\n",val,sum);   //final result printed in the terminal and the file
	fprintf(fp,"\n\n\nf(%f)=%f\n",val,sum);
}
