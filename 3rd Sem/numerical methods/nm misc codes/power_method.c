//finding eigenvalue using power method
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void eigen_power()
{
	FILE *fp;
	fp=fopen("power_method_res.txt","w");
	int n,i,j;
	printf("Enter the size of A:");    //declare the size of matrix

	scanf("%d",&n);
	int A[n+1][n+1];
	float Xf[n+1],Xl[n+1];
	printf("Enter the elemnts of A row wise:\n");
	fprintf(fp,"Matrix Taken:\n\n");
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&A[i][j]); //giving input for the matrix A
			fprintf(fp,"%d\t",A[i][j]);
		}
		fprintf(fp,"\n");
	}
	

	for(i=1;i<=n;i++){  
		Xf[i] = 1;  //input giving for matrix Xf and Xl 
		Xl[i] = 0;		
	}

	float max = 0,c0 = 0,c1= 0;
	float err=1000;
	fprintf(fp,"X1[0]\t\tX1[1]\t\tX1[2]\t\t   c\t\terror_max\n");
	while(1)
	{
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				Xl[i] = Xl[i] + A[i][j]*Xf[j];  //matrix multiplication
			}
		}

		for(i=1;i<=n;i++)
		{
			if(max<Xl[i]){
				max = Xl[i]; //update the max value
			}
		}

		c1 = max;
		max = 0;
		
		
		for(i=1;i<=n;i++)
		{
			Xl[i] = Xl[i]/c1;   //divide each term of the by the max term(c1) 
		}

		err = fabs(fabs(Xl[1])-fabs(Xf[1]));
		for(i=1;i<=n;i++)
		{
			if(fabs(fabs(Xl[i])-fabs(Xf[i]))>err) err=fabs(fabs(Xl[i])-fabs(Xf[i]));
		}
		for(i=1;i<=n;i++)
		{
			Xf[i] = Xl[i];    // updating value
		}

		//err = fabs(c1-c0); //absolute error

		c0 = c1;
		fprintf(fp,"%f\t%f\t%f\t%f\t%f\n",Xl[1],Xl[2],Xl[3],c1,err);
		
		
		for(i=1;i<=n;i++)
		{
			Xl[i] =0;
		}
		if(err<0.00005)  //checking the breaking condition
			break;

          }
	fprintf(fp,"\n\nThe maximum eigen value is %9.6f\n\nThe corresponding eigen vector is\n%9.6f\n%9.6f\n%9.6f\n",c1,Xf[1],Xf[2],Xf[3]);
	fclose(fp);
        printf("\nthe final result is: ");
	printf("%f\n",c1); //final result

}
int main()
{
	eigen_power(); //calling the function inside main  
}

