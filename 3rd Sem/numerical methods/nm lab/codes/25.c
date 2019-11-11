/*Program to apply simpson's 1/3 method to solve a definite integrals*/
#include<stdio.h>
#include<math.h>
float f(float x)    //function f=1/(1+x^2)
{
    return 1/(1+x*x);
}
void main()           //main begins here
{
	FILE *fp;
	fp=fopen("25.txt","w");
	fprintf(fp,"      Simpson's method for solving definite integrals\n\nfunction used:- f(x)=1/(1+x^2)\n");
    int i,n;
    float x0,xn,h,y[20],sumo,sume,ans,x[20];    //variables declaration
    printf("\n Enter values of x0,xn,h: ");  //taking input for the limits of x
    scanf("%f%f%f",&x0,&xn,&h);
    n=(xn-x0)/h;                      
    if(n%2==1) n++;
    h=(xn-x0)/n;
    printf("\n   Y values: \n");
    fprintf(fp,"\n Y values: \n");
    for(i=0; i<=n; i++)  //calculation of required values of x and y
    {
        x[i]=x0+i*h;
        y[i]=f(x[i]);
        printf("\n f(%f)=%f\n",x[i],y[i]);
        fprintf(fp,"\n f(%f)=%f\n",x[i],y[i]);
    }
    sumo=0;
    sume=0;
    for(i=1; i<n; i++)
    {
        if(i%2==1) sumo+=y[i];
        else sume+=y[i];
    }                            
    ans=h/3*(y[0]+y[n]+4*sumo+2*sume);   //calculation of the final value
    printf("\n Final integration is %f",ans);
    fprintf(fp,"\n Final integration is %f",ans);
    fclose(fp);
}
