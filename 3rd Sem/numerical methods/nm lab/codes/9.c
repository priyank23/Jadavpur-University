/*Program for implementing Gauss seidel method*/
#include<stdio.h>
#include<math.h>
int main(void)  //main begins here
{
	FILE *fp;
	fp=fopen("9.txt","w");
	fprintf(fp,"   GAUSS SEIDEL METHOD.\n\n");
	int order,i,j,k;
	printf("Enter the number of variables\n");
	scanf("%d",&order);			//scans the number of variables
	float A[order][order+1],x[order],x_new[order],error;
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
			for(j=0;j<i;j++)
			{
				x_new[i]-=A[i][j]*x_new[j];
			}
			for(j=i+1;j<order;j++)
			{
				x_new[i]-=A[i][j]*x[j];
			}
			x_new[i]/=A[i][i];
		}
		error=fabs(x_new[0]-x[0]); //error calculation
		for(i=0;i<order;i++)
		{
			if(error>fabs(x_new[i]-x[i])) error=fabs(x_new[i]-x[i]);
		}
		for(i=0;i<order;i++) x[i]=x_new[i];
	}while(error>=0.00001);       //minimum error calculation
	printf("The solution set is:\n");  //printing the results
	fprintf(fp,"The solution set is:\n"); 
	for(i=0;i<order;i++){
		printf("%0.5f\t",x[i]);
		fprintf(fp,"%0.5f\t",x[i]);
	}
	printf("\n");
	fclose(fp);	
}
