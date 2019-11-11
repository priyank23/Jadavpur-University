#include"auxFile.h"

void fcfs(JOB jobs[],int len)
{
    FILE *out=fopen("scheduled_jobs.txt","a");
    queue q;
    q.front=NULL;
    q.back=NULL;
    sort(jobs,len);
    enqueue(&q,jobs[0],0);
    int time=jobs[0].AT;
    fprintf(out,"\nFCFS\nTime\tJob_id\n");
    while(!empty(&q))
    {
        pair a=dequeue(&q);
        JOB p=a.x;
        fprintf(out,"%d\t%d\n",time,p.job_id);
       // printf("%d\t%d\n",time,p.job_id);
        if(p.pos<=p.cpu)
        {
            time+=p.CPU[p.pos];
            if(p.pos<=p.io) p.AT=time+p.IO[p.pos];
            else{ p.AT=__INT32_MAX__; p.CT=time;} 
            p.pos++;
            jobs[0]=p;
        }
        else
        {
            p.AT=__INT32_MAX__;
            p.CT=time;
        }
        sort(jobs,len);
            if(jobs[0].AT<=time) enqueue(&q,jobs[0],0);
    }
    fclose(out);
    fileOutput(jobs,len,1,0);
}

void np_priority(JOB jobs[],int len)
{
    FILE *out=fopen("scheduled_jobs.txt","a");
    queue q;
    q.front=NULL;
    q.back=NULL;
    sort(jobs,len);
    enqueue(&q,jobs[0],0);
    int time=jobs[0].AT;
    fprintf(out,"\nNon-preemptive priority\nTime\tJob_id\n");
    while(!empty(&q))
    {
        pair a=dequeue(&q);
        JOB p=a.x;
        // printf("%d %d\n",p.job_id,a.index);

        // output(jobs,len);
        fprintf(out,"%d\t%d\n",time,p.job_id);
       // printf("%d\t%d\n",time,p.job_id);
        if(p.pos<=p.cpu)
        {
            time+=p.CPU[p.pos];
            if(p.pos<=p.io) p.AT=time+p.IO[p.pos];
            else{ p.AT=__INT32_MAX__; p.CT=time;} 
            p.pos++;
            jobs[a.index]=p;
        }
        else
        {
            p.AT=__INT32_MAX__;
            p.CT=time;
        }

        // printf("Time= %d\n",time);
        clear(&q);
        for(int i=0;i<len;i++)
        {
            if(jobs[i].AT<=time) enqueue(&q,jobs[i],i);
        }
        if(empty(&q))
        {
            int flag=0;
            for(int i=0;i<len;i++)
            {
                if(jobs[i].AT!=__INT32_MAX__)
                {
                    time=jobs[i].AT;
                    enqueue(&q,jobs[i],i);
                }
            }
        }
        sort2(&q);
    }
    fclose(out);
    fileOutput(jobs,len,2,0);
}

void RoundRobin(JOB jobs[],int len,int s_time)
{
    int ct[len];
    FILE *out=fopen("scheduled_jobs.txt","a");
    queue q;
    q.front=NULL;
    q.back=NULL;
    sort(jobs,len);
    enqueue(&q,jobs[0],0);
    int time=jobs[0].AT;
    fprintf(out,"\nRoundRobin(t=%d)\nTime\tJob_id\n",s_time);
    while(!empty(&q))
    {
        pair a=dequeue(&q);
        JOB p=a.x;
        // printf("%d %d\n",p.job_id,a.index);

        // output(jobs,len);
        fprintf(out,"%d\t%d\n",time,p.job_id);
       // printf("%d\t%d\n",time,p.job_id);
        if(p.pos<=p.cpu)
        {
            if(p.CPU[p.pos]>s_time)
            {
                p.CPU[p.pos]-=s_time;
                time+=s_time;
            }
            else
            {
                time+=p.CPU[p.pos];
                if(p.pos<=p.io) p.AT=time+p.IO[p.pos];
                else{ p.AT=__INT32_MAX__; p.CT=time;ct[a.index]=time;} 
                p.pos++;
            }
            jobs[a.index]=p;
        }
        else
        {
            p.AT=__INT32_MAX__;
            p.CT=time;
            ct[a.index]=time;
        }

        // printf("Time= %d\n",time);
        clear(&q);
        // printf("\n");
        for(int i=0;i<len;i++)
        {
            if(jobs[i].AT<=time )enqueue(&q,jobs[i],i);
        }
        if(empty(&q))
        {
            int flag=0;
            for(int i=0;i<len;i++)
            {
                if(jobs[i].AT!=__INT32_MAX__)
                {
                    time=jobs[i].AT;
                    enqueue(&q,jobs[i],i);
                }
            }
        }
        sort2(&q);
    }
    fclose(out);
    len=input(jobs);
    for(int i=0;i<len;i++)
    {
        jobs[i].CT=ct[i];
    }
    fileOutput(jobs,len,3,s_time);
}