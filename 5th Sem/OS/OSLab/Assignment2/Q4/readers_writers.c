#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>
#include <semaphore.h>

#define iter 2

int *readCount, *crit_sec, *writeCount;
sem_t wrt, mutex, *s1, *s2;

void writer (int numWriter) {

    sem_wait(&wrt);
    *writeCount++;
    if(*writeCount==1) sem_wait(&mutex);
   // sem_post(&wrt);
   
    *crit_sec = numWriter;
    // sleep(1);
    printf("Writer %d - Wrote: %d\n", numWriter, numWriter);
    
    sem_post(&wrt);
    sem_wait(&mutex);
    *writeCount--;
    if(*writeCount==0) sem_post(&mutex);
    return;
}

void reader (int numReader) {
    sem_wait(&mutex);
    *readCount++;
    if(*readCount==1) sem_wait(&wrt);
    sem_post(&mutex);
    printf("Reader %d - Read: %d\n", numReader, *crit_sec);
    sem_wait(&mutex);
    *readCount--;
    if(*readCount==0) sem_post(&wrt);
    sem_post(&mutex);
    return;

}

int main (int argv, char **argc) {
    int numRead, numWrite;
    void *ptr1 = mmap(NULL, 3*sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, 0, 0);
    void *ptr2 = mmap(NULL, 2*sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, 0, 0);
    crit_sec=ptr1, readCount=ptr1+1, writeCount=ptr1+2;
    *crit_sec=0, *readCount=0,*writeCount=0;

    s1=ptr2, s2=ptr2+1;
    *s1=mutex, *s2=wrt;
    sem_init(&mutex,1,1);
    sem_init(&wrt,1,1);

    if (argv !=3) 
    {
        printf("Incorrect usage - must use: ./a.out [# readers] [# writers]\n");
        return 0;
    }
    if (sscanf (argc[1], "%i", &numRead)!=1|| sscanf (argc[2], "%i", &numWrite)!=1) 
    {
        printf("Incorrect usage - must use: ./a.out [# readers] [# writers]\n");
        return 0;
    }

    int rcnt = 0,wcnt=0;
    
    if(fork()==0)
    {
        while(rcnt++<numRead)
        {
            if(fork()==0)
            {
                int i=0;
                for(;i<iter;i++) {reader(rcnt); 
                sleep(0.1);
                }
                return 0;
            }
        }
    }

    else
    {
        while(wcnt++<numWrite)
        {
            if(fork()==0)
            {
                int i=0;
                for(;i<iter;i++) {
                    writer(wcnt);
                    sleep(1);
                    }
                return 0;
            }
        }
    }
    while(rcnt--)  wait(NULL);
    while(wcnt--) wait(NULL);
    /*
    while (numWrite>numRead?(wcnt<numWrite):(rcnt<numRead)) 
    {
        if (rcnt++<numRead) 
        {
            if(fork()==0){
            int i=0;        
            for(;i<iter;i++){ reader(rcnt);}
            return 0;}
        }
        else if(wcnt++<numWrite) 
        {
            if(fork()==0)
            {
            int j=0;
            for (;j<iter;j++){ writer(wcnt);}
            return 0;
            }  
        }
    } */

    // int wcnt = 0;
    // while (wcnt++ < numWrite) 
    // {
    //     if (fork()==0) 
    //     {
    //         int j=0;
    //         for (;j<iter;j++){ writer(wcnt);}
    //         return 0;  
    //     }
    // }
    return 0;
}
