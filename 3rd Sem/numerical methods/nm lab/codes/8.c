/*Program to find inverse of a given matrix*/
#include<stdio.h>
int main()  //main begins here
{
	FILE *fp;
	fp=fopen("8.txt","w");
	fprintf(fp,"   GAUSS JORDAN METHOD FOR FINDING INVERSE OF A MATRIX.\n\n");
    int iter1, iter2, k, order;        		
    printf("Enter order of matrix: ");	
    scanf("%d", &order);				//taking the input for the oder of the matrix
    float matrix[order][order*2], ratio,a;
    printf("Enter the matrix: \n");
    fprintf(fp,"The matrix is:\n\n");
    for(iter1 = 0; iter1 < order; iter1++)	//taking the input for the matrix
    {
        for(iter2 = 0; iter2 < order; iter2++)
        {
            scanf("%f", &matrix[iter1][iter2]);
            fprintf(fp,"%f\t",matrix[iter1][iter2]);
        }
        fprintf(fp,"\n");
    }					
    for(iter1 = 0; iter1 < order; iter1++)		//making an identity matrix
    {
        for(iter2 = order; iter2 < 2*order; iter2++)
        {
            if(iter1==(iter2%order))
                matrix[iter1][iter2] = 1.0;
            else
                matrix[iter1][iter2] = 0.0;
        }
    }
   for(iter2=0; iter2<order; iter2++)
 {
  int temp=iter2;

 /* finding maximum jth column element in last (dimension-j) rows */

  for(iter1=iter2+1; iter1<order; iter1++)
if(matrix[iter1][iter2]>matrix[temp][iter2])
                        temp=iter1;
 /* swapping row which has maximum jth column element */

  if(temp!=iter2)
            for(k=0; k<2*order; k++)
            {
            float temporary=matrix[iter2][k] ;
            matrix[iter2][k]=matrix[temp][k] ;
            matrix[temp][k]=temporary ;
            }

/* performing row operations to form required identity matrix out of the input matrix */

  for(iter1=0; iter1<order; iter1++)
            if(iter1!=iter2)
            {
            ratio=matrix[iter1][iter2];
            for(k=0; k<2*order; k++)
              matrix[iter1][k]-=(matrix[iter2][k]/matrix[iter2][iter2])*ratio ;
            }
            else
            {
            ratio=matrix[iter1][iter2];
            for(k=0; k<2*order; k++)
              matrix[iter1][k]/=ratio ;
            }

 }
           
    fprintf(fp,"\nThe inverse of the given matrix is:\n");
    printf("The inverse matrix is: \n");     //printing the final result
    for(iter1 = 0; iter1 < order; iter1++){
        for(iter2 = order; iter2 < 2*order; iter2++)
        {
            printf("%f\t", matrix[iter1][iter2]);
            fprintf(fp,"%f\t",matrix[iter1][iter2]);
        }
        printf("\n");
        fprintf(fp,"\n");
    }
    fclose(fp);
    return 0;
}
