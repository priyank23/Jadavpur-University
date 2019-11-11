/*Program to tabulate large integers and remainders obtained by dividing from 3 prime numbers*/
#include <stdio.h>
#include <time.h>
int main(void)						//main begins here
{
	srand(time(0));					//for generating different numbers in every iteration
	int p1=2287,p2=3671,p3=4001;	
	int iter,num=30;
	long long int l[num];
	printf("The prime numbers used are:2287 3671 4001.\n\nl[i]\tR1\tR2\tR3\n");
	for(iter=0;iter<num;iter++)		//generating large numbers and printing results
	{
		l[iter]=rand()%(100000)+50001;
		printf("%lld\t",l[iter]);
		printf("%lld\t",l[iter]%p1);
		printf("%lld\t",l[iter]%p2);
		printf("%lld\n",l[iter]%p3);
	}
}
