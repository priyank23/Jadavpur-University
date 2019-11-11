/*Program for describing chebysev raphson method
f(x)= x^3-x-3*/
#include<stdio.h>
#include<math.h>
float func(float x)                                            //function for finding the value of f(x)      
{
	return (x*x*x-x-3);
}
float dif_func(float x)                                        //function for finding the value of f'(x)
{
	return (3*x*x -1);
}
float dDifFunc(float x)                                        //function for finding the value of f"(x)
{
	return (6*x);
}
float ri(float r)                                              //function for finding the value of r_next
{
	return (r-(func(r)/dif_func(r))-(func(r)*func(r)*dDifFunc(r)/(2*dif_func(r)*dif_func(r)*dif_func(r))));
}
float gf(float x)                                             //function for checking the convergence of the function  
{
	float res;
	res=fabs(func(x)*dDifFunc(x)/((dif_func(x)*dif_func(x))));
	return res;
}
int main()                                                 //main function begins here  
{
	int iter=1;
	float r_i,r_i1,abs_error,prev_error=0,cond,conv;
	
	printf("Enter the initial point:\n");                      //input taken from user
	scanf("%f",&r_i);
	
	FILE *fp;
	fp=fopen("3.txt","w");                                  //opening of file in write mode
	fprintf(fp,"Sl.no.\t\tr  \t\tcondition\t  r_next\t\terror\torder of convergence\n");
	do                                                        //loop for the method
	{
	cond=gf(r_i);
	r_i1=ri(r_i);                                             //updating the value of r_next
	abs_error=fabs(r_i1-r_i);
	if(prev_error!=0) conv=log(abs_error)/log(prev_error);    //finding the order of convergence
	prev_error=abs_error;                                                
	if(iter==1)                
	fprintf(fp,"%2d\t\t%9f\t%9f\t%9f\t%9f\t   NA\n\n",iter,r_i,cond,r_i1,abs_error);
	else
		fprintf(fp,"%2d\t\t%9f\t%9f\t%9f\t%9f\t%9f\n\n",iter,r_i,cond,r_i1,abs_error,conv);	 
	iter++;	                                                 
	r_i=r_i1;
	}while(abs_error>=0.00001);                               //checking precision  
	printf("root of the function=%f\n",r_i1);                   //printing result
	fprintf(fp,"root of the function=%f\n\n",r_i1);
	fclose(fp);
	return 0;
}	
