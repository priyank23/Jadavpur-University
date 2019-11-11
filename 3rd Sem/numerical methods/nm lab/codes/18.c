/*Program for applying newton forward difference formula for differentiation*/
#include<stdio.h>
#include<math.h>
int fact(int n)    //function to find the factorial of n
{
	int f=1,i;
	for(i=2;i<=n;i++)
		f*=i;
	return f;	
}
int main()
{
	FILE *fp;      //file pointer declared
	fp=fopen("18.txt","w");   
	int n,i,j;
	printf("Enter the number of terms.\n");
	scanf("%d",&n);
	float x[n],y[n][n];    //variables declared
	for(i=0;i<n;i++)       //inputs taken from the user
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
	float sum=0;
	for(i=0;i<n-1;i++)    //formula for the method
		sum+=pow(-1,i)*y[0][i+1]/fact(i+1);
	sum/=(x[1]-x[0]);        //printing the final result
	printf("The f'(%f) = %f\n",x[0],sum);
	fprintf(fp,"\n\n\tThus, f'(%f) = %f\n",x[0],sum);
	fclose(fp);    //file pointer closed	
}
