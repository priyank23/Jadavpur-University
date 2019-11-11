#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 

int main()
{
    int msgid=msgget(94,0666 | IPC_CREAT);
    msgctl(msgid,IPC_RMID,NULL);

    return 0;
}