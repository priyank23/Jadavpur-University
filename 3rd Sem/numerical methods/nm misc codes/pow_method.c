#include<stdio.h>
#include<math.h>
void main()
{
    FILE *fp;
    fp=fopen("power_method_res.txt","w");
    int i,j,n,s_no=0;
    float A[40][40],x[40],z[40],e[40],zmax,emax;
    printf("\n Enter the order of matrix:");
    scanf("%d",&n);
    printf("\n Enter matrix elements row-wise: \n");
    fprintf(fp,"Matrix Taken:\n\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            scanf("%f",&A[i][j]);
            fprintf(fp,"%f\t",A[i][j]);
        }
        fprintf(fp,"\n");
    }
    fprintf(fp,"\n\n");
    printf("\n Enter the column vector \n");
    for(i=1; i<=n; i++)
    {
        printf("X[%d]=",i);
        scanf("%f",&x[i]);
    }
    fprintf(fp,"S.No\tX1\t\tx2\t\tx3\t\tC\t\terrormax\n");
    do
    {
        s_no++;
        for(i=1; i<=n; i++)
        {
            z[i]=0;
            for(j=1; j<=n; j++)
            {
                z[i]=z[i]+A[i][j]*x[j];
            }
        }
        zmax=fabs(z[1]);
        for(i=2; i<=n; i++)
        {
            if((fabs(z[i]))>zmax)
                zmax=fabs(z[i]);
        }
        for(i=1; i<=n; i++)
        {
            z[i]=z[i]/zmax;
        }
        for(i=1; i<=n; i++)
        {
            e[i]=0;
            e[i]=fabs((fabs(z[i]))-(fabs(x[i])));
        }
        emax=e[1];
        for(i=2; i<=n; i++)
        {
            if(e[i]>emax)
                emax=e[i];
        }
        fprintf(fp,"%d\t%9.6f\t%9.6f\t%9.6f\t%9.6f\t%9.6f\n",s_no,x[0],x[1],x[2],zmax,emax);
        for(i=1; i<=n; i++)
        {
            x[i]=z[i];
        }
    }
    while(emax>0.001);
    printf("\n The required eigen value is %f",zmax);
    fprintf(fp,"\n The required eigen value is %f\n\n",zmax);
    printf("\n\nThe required eigen vector is :");
    fprintf(fp,"\n\nThe required eigen vector is :\n");
    for(i=1; i<=n; i++)
    {
        printf("%ft \n",z[i]);
        fprintf(fp,"%f\n",z[i]);
    }
}

