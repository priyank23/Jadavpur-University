/*Program for performing linear and binary search over arrays of integers, floats and strings*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int int_lsearch(int arr[],int size,int val)     //function for linear search integers array 
{
	int i;
	for(i=0;i<size;i++)
	{
		if(arr[i]==val)
			return i;
	}
	return -1;
}
int int_bsearch(int low,int up,int arr[],int val)//function for binary search integers array
{
	int mid;
	do
	{
		mid=(up+low)/2;
		if(arr[mid]>val)
			up=mid-1;
		else if(arr[mid]<val)
			low=mid+1;
	}while(arr[mid]!=val && low<=up);
	if(arr[mid]==val)
		return mid;
	else
		return -1;
}

int string_lsearch(char arr[][20],int size,char val[])//function to linear search strings array
{
	int i;
	for(i=0;i<size;i++)
	{
		if(strcmp(arr[i],val)==0)
			return i;
	}
	return -1;
}
int string_bsearch(int low,int up,char arr[][20],char val[])//function to binary search strings array
{
	int mid;
	do
	{
		mid=(up+low)/2;
		if(strcmp(val,arr[mid])<0)
			up=mid-1;
		else if(strcmp(val,arr[mid])>0)
			low=mid+1;
	}while(strcmp(arr[mid],val)!=0 && low<=up);
	if(strcmp(arr[mid],val)==0)
		return mid;
	else
		return -1;
}
int float_lsearch(float arr[],int size,float val) //function to linear search floats array
{
	int i;
	for(i=0;i<size;i++)
	{
		if(arr[i]==val)
			return i;
	}
	return -1;
}
int float_bsearch(int low,int up,float arr[],float val)//function to binary search floats array
{
	int mid;
	do
	{
		mid=(up+low)/2;
		if(arr[mid]>val)
			up=mid-1;
		else if(arr[mid]<val)
			low=mid+1;
	}while(arr[mid]!=val && low<=up);
	if(arr[mid]==val)
		return mid;
	else
		return -1;
}
void int_sort(int arr[],int size)     //function for sorting integers array
{
	int i,j;
	for(i=0;i<size-1;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(arr[i]>arr[j])
			{
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}

void float_sort(float arr[],int size)     //function for sorting floating point nuumbers array
{
	int i,j;
	for(i=0;i<size-1;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(arr[i]>arr[j])
			{
				float temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
void string_sort(char arr[][20],int size)   //function for sorting strings array
{
	int i,j;
	char temp[20];
	for(i=0;i<size-1;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(strcmp(arr[i],arr[j])>0)
			{
				strcpy(temp,arr[i]);
				strcpy(arr[i],arr[j]);
				strcpy(arr[j],temp);
			}
		}
	}
}

int main(void)									//main begins here
{
	int size=10;
	int A[size],i,vali,choice;
	float B[size],valf;
	char C[size][20],vals[20];
	FILE *fp;
	fp=fopen("p3_input.txt","r");				//opening p3_input.txt for taking input of arrays
	printf("Input taking begins...\n");
	
	for(i=0;i<size;i++)							//taking input from the file
		fscanf(fp,"%d\t%f\t\t%s\n",&A[i],&B[i],&C[i]);
	printf("Inputs taken successfully.\n\n");
	
	fclose(fp);									//file pointer closed
	printf("Ints\tFloats\t\tWords\n");			//printing the arrays in the terminal
	for(i=0;i<size;i++)
		printf("%d\t%f\t%s\n",A[i],B[i],C[i]);
	printf("\nEnter the integer to be found:"); //taking input from the for the int to be searched
	scanf("%d",&vali);
	int res;
	printf("\nEnter the method to be searched:\n1 for linear search\n2 for binary search\n");//asking user the method to search the array
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		res=int_lsearch(A,size,vali);						//linear searching the integer array
		if(res==-1)
			printf("Number not found!!! :(\n\n");
		else
		printf("Number found at position %d. :)\n",res+1);		
		break;
	case 2:
		int_sort(A,size);									//sorting the array to make it ready for binary search
		res=int_bsearch(0,size-1,A,vali);					//binary searching the integer array
		if(res==-1)
			printf("Number not found!!! :(\n\n");
		else
		printf("Number found at position %d after sorting the array. :)\n",res+1);		
		break;
	default:
		printf("Wrong input!!! X(\n\n");
	}
	
	printf("\nEnter the float number to be found:");//taking input from the for the float to be searched
	scanf("%f",&valf);
	printf("\nEnter the method to be searched:\n1 for linear search\n2 for binary search\n");//asking user the method to search the array
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		res=float_lsearch(B,size,valf);						//linear searching the floating point numbers array
		if(res==-1)
			printf("Number not found!!! :(\n\n");
		else
		printf("Number found at position %d. :)\n",res+1);		
		break;
	case 2:
		float_sort(B,size);									//sorting the array to make it ready for binary search
		res=float_bsearch(0,size-1,B,valf);					//binary searching the floating point number array
		if(res==-1)
			printf("Number not found!!! :(\n\n");
		else
		printf("Number found at position %d after sorting the array. :)\n",res+1);		
		break;
	default:
		printf("Wrong input!!! X(\n\n");
	}
	
	printf("\nEnter the word to be found:");		//taking input from the for the word to be searched
	scanf("%s",&vals);
	printf("\nEnter the method to be searched:\n1 for linear search\n2 for binary search\n");//asking user the method to search the array
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		res=string_lsearch(C,size,vals);			//linear searching the string array
		if(res==-1)
			printf("Word not found!!! :(\n\n");
		else
		printf("Word found at position %d. :)\n",res+1);		
		break;
	case 2:
		string_sort(C,size);						//sorting the array to make it ready for binary search
		res=string_bsearch(0,size-1,C,vals);		//binary searching the string array
		if(res==-1)
			printf("Word not found!!! :(\n\n");
		else
		printf("Word found at position %d after sorting the array. :)\n",res+1);		
		break;
	default:
		printf("Wrong input!!! X(\n\n");
	}
}
