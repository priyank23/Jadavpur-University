/*Program for finding a fibonacci term and display the time taken for its exection iteratively and recursively*/ 
#include<stdio.h>
#include<time.h>
#define Int long long unsigned int

Int rec_fib(Int n)                              //function for recursion method
{
	if(n==1) return 1;
	else if(n==0) return 0;
	else return (rec_fib(n-1)+rec_fib(n-2));
}
Int iter_fib(Int n)                            //function for iteration method
{
	if(n==1||n==2) return 1;
	else
	{
		Int a=0,b=1,c,i;
		for( i=1;i<=n-1;i++)
		{
			c=b+a;
			a=b;
			b=c;
		}
		return c;
	} 
}

int main(void)                                   //main begins here
{
	int term; 
	printf("Enter the term of the series to be printed:\n"); 
	scanf("%d",&term);                           //input taken from the user
	clock_t t1=clock();                          //time calculation starts for resursion method
	printf("The %d th term found by recursive method is %llu \n",term,rec_fib(term));
	t1=clock()-t1;                               //time calculation stops for recursion method
	clock_t t2=clock();                          //time calculation starts for iteration method
	printf("The %d th term found by iteration method is %llu \n",term,iter_fib(term));
	t2=clock()-t2;                               //time calculation stops for iteration method
	double dur1=((double)t1)/CLOCKS_PER_SEC,dur2=((double)t2)/CLOCKS_PER_SEC; //time calculated in seconds
	printf("The time taken by recursive and iteration method is %llf and %llf respectively.\n\n",dur1,dur2);//result printed here
}
