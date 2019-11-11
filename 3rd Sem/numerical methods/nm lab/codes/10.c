/*Program for implementing Jacobi's method*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(void)  //main begins here
{
	FILE *fp;
	fp=fopen("10.txt","w");
	fprintf(fp,"   JACOBI METHOD FOR SOLVING EQUATIONS.\n\n");
	int order,i,j,k;
	printf("Enter the number of variables\n");
	scanf("%d",&order);			//scans the number of variables
	float A[order][order+1],x[order],x_new[order],error,max;
	for(i=0;i<order;i++)		//seeding the initial result
	{
		x[i]=0;x_new[i]=0;
	}
	printf("Enter the augmented matrix\n");
	fprintf(fp,"The augmented matrix is:-\n");
	for(i=0;i<order;i++){		//augmented matrix is scanned from the user row-wise
		for(j=0;j<order+1;j++){
			scanf("%f",&A[i][j]);
			fprintf(fp,"%f\t",A[i][j]);
		}fprintf(fp,"\n");
	}
	do							//loop for implementing the method
	{
		for(i=0;i<order;i++)    
		{
			x_new[i]=A[i][order]; //updating the value of x begins here
			for(j=0;j<order;j++)
			{
				if(j!=i) x_new[i]-=A[i][j]*x[j];
			}
			x_new[i]/=A[i][i];
		}
		max=fabs(x_new[0]-x[0]); //error calculation
		for(i=0;i<order;i++)
		{
			error=fabs(x_new[i]-x[i]);
			if(error>max) max=error;
		}
		for(i=0;i<order;i++) x[i]=x_new[i];
	}while(max>=0.000005);       //minimum error calculation
	printf("The solution set is:\n");  //printing the results 
	fprintf(fp,"The solution set is:\n");
	for(i=0;i<order;i++){
		printf("%0.5f\t",x[i]);
		fprintf(fp,"%0.5f\t",x[i]);
	}
	printf("\n");	
	fclose(fp);
}
