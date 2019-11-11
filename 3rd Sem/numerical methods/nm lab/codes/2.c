#include<stdio.h>
#include<math.h>
float func(float x)                                                              //function to find the value of f(x)
{
    float res;
    res= exp(-x)-x;
    return res;
}
int main(void)                                                                   //main begins
{
   FILE *fp;               
   fp=fopen("2.txt","w");                                                //file opens
   int iter=1;
   float a=-1.0,b=1.0,m,f_a,f_b,f_m,abs_error,multi;
   fprintf(fp,"SL.no\t\ta\t\t\tb\t\t\tm\t\t\tf(m)\terror\n");    
   do                                                                            //loop for finding the root of the function     
   {  abs_error=fabs(b-a);                                                          
      m=(a+b)/2;
      f_a=func(a);                                                               //calling the function
      f_b=func(b);
      f_m=func(m);
      multi=f_m*f_a;
      fprintf(fp,"%d\t\t%f\t%f\t%f\t%f\t%f\n",iter,a,b,m,f_m,multi,abs_error);
      if(fabs(f_m)<=0.000005)                                                    //checking for required precision
          break;
      else if(multi<0) b=m;
      else a=m;
      iter++;
   }while(fabs(b-a)>=0.000005);                                                  //checking for minimal error
   fprintf(fp,"\n\nroot of the function = %f",m);                                //printing result in file
   fclose(fp);
   printf("res = %f",m);                                                         //printing result in terminal
}          
