/*Program to apply secant method*/
#include<stdio.h>
#include<math.h>
#define f(x) exp(-x)-x  //original function
int main()              //main begins
{ 	
	FILE *fp;
	fp= fopen("24.txt","w");
	float x0,x1,x2,order,error,pre_error;
	int iter=1;
	fprintf(fp,"   SECANT METHOD\n\n");
	printf("Solving Equation e^(-x)-x=0 using Secant method:\n");			
	printf("Please input initial approximations: ");
	scanf("%f%f",&x0,&x1);								//taking inputs from user
	fprintf(fp,"Sl\t\tx0\t\t\tx1\t\t\tf(x0)\t\tf(x1)\t\tx2\t\t|x1-x0|\t\tOrder(c)\n");
	do													//method loop		
	{
		x2=(x0*(f(x1))-x1*(f(x0)))/((f(x1))-(f(x0)));	//formula to apply secant method
		pre_error=fabs(x1-x0);
		error=fabs(x2-x1);
		order=log(error)/log(pre_error);	
 		fprintf(fp,"%d\t%9f\t%9f\t%9f\t%9f\t%9f\t%9f\t%9f\n",iter,x0,x1,(f(x0)),(f(x1)),x2,fabs(x2-x1),fabs(order));		//printing results in the file
		x0=x1;
		x1=x2;
		iter++;
	}while(pre_error>0.0005);			//condition for loop to end
	fprintf(fp,"\n\nThe root of the equation is %f.\n",x1);
	printf("\nThe root of the equation is: %f\n",x1);		//printing final results
	return 0;
	fclose(fp);
}
