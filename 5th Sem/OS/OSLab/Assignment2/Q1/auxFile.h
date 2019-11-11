#include"queue.h"

int input(JOB jobs[])
{
    FILE *in;
    in=fopen("job_profile.txt","r");
    int i=0;
    while(fgetc(in)!=EOF)
    {
        fseek(in,-1,SEEK_CUR);
        fscanf(in,"%d %d %d ",&jobs[i].job_id,&jobs[i].priority,&jobs[i].AT);
        jobs[i].actual_AT=jobs[i].AT;
        jobs[i].CT=-1;
        jobs[i].WT=-1;
        jobs[i].TAT=-1;
        int n;
        jobs[i].cpu=-1;
        jobs[i].io=-1;
        jobs[i].pos=0;
        fscanf(in,"%d ",&n);
        int a=0;
        while(n!=-1)
        {
            if(a%2==0)
            {
                // printf("%d %d %d\n",n,a/2,i);
                jobs[i].CPU[a/2]=n;
                jobs[i].cpu=a/2;
                a++;
            }
            else
            {
                // printf("%d %d %d\n",n,a/2,i);
                jobs[i].IO[a/2]=n;
                jobs[i].io=a/2;
                a++;
            }
            fscanf(in,"%d ",&n);
        }
        i++;
    }
    // printf("%d\n",i);
    fclose(in);
    return i;
}

void output(JOB jobs[],int len)
{
    printf("  \tJOB PROFILES\n JOB_ID  PRIORITY   AT\t CPU\tIO\n");
    for(int i=0;i<len;i++)
    {
        int cpuBurst=0,ioBurst=0;
        for(int j=0;j<=jobs[i].cpu;j++)
        {
            cpuBurst+=jobs[i].CPU[j];
        }
        for(int j=0;j<=jobs[i].io;j++)
        {
            ioBurst+=jobs[i].IO[j];
        }
        printf("   %d  \t   %d\t    %d\t  %d\t %d\n",jobs[i].job_id,jobs[i].priority,jobs[i].AT,cpuBurst,ioBurst);
    }
}

void fileOutput(JOB jobs[],int len,int option,int s)
{
    FILE *out=fopen("job_profiles_after_scheduling.txt","a");
    if(option==1)
    fprintf(out,"  \t\t\tJOB PROFILES (FCFS)\n JOB_ID  PRIORITY   AT\t CPU\tIO\tCT\tTAT\tWT\n");
    if(option==2)
    fprintf(out,"  \t\t\tJOB PROFILES (np_priority)\n JOB_ID  PRIORITY   AT\t CPU\tIO\tCT\tTAT\tWT\n");
    if(option==3)
    fprintf(out,"  \t\t\tJOB PROFILES (Round Robin TimeSlice=%d)\n JOB_ID  PRIORITY   AT\t CPU\tIO\tCT\tTAT\tWT\n",s);
    float awt=0.0,atat=0.0;
    for(int i=0;i<len;i++)
    {
        int cpuBurst=0,ioBurst=0;
        for(int j=0;j<=jobs[i].cpu;j++)
        {
            cpuBurst+=jobs[i].CPU[j];
        }
        for(int j=0;j<=jobs[i].io;j++)
        {
            ioBurst+=jobs[i].IO[j];
        }
        jobs[i].TAT=jobs[i].CT - jobs[i].actual_AT;
        jobs[i].WT=jobs[i].TAT-(cpuBurst+ioBurst);
        awt+=jobs[i].WT;
        atat+=jobs[i].TAT;
        fprintf(out,"   %d  \t   %d\t    %d\t  %d\t %d\t%d\t%d\t%d\n",jobs[i].job_id,jobs[i].priority,jobs[i].actual_AT,cpuBurst,ioBurst,jobs[i].CT,jobs[i].TAT,jobs[i].WT);
    }
    awt/=len;
    atat/=len;
    fprintf(out,"\nAverage Waiting Time=%0.2f\nAverage TurnAroundTime=%0.2f\n\n\n",awt,atat);
    printf("\nAverage Waiting Time=%0.2f\nAverage TurnAroundTime=%0.2f\n\n\n",awt,atat);
    fclose(out);
}
void sort(JOB jobs[],int len)   // sort on the basis of arrival time
{
    for(int i=0;i<len-1;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            if(jobs[i].AT>jobs[j].AT)
            {
                JOB temp=jobs[i];
                jobs[i]=jobs[j];
                jobs[j]=temp;
            }
        }
    }
}

void sort2(queue *q)  //sort the queue on the basis of priority
{
    if(empty(q)) return;
    if(q->back==q->front) return;
    for(node* a=q->front;a->next!=NULL;a=a->next)
    {
        for(node* b=a->next;b!=NULL;b=b->next)
        {
            if(a->data.priority>b->data.priority)
            {
                JOB temp=a->data;
                a->data=b->data;
                b->data=temp;

                int i=a->index;
                a->index=b->index;
                b->index=i;
            }
        }
    }/*
    for(node* a=q->front;a!=NULL;a=a->next)
    {
        printf("%d\t",a->index);
    }
    printf("\n");*/
}