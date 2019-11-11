/*Program to implement Newton raphson mathod for solving non linear simultaneous equations*/
#include<stdio.h>
#include<math.h>
#define f(x,y) x*x-y*y-3   //first equation as f(x,y)=0
#define g(x,y) x*x+y*y-13  //second equation as g(x,y)=0
#define max(x,y) x>y?x:y   //max function
//main begins
int main(void)
{
	FILE *fp;
	fp=fopen("20.txt","w");
	fprintf(fp,"     Newton Raphson method for solving non-linear simultaneous equations\n\n");
	fprintf(fp,"Functions:\nf(x,y)=x^2-y^2-3\ng(x,y)=x^2+y^2-13\n\n");
	int iter=0;
	float x,y,h,k,pfx,pfy,pgx,pgy,f0,g0,jac;  
	x=sqrt(6.5); //initialisation of x,y for making g(x,y)=0;
	y=x;
	fprintf(fp,"Sl\t\th\t\t\tk\t\t   x\t\t\ty\t\tjacobian term\n");
	do
	{
		iter++;  //for printing the iterations
		f0=f(x,y); //function values
		g0=g(x,y);
		pfx=2*x;  //partial derivatives of functions w.r.t variable
		pfy=-2*y;
		pgx=2*x;
		pgy=2*y;
		jac=pfx*pgy-pfy*pgx;  //value of jacobian
		/*h and k are approximation to the value of x and y calculated by solving the equations
				h(pfx)+k(pfy)=f0 and
				h(pgx)+k(pgy)=g0*/		
		h=(pfy*g0-pgy*f0)/(pfx*pgy-pfy*pgx); //extending limits of x
		k=(pgx*f0-pfx*g0)/(pfx*pgy-pfy*pgx); //extending limits of y
		x=x+h;
		y=y+k;
		fprintf(fp,"%d\t%f\t%f\t%f\t%f\t%f\n",iter,h,k,x,y,jac);  //printing value of x and y in each iteration
	}while((max(f(x,y),g(x,y))>=0.0005)&&jac!=0);   //loop shall run till functions tend to 0
	printf("Results:\nx=%f  y=%f  \n",x,y);   //printing final results
	fprintf(fp,"\n\nResults:\nx=%f y=%f",x,y);
	fclose(fp);
}
