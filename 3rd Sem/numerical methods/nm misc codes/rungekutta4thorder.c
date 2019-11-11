/*Program to apply runge kutta method for solving linear differential equations*/ 
#include<stdio.h>
#include<math.h>
#define f(x,y) y-x   //function used :- y'=y-x
int main()
{
	FILE *fp;          
	fp=fopen("runge kutta 4th order.txt","w");   //file  opened in writing mode
	fprintf(fp,"   Runge kutta method for solving differential equation.\n\nDE: y'=y-x\n\n");
    float x0,y0,m1,m2,m3,m4,m,y,x,h,xn; 
    printf("Enter the value of x0,xn,h,y0:\n");   //initial and final values of x, height of x and initial value of y are taken as 													  input 
    scanf("%f %f %f %f",&x0,&xn,&h,&y0);
    x=x0;
    y=y0;
    printf("\n\nX\t\tY\n");
    fprintf(fp," The respective values of x and y are\n     x  \t     y\n\n");
    while(x<xn)   //method application here
    {
        m1=f(x0,y0);
        m2=f((x0+h/2.0),(y0+m1*h/2.0));
        m3=f((x0+h/2.0),(y0+m2*h/2.0));
        m4=f((x0+h),(y0+m3*h));
        m=((m1+2*m2+2*m3+m4)/6);
        y=y+m*h;
        x=x+h;
        printf("%f\t%f\n",x,y);
        fprintf(fp,"  %f\t%f\n",x,y);   //printing final results at each iteration
    }
}
