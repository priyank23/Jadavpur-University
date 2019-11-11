/*Program to apply multi point iteration method to find the root of the equation e^x-2x-1*/
#include<stdio.h>
#include<math.h>

double f(double x)                                              //function to return f(x)
{
	double y;
	y=exp(x)-2*x-1;
	return y;
}

double df(double x)												//function to return f'(x)
{
	double y;
	y=exp(x)-2;
	return y;
}
double soln(double r)											//fuunction to return root of the equation using multipoint iteration method
{
	int i=1;
	double ri,ri_s,pre_err,err,order=0;
	FILE *fp;													//opening the file
	fp=fopen("15.txt","w");
	fprintf(fp,"  MULTI POINT ITERATION METHOD.\n\n");
	pre_err=0;
	err=0;
	ri_s=r-(f(r)/(2*df(r)));									//calculating ri+1*
	ri=r-(f(r)/df(ri_s));										//calculating ri+1
	pre_err=fabs(r-ri);
	fprintf(fp,"i	   x		f(x)		a_error		order");
	fprintf(fp,"\n%d	%lf	%lf	%lf	%lf",i,r,f(r),pre_err,order);
	while(fabs(r-ri)>=0.0001)									//doing the iteration till error becomes less than 10^-4
	{
		r=ri;i++;
		ri_s=r-(f(r)/(2*df(r)));								//calculating ri+1*		
		ri=r-f(r)/df(ri_s);										//calculating ri+1
		err=fabs(r-ri);											//calculating error
		order=log(err)/log(pre_err);							//calculating order of convergence
		fprintf(fp,"\n%d	%lf	%lf	%lf	%lf",i,r,f(r),err,order);//printing results
		pre_err=err;											//updating previous error
	}
	fprintf(fp,"\n\nThe root of the equaion is %lf\n",r);		//printing the final result
	fclose(fp);													//closing the file				
	return r;													//returning the root		
}
/*main begins here*/
void main()
{
	double r;                           
	printf("enter any starting point:"); //taking input from the user
	scanf("%lf",&r);
	printf("\nroot=%lf",soln(r));        //printing the result by calling the function
}
