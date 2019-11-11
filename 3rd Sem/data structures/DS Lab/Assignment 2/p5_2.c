/*Program to check whether a given order is sorted or not*/
#include<stdio.h>
int checksort(int arr[],int size)						//function to check the sorting order
{
	int iter=1;
	if(arr[0]<arr[1])									//checking the ascending order of the array
	{
		for(iter;iter<size-1;iter++)
		{
			if(arr[iter]>arr[iter+1])
			return 0;
		}
		return 1;
	}
	
	if(arr[0]>arr[1])									//checking the descending order of the array
	{
		for(iter=1;iter<size-1;iter++)
		{
			if(arr[iter]<arr[iter+1])
			return 0;
		}
		return -1;
	}
}
int main(void)
{
	int size,iter;      
	printf("Enter the size of the array.\n");    //taking the size of the array as input
	scanf("%d",&size);
	int arr[size];
	printf("Enter the elements of the array.\n");
	for(iter=0;iter<size;iter++)				//taking the elements of the array as input 
		scanf("%d",&arr[iter]);
	int x=checksort(arr,size);              	//calling checksort() function to check the sorting order
	if(x==0)                                	//The function returns 0 means the array is not sorted
		printf("The array is not sorted.\n");
	else if(x==1)								//The function returns 1 means the array is sorted in ascending order					
		printf("The array is sorted in ascending order.\n");
	else										//The function returns -1 means the array is sorted in descending order
		printf("The array is sorted in descending order.\n");
}
