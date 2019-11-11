/*Program to apply lin bairstow's mathod*/
#include<stdio.h>
#include<math.h>
#define max 10
int main(void)
{
	FILE *fp;
	fp=fopen("1.txt","w");
	fprintf(fp,"  LIN BAIRSTOW METHOD.\n\n");
	float a[max], b[max], bc[max], bd[max], p, q, r, s, error, errorp, errorq, rq, sq, rp, sp;
	int i, degree, iter=0;
/*accepting the polynomial equation in the following form*/
	printf("\n Enter degree of polynomial?  ");
	scanf("%d",&degree);
	fprintf(fp,"The given equation is:\n");
	for(i=degree; i>=0; i--)
	{
		printf("\n Enter coefficient of x^%d:  ",i);
		if(i<degree)
		{
			scanf("%f",&a[degree-1-i]);
            a[degree-1-i]/=a[degree];
            fprintf(fp,"%f * x^%d ",a[degree-1-i],i);
		}
		else
		{
            scanf("%f",&a[i]);
            fprintf(fp,"%f * x^%d ",a[i],i);
    }
	}
	a[degree]=1;
	printf("\n X^2 + PX + Q \n Enter guesses for P and Q:  ");
	scanf("%f %f",&p,&q);
	error=1;
	while(error>=0.0005)
	{
	/* Beginning of Lin's method */
		for(i=0;i<=degree-3;i++)
			if(i==0)
				b[i]=a[i]-p;
            else if(i==1)
                b[i]=a[i]-p*b[i-1]-q;
            else
                b[i]=a[i]-p*b[i-1]-q*b[i-2];
             /* Modification of Lin's to Bairstow's method */
            r = a[degree-2] - p*b[degree-3] - q*b[degree-4];
            s = a[degree-1] - q*b[degree-3];
            for(i=0; i<=degree-3; i++)
            	if(i==0)
                	bc[i]=-1;
              	else if(i==1)
                    bc[i]=-b[0]+p;
             	else
                    bc[i]=b[i-1]-p*bc[i-1]-q*bc[i-2];
            rp=-b[degree-3]-p*bc[degree-3]-q*bc[degree-4];
            sp=-q*bc[degree-3];
            for(i=0;i<=degree-3;i++)
             	if(i==0)
                	bd[i]=0;
              	else if(i==1)
                   	bd[i]=-1;
              	else
                  	bd[i]=-b[i-2]-p*bd[i-1]-q*bd[i-2];

            rq=-b[degree-4]-p*bd[degree-3]-q*bd[degree-4];
            sq=-b[degree-3]-q*bd[degree-3];

            errorp = (s*rq - r*sq)/(rp*sq - sp*rq);
            p+=errorp;
            errorq = (r*sp - s*rp)/(rp*sq - sp*rq);
            q+=errorq;

           error=errorp>errorq?errorp:errorq;
            iter++;                                                                            /* iteration no. */
	}
 	printf("\n\nA root of the given equation is X^2 + %f*X + %f",p,q);
 	fprintf(fp,"\n\nA root of the given equation is X^2 + %f*X + %f",p,q);
 	fclose(fp);
}
