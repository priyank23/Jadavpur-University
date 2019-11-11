//Program to find the eigen value of a given matrix
#include <stdio.h>
#include <math.h>
int main()
{
	FILE *fp;
	int i,j,order,iter=0;
	printf("Enter the order of matrix:");
	scanf("%d",&order);						//scans the order of the matrix
	fp=fopen("21.txt","w");				
    	float A[order][order],x[order],z[order],e[order],zmax,emax;	//declaring variable
   	printf("Enter the matrix\n");
   	fprintf(fp,"The given matrix is\n");
    	for(i=0; i<order; i++)						//scanning matrix
    	{
       		for(j=0; j<order; j++)
        	{
            		scanf("%f",&A[i][j]);				//scannning elements
            		fprintf(fp,"%f\t",A[i][j]);			//print matrix in file
        	}
        	fprintf(fp,"\n");
    	}
    	fprintf(fp,"\n\n");
    	for(i=0; i<order; i++)						//initialising first column vector 
    	{
        	x[i]=1;
    	}
    	fprintf(fp,"Sl.No\tX1\t\tx2\t\tx3\t\tC\t\terrorMax\n");		//print column headers
    	do
    	{			
    		iter++;							// iteration
        	for(i=0; i<order; i++)					//matrix multiplication
        	{
            		z[i]=0;
            		for(j=0; j<order; j++)
            		{
                		z[i]=z[i]+A[i][j]*x[j];
            		}
        	}
        	zmax=fabs(z[0]);					//calculating max value 
        	for(i=1; i<order; i++)
        	{
            		if((fabs(z[i]))>zmax)
                		zmax=fabs(z[i]);
        	}
        	for(i=0; i<order; i++)					//divide the column  matrix by c
        	{
            		z[i]=z[i]/zmax;
        	}
        	for(i=0; i<order; i++)					//calculate error
        	{
        	    	e[i]=0;
        	    	e[i]=fabs((fabs(z[i]))-(fabs(x[i])));
        	}
        	emax=e[0];
        	for(i=1; i<order; i++)
        	{
            		if(e[i]>emax)
                	emax=e[i];
        	}
        	fprintf(fp,"%d\t%9.6f\t%9.6f\t%9.6f\t%9.6f\t%9.6f\n",iter,x[0],x[1],x[2],zmax,emax);//printing iterations in files
        	for(i=0; i<order; i++)			//reinitialising matrix
        	{
            		x[i]=z[i];
        	}
    	}while(emax>0.0001);
    	printf("The required eigen value is %f\n\n",zmax);
    	printf("The required eigen vector is :\n");
    	fprintf(fp,"\nThe required eigen value is %f\n\n",zmax);		//printing results
    	fprintf(fp,"The required eigen vector is :\n");				
    	for(i=0; i<order; i++)		
    	{
        	printf("%f\n",z[i]);
        	fprintf(fp,"%f\n",z[i]);
    	}
    	return 0;
    	fclose(fp);
}
