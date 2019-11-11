#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int job_id;
    int priority;
    int AT;
    int actual_AT;
    int CT,WT,TAT;
    int CPU[10],IO[10];
    int cpu,io;
    int pos;
}JOB;


typedef struct pair
{
    JOB x;
    int index;
}pair;

typedef struct node
{
    JOB data;
    int index;
    struct node *next;
}node;

typedef struct 
{
    node* front;
    node* back;
}queue;


int empty(queue *q)
{
    if(q->front==NULL) {return 1;}
    return 0;
}

void enqueue(queue *q,JOB data,int i)
{
    node* a=(node*)malloc(sizeof(node));
    a->data=data;
    a->index=i;
    a->next=NULL;
    if(empty(q)){q->front=a;q->back=q->front;}
    else
    {
        q->back->next=a;
        q->back=q->back->next;
    }
}
void clear(queue *q)
{
    node* a=q->front;
    while(a!=NULL)
    {
        node* temp=a;
        temp->next=NULL;
        a=a->next;
        free(temp);
    }
    q->front=NULL;
    q->back=NULL;
}
pair dequeue(queue *q)
{
    pair p;
    node* temp=q->front;
    q->front=q->front->next;
    p.x=temp->data;
    p.index=temp->index;
    temp->next=NULL;
    free(temp);
    return p;
}