#include <stdio.h> 
#include <stdlib.h>
#include <semaphore.h> 
#include <unistd.h> 
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
  
sem_t mutex,wrt,*s1,*s2; 
int *a;
int *reader;


void reads(void* arg) 
{ 
    //wait 
    sem_wait(&mutex); 
    *reader++;
    if(*reader>0)
        sem_wait(&wrt);
    sem_post(&mutex);
    printf("The reader is reading the value\n");
    printf("The value of a=%d\n",(*a));
    sleep(1);
    sem_wait(&mutex);
    *reader--;
    if(*reader==0)
        sem_post(&wrt);
    sem_post(&mutex); 
}
void writer(void* arg) 
{ 
    sem_wait(&wrt);
    sem_wait(&mutex);
    printf("The writer is writing into the database\n");
    (*a)++;
    sem_post(&wrt); 
    sem_post(&mutex);
}

void deg()
{
    printf("Debug");
}  

int main() 
{ 
    //deg();
    //printf("Debug");
    //sem_init(mutex,1,1);
    //sem_init(wrt,1,1);
    void* ptr=mmap(NULL,2*sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS,0,0);
    //printf("Debug");
    void* ptr2=mmap(NULL,2*sizeof(sem_t),PROT_READ|PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS,0,0);
    a=ptr;
    *a=0;
    reader=ptr+1;
    *reader=0;
    s1=ptr2;
    s2=ptr2+1;
    mutex=*s1;
    wrt=*s2;
    //printf("Debug");
    if(sem_init(&mutex,1,1)!=0)
        printf("Error");
    if(sem_init(&wrt,1,1)!=0)
        printf("Error");
    pid_t pid[5];
    int a[]={0,1,2,3,4};
     
    if(fork()==0)
    for(int i=0;i<5;i++)
    {
        pid[a[i]]=fork();
        if(pid[a[i]]==0)
        {
            reads(NULL);
            exit(0);
        }
        else if(pid[a[i]]<0)
        {
            printf("Fork Failed");
        } 
    }
    else{
    pid_t pid_wrt=fork();
    if(pid_wrt==0)
        {
            writer(NULL);
            sleep(2);
            exit(0);
        }
    else if(pid_wrt>0)
        {
            wait(NULL);
        }
    else
        {
            printf("Fork Failed");
        }
    
    int status =0;
    for(int i=0;i<5;i++)
    {
        while((pid[i] = waitpid(pid[i], &status, WNOHANG)) != 0)
        {}

    }
    while((pid_wrt = waitpid(pid_wrt, &status, WNOHANG)) != 0)
    {}}
    sem_destroy(&mutex);
    sem_destroy(&wrt);
    return 0; 
}