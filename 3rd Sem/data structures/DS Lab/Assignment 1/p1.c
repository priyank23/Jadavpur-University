#include<stdio.h>
#include<stdlib.h>

long long unsigned int rec_fact(int n){
	if(n==0 || n==1){
		return 1;
		}
	else return n*rec_fact(n-1);
}

long long unsigned int iter_fact(int m){
	int i;
	long long unsigned int factorial=1;
	if (m==0 || m==1){
		return 1;
		}
	else 
	{
	for(i=m;i>0;i--){
		factorial=factorial*i;
		}
	return factorial;
    }
}

int main()
{
	int choice,term;
	printf("Enter a number:\n");
	scanf("%d",&term);
	printf("\nChoose any one type.\nPress 1 for recursive method.\nPress 2 for iteration method:\n");
	scanf("%d",&choice);
	switch(choice){
	
		case 1 :printf("%llu\n",rec_fact(term));
			break;
		case 2 :printf("%llu\n",iter_fact(term));
			break;

		default:printf("\nInvalid\n");
			break;
	};
	return 0;
}

