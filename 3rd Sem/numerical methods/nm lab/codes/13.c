/*Program to implement LU decomposition method*/
#include<stdio.h>
int main(void)  //main begins here
{
	FILE *fp;
	fp=fopen("13.txt","w");
	fprintf(fp,"   LU Decomposition method.\n\n");
	int size,i,j,p,k;  
	printf("Enter the order of the matrix.\n");
	scanf("%d",&size);  //size of the matrix scanned from the terminal
	float A[size][size],L[size][size],U[size][size];
	printf("Enter the matrix.\n");  //matrix is scanned
	fprintf(fp,"A:");
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			scanf("%f",&A[i][j]);
			fprintf(fp,"%f\t",A[i][j]);
		}
		fprintf(fp,"\n  ");
	}
	for(i=0;i<size;i++)  //matrices initialised
		for(j=0;j<size;j++)
		{
			L[i][j]=0;U[i][j]=0;
		}		
			
	for(j=0;j<size;j++)  //loop of implementation
		for(i=0;i<size;i++)
		{
			if(i>=j)   //for lower matrix
			{
				L[i][j]=A[i][j];
				for(k=0;k<=j-1;k++) L[i][j]-=L[i][k]*U[k][j];
				if(i==j) U[i][j]=1;
			}
			else   //for upper matrix
			{
				U[i][j]=A[i][j];
				for(k=0;k<=i-1;k++)
					U[i][j]-=L[i][k]*U[k][j];
				U[i][j]/=L[i][i];	
			}
		}
	printf("\nL\n");  //printing results
	fprintf(fp,"\nL:");
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++){
			printf("%f\t",L[i][j]);
			fprintf(fp,"%f\t",L[i][j]);
		}
		printf("\n");
		fprintf(fp,"\n  ");	
	}

	printf("\nU\n");
	fprintf(fp,"\nU:");
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++){
			printf("%f\t",U[i][j]);
			fprintf(fp,"%f\t",U[i][j]);
		}
		fprintf(fp,"\n  ");
		printf("\n");	
	}
	fclose(fp);
}
