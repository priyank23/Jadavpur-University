#include <stdio.h>
#include <stdlib.h>
int main()
{
	char name[16]="PRIYANKLOHARIWAL";
	long long unsigned int a=0,b=0;
	int i;
	for( i=0;i<16;i++)
	{
		if(i<7)
			a=a*100+(int)name[i];
		else
			b=b*100+(int)name[i];
	}
	printf("%llu\t%llu",a+b,(a+b)%2287);
	return 0;
}
