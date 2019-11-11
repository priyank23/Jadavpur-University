#include "scheduling_algorithm.h"

int main()
{
    JOB jobs[20];
    int len;
    int option,SliceTime;
    while(1)
        {
        printf("\n 1.First Come First Serve\n 2.Non-preemptive priority\n 3.Round Robin\n\nENTER METHOD FOR CPU SCHEDULING: ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                len=input(jobs);
                fcfs(jobs,len);
                break;

            case 2:
                len=input(jobs);
                np_priority(jobs,len);
                break;
            
            case 3:
                len=input(jobs);
                printf("Enter Slice Time: ");
                scanf("%d",&SliceTime);
                RoundRobin(jobs,len,SliceTime);
                break;
            
            case 4:
                printf("Error Input!!!\n");
        }
        char ch='y';
        printf("Do you want to try another method?[Y/n]\n");
        ch=getchar();
        ch=getchar();
        if(ch!='y'&&ch!='Y') break;
    }
    return 0;
}