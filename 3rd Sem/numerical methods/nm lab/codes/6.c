/*
  Program to implement GAUSS' FORWARD INTERPOLATION FORMULA.
        ---------------------------------
*/
#include<stdio.h>
#include<math.h>

void main()
{
	FILE *fp;
	fp=fopen("6.txt","w");
	fprintf(fp,"GAUSS CENTRAL FORWARD INTERPOLATION.\n\n");
	int n,i,j;
	float y1,y2,y3,y4,x,nr,dr,y=0,h,p;                  
	float diff[20][20];             

	// Input section.
	printf("\n\n Enter the no. of terms: ");
	scanf("%d",&n);
	float ax[n],ay[n];

	// Input Sequel for array X and Y
	printf("\n\n Enter the value in the form of x f(x)\n ");
	// Input loop for X and Y
	for(i=0;i<n;i++)
	   scanf("%f%f",&ax[i],&ay[i]);
	
	// Inputting the required value query
	printf("\n\n Enter the required value of x.\n ");
	scanf("%f",&x);

	// Calculation and processing section.
	h=ax[1]-ax[0];
	for(i=0;i<n-1;i++)
	   diff[i][1]=ay[i+1]-ay[i];
	
	for(j=2;j<=4;j++)
	   for(i=0;i<n-j;i++)
	      diff[i][j]=diff[i+1][j-1]-diff[i][j-1];
	
	fprintf(fp,"x\t\t\tDifference Table\n");      
	
	for(i=0;i<n;i++)     //difference table printed
	{
		fprintf(fp,"%f|\t",ax[i]);
		fprintf(fp,"%f\t",ay[i]);
		for(j=1;j<n-i;j++)
			 fprintf(fp,"%f\t",diff[i][j]);
		fprintf(fp,"\n");	
	}
	i=0;
	//Implementation of the method performed here after
	do
	{
		i++;
	}while(ax[i]<x);
	i--;
	p=(x-ax[i])/h;
	y1=p*diff[i][1];
	y2=p*(p-1)*diff[i-1][2]/2;
	y3=(p+1)*p*(p-1)*diff[i-2][3]/6;
	y4=(p+1)*p*(p-1)*(p-2)*diff[i-3][4]/24;
	
	// Taking sum
	y=ay[i]+y1+y2+y3+y4;
	
	// Outut Section
	printf("\n When x = %6.4f , y = %6.8f\n",x,y);
	fprintf(fp,"\n\nResult:\tf(%f)=%f",x,y);   //final result printed in the file
	fclose(fp);
}
