#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/mman.h>
void semWait(int *s)
{
    (*s)--;
    while(*s<0);
}
void semSignal(int *s)
{
    (*s)++;
}
int *s;

int main()
{
    void *ptr3=mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,0,0);
    s=ptr3;
    *s=1;
    if(fork()==0)
    {
        for(int i=1;i<=10;i++) 
        {
            semWait(s);
            printf("X - iter-%d\n",i);
           sleep(0.5);
        }
        return 0;
    }
    else
    {
        if(fork()==0)
        {
            for(int i=1;i<=10;i++)
            {
                printf("\tY - iter-%d\n",i);
                sleep(1);
                semSignal(s);
                
            }
            return 0;
        }
    }
    wait(NULL);
    wait(NULL);
    return 0;
}