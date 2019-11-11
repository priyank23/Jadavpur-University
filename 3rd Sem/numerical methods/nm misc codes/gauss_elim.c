/*Program to find the solution of linear equations using gauss elimination method*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void Gauss_Elimination();   //function prototype
int main(void)
{
	Gauss_Elimination();  //calling function inside main function
}
void Gauss_Elimination()
{ 	int n,i,j,k,p;    //variable decleration
	FILE *fp;
	fp=fopen("5.txt","w");
	fprintf(fp,"   GAUSSIAN ELIMINATION FOR SOLVING LINEAR EQUATIONS.\n\n");
	printf("Enter number of variables:");
	scanf("%d",&n);                       //size of matrix
	float a[n+1][n+2],m[n][n+2],sum,big,temp,x[n+1];     //variable decleration
	big=0;
	for(i=1;i<=n;i++){
		x[i] = 0;
	}
	fprintf(fp,"Augmented matrix formed is:\n");
	printf("Enter the augmented matrix.\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n+1;j++){
			scanf("%f",&a[i][j]);     //value giving for matrix 
			fprintf(fp,"%f",&a[i][j]);
			fprintf(fp,"\n");
		}
	}
	for(k=1;k<n;k++)
	{
		big = 0;
		for(i=k;i<n;i++)                //partial pivoting
		{
			if(fabs(a[i][k])>big)
			{
				big = fabs(a[i][k]);
				p = i;
			}
		}
		for(j=k;j<=n+1;j++)        //swapping values
		{
			temp = a[k][j];
			a[k][j] = a[p][j];
			a[p][j] = temp;
		}
		for(i = k+1;i<=n;i++)
		{   //gauss elimination
			m[i][k] = a[i][k] / a[k][k];
			for(j=k;j<=n+1;j++)
			{
				a[i][j] = a[i][j] - m[i][k]*a[k][j];
			}
		}
	}
	for(i =n;i>=1;i--)
	{
		sum = 0;
		for(j = n;j>=i;j--)                     //back substitution
		{
			sum = sum + a[i][j]*x[j];
		}
		x[i] = (a[i][n+1] -sum)/a[i][i];        //solving and finding values
	}
	for(i = 1;i<=n;i++)
	{
		printf("x%d = %f",i,x[i]);   //print the result  
		fprintf(fp,"x%d = %f",i,x[i]);
		printf("\n");
		fprintf(fp,"\n");
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n+1;j++){
			printf("%f ",a[i][j]);    //print the upper tringualr matrix after gauss elimination
			fprintf(fp,"%f ",a[i][j]);
		}
		printf("\n");
		fprintf(fp,"\n");
	}
	fclose(fp);
}
