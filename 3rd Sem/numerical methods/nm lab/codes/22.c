/*Program for implementing regula falsi method*/
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
   fp=fopen("22.txt","w");                                                //file opens
   int iter=1;
   float a,b,c,f_a,f_b,f_c,abs_error,multi,prev_c,prev_error=0,conv;
   do                                                                            //taking input from user
   {
   printf("Enter lower and upper bound of x\n");
   scanf("%f%f",&a,&b);
   if(func(a)*func(b)>=0)
   printf("ERROR!!! Enter again!\n");
   }while(func(a)*func(b)>=0);
   c=a;                                                                          //for initialising a prev_c within range
   fprintf(fp,"SL.no\t\ta\t\t\tb\t\t\tc\t\t\tf(c)\t\terror\torder of convergence\n");    
   do                                                                            //loop for finding the root of the function     
   {  
      prev_c=c;                                                          
      f_a=func(a);                                                               //calling the function
      f_b=func(b);
      c=((a*f_b)-(b*f_a))/(f_b-f_a);
      f_c=func(c);
      multi=f_c*f_a;
      abs_error=fabs(prev_c-c);
      
      if(prev_error!=0){
      conv = log(abs_error)/log(prev_error);}
      prev_error=abs_error;
      fprintf(fp,"%d\t\t%f\t%f\t%f\t%f\t%f\t%f\n",iter,a,b,c,f_c,abs_error,conv);
      if(fabs(f_c)<=0.000005)                                                    //checking for required precision
          break;
      else if(multi<0) b=c;
      else a=c;
      iter++;
   }while(fabs(prev_c-c)>=0.000005);                                                  //checking for minimal error
   fprintf(fp,"\n\nroot of the function = %f",c);                                //printing result in file
   fclose(fp);
   printf("res = %f",c);                                                         //printing result in terminal
}          
