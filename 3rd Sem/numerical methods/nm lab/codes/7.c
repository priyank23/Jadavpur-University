/*Program to solve linear equations using gauss jordan method*/
#include<stdio.h>
#include<math.h>
void pivot(double a[100][100], int, int);
int main()
{
	FILE *fp;
	fp=fopen("7.txt","w");
	int i,j,k,n,maxpos,l,ch,loop1,loop2;
	double m,s,temp,max;	
	printf("Enter Value of n:\n");     //number of variables is scanned
	scanf("%d", &n);
	printf("Enter the augmented matrix:\n"); //augmented matrix is taken from the user
	fprintf(fp,"The augmented matrix is:\n");
	double a[n][n+1], x[n];
	for(i=0; i<n; i++)
	{
		for(j=0; j<=n; j++){
			scanf("%lf", &a[i][j]);
			fprintf(fp,"%lf", &a[i][j]);
		}
		fprintf(fp,"\n");
	}
	for(k=0; k<n; k++)      //loop for the implementation of the method
	{
		for(i=0; i<n; i++){
			if(i==k)
				continue;
			m=a[i][k]/a[k][k];
			for(j=k; j<n+1; j++)
				a[i][j]= a[i][j]-(m*a[k][j]);
		}
	} 
	printf("\n");
	fprintf(fp,"\n");
	for(i=0; i<n; i++) 
	{
		printf("\n");
		fprintf(fp,"\n");
		for(j=0; j<=n; j++)
		{	
			printf("%lf   ", a[i][j]);
			fprintf(fp,"%lf   ", a[i][j]);	
		}
	}
	for(i=0; i<n; i++)
	{
		x[i]=a[i][n]/a[i][i];
	}
	printf("\n\nSolution to the Equation:\n");  //printing the results
	fprintf(fp,"\n\nSolution to the Equation:\n");
	for(i=0; i<n; i++){
		printf("%lf\n", x[i]);
		fprintf(fp,"%lf\n",x[i]);
	}
	fclose(fp);
	return 0;
}
