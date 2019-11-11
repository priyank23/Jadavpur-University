/*Program for applying least square method of curve fitting*/
#include<stdio.h>
#include<math.h>
int main()  //main begins here
{
 	FILE *fp;   //file pointer declared
 	fp=fopen("12.txt","w");  //file opened
 	fprintf(fp,"     Linear Curve fitting using least square method\n\n");
    int n,i, x[20],y[20],sumx=0,sumy=0,sumxy=0,sumx2=0;   //variables declared
    float a,b;
    printf("\n Enter the value of number of terms n:");  //scanning begins from here
    scanf("%d",&n);
    printf("\n Enter the values of x:\n");
    for(i=0;i<=n-1;i++)
    {
        scanf(" %d",&x[i]);
 
    }
    printf("\n Enter the values of y:");
    fprintf(fp,"Given inputs are:\n");
    for(i=0;i<=n-1;i++)
    {
        scanf("%d",&y[i]);
        fprintf(fp," f(%d)=%d\n",x[i],y[i]);
    }
    for(i=0;i<=n-1;i++)    //calculation of the function
    {
        sumx=sumx +x[i];
        sumx2=sumx2 +x[i]*x[i];
        sumy=sumy +y[i];
        sumxy=sumxy +x[i]*y[i];
 
    }
    a=((sumx2*sumy -sumx*sumxy)*1.0/(n*sumx2-sumx*sumx)*1.0);   //final sum calculated
    b=((n*sumxy-sumx*sumy)*1.0/(n*sumx2-sumx*sumx)*1.0);
    printf("\n\nThe line is Y=%3.3fx +%3.3f \n",b,a);   //final result being printed here
    fprintf(fp,"\n\nThe line is Y=%3.3fx +%3.3f \n",b,a);  
    fclose(fp);
    return 0;
}
