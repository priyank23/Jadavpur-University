/*Program to find eigen value using jacobi's method*/
#include<stdio.h>
#include<math.h>
int main(void)
{
	FILE *fp;
	fp=fopen("11.txt","w");
	fprintf(fp,"  Finding Eigen value using Jacobi's method\n\n");
	int i,j,n,r,s;
	printf("Enter the order of the matrix\n");
	scanf("%d",&n);
	float x[n][n],max=0,sum=0;
	printf("Enter the symmetrix of order %d\n",n);
	fprintf(fp,"The given matrix is:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			scanf("%f",&x[i][j]);
			fprintf(fp,"%f\t",x[i][j]);
			if(j>i)
			{
				sum+=x[i][j];
				if(max<fabs(x[i][j]))
				{
					max=x[i][j];r=i;s=j;
				}
			}
			fprintf(fp,"\n");		
		}		
	while(sum!=0)
	{
		float ang=atan((2*x[r][s])/(x[r][r]-x[s][s]))/2;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				if(j>i && j!=r &&j!=s)
				{
					x[j][r]=x[j][r]*cos(ang)+x[j][s]*sin(ang);
					x[r][j]=x[j][r];
					x[j][s]=x[j][s]*cos(ang)-x[j][r]*sin(ang);
					x[s][j]=x[j][s];
				}
			}
		x[r][r]=x[r][r]*cos(ang)*cos(ang)+2*x[r][s]*cos(ang)*sin(ang)+x[s][s]*sin(ang)*sin(ang);
		x[s][s]=x[s][s]*cos(ang)*cos(ang)-2*x[r][s]*cos(ang)*sin(ang)+x[r][r]*sin(ang)*sin(ang);	
		x[r][s]=0;x[s][r]=0;
		max=0,sum=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				if(j>i)
				{
					sum+=x[i][j];
					if(max<fabs(x[i][j]))
					{
						max=x[i][j];r=i;s=j;			
					}
				}		
			}
		printf("%f\n",sum);
	}
	printf("The eigen values are:\n");
	fprintf(fp,"The eigen values are:\n");
	for(i=0;i<n;i++){
		printf("%f\n",x[i][i]);
		fprintf(fp,"%f\n",x[i][i]);
	}
}
