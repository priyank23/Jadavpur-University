/*Program to apply modified euler's method for solving linear differential equation*/
#include<stdio.h>
#include<math.h>
#define fun(x,y) y-x    //function used is y'=y-x
void main()       //main begins here
{ 
	FILE *fp;          
	fp=fopen("modified euler.txt","w");
	fprintf(fp,"   Modified euler method for solving differential equation.\n\nDE: y'=y-x\n\n");
    int i,j,c;
    float x,y,h,m,m1,m2,a,s[100],w;
	printf("  Enter the value of x0,xn,h,y0:\n");   //initial and final values of x, height of x and initial value of y is taken as 													  input 
	scanf("%f%f%f%f",&x,&a,&h,&y);
	s[0]=y;
	printf(" The respective values of x and y are\n     x  \t     y\n\n");
	fprintf(fp," The respective values of x and y are\n     x  \t     y\n\n");
	for(i=1;x<a;i++)   //method application here
    {
		printf("  %f\t%f\n",x,y);
		fprintf(fp,"  %f\t%f\n",x,y);
	    w=100;
	    m=fun(x,y);
	    x= x+h;
	    c=0;
	    while(w>0.00001)            //convergence of y at ith iteration
	    {
	        m1=fun(x,s[c]);
	        m2=(m+m1)/2;
	        s[c+1]=y+m2*h;
	        w=fabs(s[c]-s[c+1]);
	        c++;
	    }
	    y=s[c];
    }
    printf("  %f\t%f\n",x,y);
	fprintf(fp,"  %f\t%f\n",x,y);   //printing final results
	fclose(fp);
}
