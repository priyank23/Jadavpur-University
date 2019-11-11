#include<stdio.h>
#define SEN -1
int isEmpty(int arr[])
{
	if(arr[0]==SEN)
		return 1;
	return 0;
}
int lengthList(int arr[])
{
	int iter=0,count=0;
	for(iter=0;arr[iter]!=SEN;iter++)
	count++;
	return count;
}
void display(int arr[])
{
	int i=0;
	if(isEmpty(arr)==0)
	while(arr[i]!=-1)
	{
		printf("%d\n",arr[i]);
		i++;
	}
	else printf("The list is empty.\n");
	printf("\n");
}
int readn(int arr[],int n)
{
	if(arr[n-1]==SEN)
		printf("There is no element at %dth position.\n\n",n);
	else
		printf("The %dth element in the list is %d.\n\n",n,arr[n-1]);	
}
int search(int arr[],int key)
{
	int iter;
	for(iter=0;arr[iter]!=SEN;iter++)
		if(arr[iter]==key) return iter+1;
	return SEN;	
}
int sort(int arr[])
{
	int iter1,iter2;
	for(iter1=0;arr[iter1+1]!=SEN;iter1++)
		for(iter2=iter1+1;arr[iter2]!=SEN;iter2++)
		{
			if(arr[iter1]>arr[iter2])
			{
				int temp=arr[iter1];
				arr[iter1]=arr[iter2];
				arr[iter2]=temp;
			}
		}
	printf("The list has become:\n");
		display(arr);	
}
int insert(int arr[],int n,int key)
{
	if(arr[n-1]==SEN)
	{
		arr[n-1]=key;
		arr[n]=SEN;
	}
	else
	{
		int iter,temp=arr[n-1],temp2;
		arr[n-1]=key;
		for(iter=n;arr[iter]!=SEN;iter++)
		{
			temp2=arr[iter];
			arr[iter]=temp;
			temp=temp2;
		}
			arr[iter]=temp;
			arr[iter+1]=SEN;
	}
	printf("The list has become:\n");
	display(arr);
	return 0;
}
int deleten(int arr[],int n)
{
	if(arr[n-1]==SEN)
	{
		printf("\nThere is no element at %d position in the list.\n",n);
	}
	else
	{
		int iter;
		for(iter=n-1;arr[iter]!=SEN;iter++)
		{
			arr[iter]=arr[iter+1];
		}
		arr[iter-1]=SEN;
		printf("The list has become:\n");
		display(arr);	
	}
	return 0;
}

void init(int arr[])
{
	int i=0;
	printf("Begin entering the list.\n-1 to termninate.\n");
	while(1)
	{
		int val;
		scanf("%d",&val);
		if(val==-1)
		{
			arr[i]=SEN;
			break;
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
	int arr[1000],ch,val,pos;
	init(arr);
	while(1)
	{
		printf("What do you want to do?\n1.Check whether the list is empty or not.\n2.Print the length of the list.\n3.Read the nth element in the list.\n4.Insert an element in the list\n5.Delete an element in the list.\n6.Search in the list.\n7.Sort the list.\n8.Exit.\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				if(isEmpty(arr)) printf("The List is empty.\n\n");
				else printf("The List is not empty.\n\n");
				break;
			case 2:	
				printf("The length of the list is %d.\n\n",lengthList(arr));
				break;
			case 3:
				printf("Enter the position of the element to be read.\n");
				scanf("%d",&pos);
				readn(arr,pos);
				break;
			case 4:
				printf("Enter the value and position of the value to be inserted.\n");
				scanf("%d%d",&val,&pos);
				insert(arr,pos,val);
				break;
			case 5:
				printf("Enter the position at which the element is to be deleted.\n");
				scanf("%d",&pos);
				deleten(arr,pos);
				break;
			case 6:
				printf("Enter the value to be searched.\n");
				int val;
				scanf("%d",&val);
				int pos=search(arr,val);
				if(pos!=SEN) printf("The value is found at position %d.\n\n",pos);
				else printf("Value not found in the list!!!\n\n");
				break;
			case 7:
				sort(arr);
				break;
			case 8:
				return 0;
			default:
				printf("Invalid Input.\n");
							
		}
	}
}
