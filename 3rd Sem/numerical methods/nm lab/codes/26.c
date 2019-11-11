/*Program to integrate f(x)=1/(1+x^2) using trapezoidal rule*/
#include<stdio.h>
#include<math.h>
#define f(x) 1/(1+pow(x,2))
int main(void)
{
	FILE *fp;
	fp=fopen("26.txt","w");
	fprintf(fp," Integrating f(x)=1/(1+x^2) using trapezoidal rule\n\n");
    int i,n;
    float x0,xn,h,sumo=0,sume=0,ans;
    printf("\n Enter values of x0,xn,h(length of sub domain):\n");
    scanf("%f%f%f",&x0,&xn,&h);
    n=(xn-x0)/h;
    if(n%2==1)
    {
        n=n+1;
    }
    h=(xn-x0)/n;
    float x[n],y[n];
    printf("\nrefined value of n and h are:%d  %f\n",n,h);
    printf("\n f(x) values \n"); //printing function values
    fprintf(fp,"\n f(x) values \n");
    for(i=0; i<=n; i++)
    {
        x[i]=x0+i*h;
        y[i]=f(x[i]);
        printf("\nf(%f)=%f\n",x[i],y[i]);
        fprintf(fp,"\nf(%f)=%f\n",x[i],y[i]);
    }
    for(i=1; i<n; i++)  //calculating integration sum
    {
        if(i%2==1)
        {
            sumo=sumo+y[i];
        }
        else
        {
            sume=sume+y[i];
        }
    }
    ans=h/3*(y[0]+y[n]+4*sumo+2*sume);   //calculating final integration sum
    printf("\nfinal integration is %f",ans); //printing final result
	fprintf(fp,"\n Final integration value is %f",ans);
	fclose(fp);
}
