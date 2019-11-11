/*Program to implement backward interpolation technique*/
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
	fp=fopen("16.txt","w");   //file opened to print the data in it
	printf("Enter the number of inputs.\n");
	int n,i,j;
	scanf("%d",&n);
	printf("Enter the values of the function as x,f(x)\n");  //inputs taken
	float x[n];
	float y[n][n];
	for(i=0;i<n;i++)
		scanf("%f%f",&x[i],&y[i][0]);
	for(i=1;i<n;i++)      //difference table created
		for(j=n-1;j>=i;j--)
			y[j][i]=y[j][i-1]-y[j-1][i-1];
	fprintf(fp,"    x\t\t       Difference table.\n");
	for(i=0;i<n;i++)     //difference table printed
	{
		fprintf(fp,"%f\t",x[i]);
		for(j=0;j<=i;j++)
			fprintf(fp,"%f\t",y[i][j]);
		fprintf(fp,"\n");	
	}
	float val;     //interpolated value taken from the user
	printf("Enter the value to interpolat at:(between %f and %f)\n",x[0],x[n-1]);
	scanf("%f",&val);
	float sum=y[n-1][0];
	float u=(val-x[n-1])/(x[1]-x[0]);   //height is found
	float temp=u;
	for(i=1;i<n;i++)
	{  
		sum+=((u*y[n-1][i])/fact(i));    //formula of the technique implemented here
		u*=(temp+i);
	}
	printf("Value at %f is %f\n",val,sum);   //final result printed in the terminal and the file
	fprintf(fp,"\n\n\nf(%f)=%f\n",val,sum);
}
