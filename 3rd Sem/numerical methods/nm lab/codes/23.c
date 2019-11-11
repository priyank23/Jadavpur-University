/*Program to apply runge kutta method for solving linear differential equations*/ 
#include<stdio.h>
#include<math.h>
#define f(x,y) y-x   //function used :- y'=y-x
int main()
{
	FILE *fp;          
	fp=fopen("23.txt","w");   //file  opened in writing mode
	fprintf(fp,"  Second Order runge kutta method for solving differential equation.\n\nDE: y'=y-x\n\n");
    float x0,y0,m1,m2,m3,m4,m,y,x,h,xn; 
    printf("Enter the value of x0,xn,h,y0:\n");   //initial and final values of x, height of x and initial value of y are taken as 													  input 
    scanf("%f %f %f %f",&x0,&xn,&h,&y0);
    x=x0;
    y=y0;
    printf("\n\nX\t\tY\n");
    fprintf(fp," The respective values of x and y are\n     x  \t     y\n\n");
    m=f(x0,y0)-h+h*f(x0,y0);   //second orderr runga kutta formula
    while(x<xn)   //method application here
    {
        y=y+m*h;
        x=x+h;
        printf("%f\t%f\n",x,y);
        fprintf(fp,"  %f\t%f\n",x,y);   //printing final results at each iteration
    }
}
