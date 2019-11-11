#include<stdio.h>
#define size 1000
int isEmpty(int n)
{
	if(n==-1)
		return 1;
	return 0;
}
void display(int arr[],int end)
{
	int i=0;
	if(isEmpty(end)==0)
	while(i<=end)
	{
		printf("%d\n",arr[i]);
		i++;
	}
	else printf("The list is empty.\n");
	printf("\n");
}
int readn(int arr[],int n,int end)
{
	if(n-1>end)
		printf("There is no element at %dth position.\n\n",n);
	else
		printf("The %dth element in the list is %d.\n\n",n,arr[n-1]);	
}
int search(int arr[],int key,int end)
{
	int iter;
	for(iter=0;iter<end;iter++)
		if(arr[iter]==key) return iter+1;
	return -1;	
}
void sort(int arr[],int end)
{
	int iter1,iter2;
	for(iter1=0;iter1<=end-1;iter1++)
		for(iter2=iter1+1;iter2<=end;iter2++)
		{
			if(arr[iter1]>arr[iter2])
			{
				int temp=arr[iter1];
				arr[iter1]=arr[iter2];
				arr[iter2]=temp;
			}
		}
	printf("The list has become:\n");
		display(arr,end);	
}
void insert(int arr[],int n,int key,int *end)
{
	if(n-1==*end+1)
	{
		arr[n-1]=key;
		*end=n-1;
	}
	else
	{
		int iter,temp=arr[n-1],temp2;
		arr[n-1]=key;
		for(iter=n;iter<=*end;iter++)
		{
			temp2=arr[iter];
			arr[iter]=temp;
			temp=temp2;
		}
			arr[iter]=temp;
			*end=iter;
	}
	printf("The list has become:\n");
	display(arr,*end);
}
void deleten(int arr[],int n,int *end)
{
	if(n-1>*end)
	{
		printf("\nThere is no element at %d position in the list.\n",n);
	}
	else
	{
		int iter;
		for(iter=n-1;iter<*end;iter++)
		{
			arr[iter]=arr[iter+1];
		}
		*end=iter-1;
		printf("The list has become:\n");
		display(arr,*end);	
	}
}

int init(int arr[])
{
	int i=0;
	printf("Begin entering the list.\n-1 to termninate.\n");
	while(1)
	{
		int val;
		scanf("%d",&val);
		if(val==-1)
		{
			int end=i-1;
			return end;
		}
		else 
		{
			arr[i]=val;
			i++;
		}
	}
}
int main()
{
	int arr[size],ch,val,pos;
	int end=init(arr);
	while(1)
	{
		printf("What do you want to do?\n1.Check whether the list is empty or not.\n2.Print the length of the list.\n3.Read the nth element in the list.\n4.Insert an element in the list\n5.Delete an element in the list.\n6.Search in the list.\n7.Sort the list.\n8.Exit.\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				if(isEmpty(end)) printf("The List is empty.\n\n");
				else printf("The List is not empty.\n\n");
				break;
			case 2:	
				printf("The length of the list is %d.\n\n",end+1);
				break;
			case 3:
				printf("Enter the position of the element to be read.\n");
				scanf("%d",&pos);
				readn(arr,pos,end);
				break;
			case 4:
				printf("Enter the value and position of the value to be inserted.\n");
				scanf("%d%d",&val,&pos);
				insert(arr,pos,val,&end);
				break;
			case 5:
				printf("Enter the position at which the element is to be deleted.\n");
				scanf("%d",&pos);
				deleten(arr,pos,&end);
				break;
			case 6:
				printf("Enter the value to be searched.\n");
				int val;
				scanf("%d",&val);
				int pos=search(arr,val,end);
				if(pos!=-1) printf("The value is found at position %d.\n\n",pos);
				else printf("Value not found in the list!!!\n\n");
				break;
			case 7:
				sort(arr,end);
				break;
			case 8:
				return 0;
			default:
				printf("Invalid Input.\n");
		}
	}
}
