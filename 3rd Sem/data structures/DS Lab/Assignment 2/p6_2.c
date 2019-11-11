/*Program to merge two arrays in a sorted order*/
#include<stdio.h>
void swap(int *x,int *y)                           //function for swapping
{
	int temp=*x;
	*x=*y;
	*y=temp;
}
int partition1(int arr[],int low,int high)        //function to partition an array to be sorted in ascending in two halves
{
	int i=low-1,j;
	int temp=arr[high];
	for(j=low;j<high;j++)
	{
		if(arr[j]<=temp)
		{
			++i;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return i+1;
}

void aquicksort(int arr[],int low,int high)       //function for implementing quick sort for ascending order
{
	if(low<high)
	{
		int p=partition1(arr,low,high);
		aquicksort(arr,low,p-1);
		aquicksort(arr,p+1,high);
	}
}
int partition2(int arr[],int low,int high)       //function to partition an array to be sorted in descending order in two halves
{
	int i=low-1,j;
	int temp=arr[high];
	for( j=low;j<high;j++)
	{
		if(arr[j]>=temp)
		{
			++i;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return i+1;
}

void dquicksort(int arr[],int low,int high)     //function for implementing quick sort for descending order
{
	if(low<high)
	{
		int p=partition2(arr,low,high);
		dquicksort(arr,low,p-1);
		dquicksort(arr,p+1,high);
	}
}
void mergeArray(int a[], int b[], int m, int n,int ch)
{
	int i;
    for (i=n-1; i>=0; i--)
    { 
        int j, end = a[m-1];      /* We find the smallest element>b[i]& shift all
                                    elements one position ahead till smallest greater
                                    element is not found*/                                    
        if(ch==1)               //for ascending order
		{                   
        	for (j=m-2; j >= 0 && a[j] > b[i]; j--)
            	a[j+1] = a[j]; 
                                    // For greater element
        	if (j != m-2 || end > b[i])
        	{
            	a[j+1] = b[i];
            	b[i] = end;
        	}
    	}
    	
    	if(ch==2)               //for descending order
		{                   
        	for (j=m-2; j >= 0 && a[j] < b[i]; j--)
            	a[j+1] = a[j];
                                    // For smaller element
        	if (j != m-2 || end < b[i])
        	{
            	a[j+1] = b[i];
            	b[i] = end;
        	}
    	}
    }
}

int main(void)
{
	int size1,size2,iter,ch;      
	printf("Enter the size of the arrays.\n");   //taking the sizes of the array as input
	scanf("%d%d",&size1,&size2);
	int arr1[size1],arr2[size2];
	printf("Enter the elements of the first array.\n");
	for(iter=0;iter<size1;iter++)				//taking the elements of the array1 as input 
		scanf("%d",&arr1[iter]);
	printf("Enter the elements of the second array.\n");
	for(iter=0;iter<size2;iter++)				//taking the elements of the array2 as input 
		scanf("%d",&arr2[iter]);
	printf("\nIn which order you want to print the merged array?\n1.Ascending\n2.Descending.\n");
	scanf("%d",&ch);                            //asking the user the order of sorting
	switch(ch){
		case 1:aquicksort(arr1,0,size1-1);      //sorting arrays in ascending order
			   aquicksort(arr2,0,size2-1);			   
			   break;
		case 2:dquicksort(arr1,0,size1-1);	    //sorting arrays in descending order
			   dquicksort(arr2,0,size2-1);
			   break;
		default:printf("Invalid Input!!!\n");
				break;	
	}                 //array declaration for storing the resultant
	mergeArray(arr1,arr2,size1,size2,ch);  //calling the function for merging
	printf("\nThe merged array is:\n");
	for(iter=0;iter<size1;iter++)        //printing the final result
		printf("%d\n",arr1[iter]);
	for(iter=0;iter<size2;iter++) 
		printf("%d\n",arr2[iter]);	
}
