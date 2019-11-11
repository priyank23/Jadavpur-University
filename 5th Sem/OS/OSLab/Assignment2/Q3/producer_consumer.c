#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<time.h>
typedef struct shared_buffer{
	int arr[25];
	int pid[25];
	int aStart;
	int aEnd;
	int total;
} ShBuf;
void execution(ShBuf *samp,int p,int c){
	pid_t pr=fork();
	if(pr==0){
	for(int i=0;i<p;i++){
		pid_t t1=fork();
		if(t1==0){
			srand(getpid());
			int temp=(rand()%80)+1;
			samp->arr[samp->aEnd%25]=temp;
			samp->pid[samp->aEnd%25]=getpid();
            printf("Producer %d produced : %d\n",samp->aEnd%25,samp->arr[samp->aEnd%25]);
            sleep(1);
			(samp->aEnd)=((samp->aEnd)+1)%25;;
			exit(0);
		}
		else{
			pid_t t;
			int ch;
			do{
				t=wait(&ch);
				}while(t!=t1);
			}	
		}
		exit(0);
	}
	else{
		pid_t co=fork();
		if(co>0){
			pid_t tpid;
			int childs;
            do{
                tpid=wait(&childs);
            }while(tpid != co);
		}
		else{
		for(int i=0;i<c;i++){
				pid_t t2=fork();
				if(t2==0){
					while(samp->arr[samp->aStart]==0);
					samp->total=samp->total+samp->arr[samp->aStart];
					printf("\tValue added%d , aStart :%d\n",samp->arr[samp->aStart],samp->aStart);
					(samp->aStart)=((samp->aStart)+1)%25;;
					
					// printf("Part Total: %d\n",samp->total);
					
					sleep(1);
					exit(0);
				}	
				else{pid_t t;
					int ch;
					do{
						t=wait(&ch);
					}while(t!=t2);
					}
			}
			exit(0);
		}
	}
    while(p--) wait(NULL);
    while(c--) wait(NULL);	
}
int main(int argc,char* argv[]){
	int prod,cons;
	time_t t;
	srand(t);
    if(argc!=3) 
    {
        printf("Wrong execution form!\nPlease use ./a.out [# producers] [# consumers]\n");
        return 0;
    }
    sscanf(argv[1],"%i",&prod);
    sscanf(argv[2],"%i",&cons);
	ShBuf *sample;
	int shmid_samp=shmget(262,sizeof(ShBuf),0666|IPC_CREAT);
	if(shmid_samp==-1){
		perror("Shared Memory");
		return 1;
	}
	
	sample=shmat(shmid_samp,NULL,0);
	if(sample==(void*)-1){
		perror("Shared Memory Attach");
		return 1;
	}
	// printf("%p\n",sample );
	execution(sample,prod,cons);
	// for(int i=0;i<sample->aEnd;i++){
	// 	printf("\nProducer %d: %d",i,sample->arr[i]);
	// 	// printf("\tPid_Producer[%d]: %d",i,sample->pid[i]);
	// }
	printf("\nTotal : %d\n",sample->total);
	shmdt(sample);
	shmctl(shmid_samp,IPC_RMID,NULL);
}