/*Program to apply fixed point iteration*/
#include <stdio.h>
#include <math.h>
#define g(x) exp(-x)
#define dg(x) -exp(-x)
#define f(x) exp(-x)-x  //original function
double x1,e1;
int iter=0;
int main()                                                                                //main begins
{
	FILE *fp;		                                                                      //opening file pointer
	fp=fopen("4.txt","w");
	double x,order,e;
	printf("Enter the starting point:");
	scanf("%lf",&x);		                                                              //taking initial input from the user
	fprintf(fp,"SL\t\tx\t\tg(x)\t\tdg(x)\t\tf(x)\t\terror\t\torder\n");
	do			                                                                          //loop to apply the method
	{
	iter++;
	if (fabs(dg(x))>1)                                                                    //checking for convergence
	{
		printf("the process may not converge to the root\n");
		return 0;
	}
		x1=g(x);
		e=fabs(x1-x);
		if(iter==1)
		fprintf(fp,"%d\t%9f\t%9f\t%9f\t%9f\t%9f\tNA\n",iter,x,g(x),dg(x),f(x),e,order);
		else                                                                              //finding order of convergence
		{
			order=log(e)/log(e1);
			fprintf(fp,"%d\t%9f\t%9f\t%9f\t%9f\t%9f\t%9f\n",iter,x,g(x),dg(x),f(x),e,order);
		}
		e1=e;
		x=x1;
	}while(e>0.00005);                                                                     //checking the precision
	printf("The root of the equation is %f\n",x1);                                         //printing final result
	fprintf(fp,"\n\nThe root of the equation is %f\n",x1);
		fclose(fp);
		return 0;
}
