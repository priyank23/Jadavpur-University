#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include<sys/wait.h>
#define BUFFER_SIZE 1024  
int main() 
{ 
    int fd,fd1; 
    char * myfifo = "./myfifo1";
    char* myfifo2= "./myfifo2";
    mkfifo(myfifo, 0666); 
    if(fork()==0)
    {
        char buffer[BUFFER_SIZE]; 
        while (1)
        { 
            fd = open(myfifo, O_WRONLY); 
            // printf("Enter Message: ");
            scanf("%[^\n]s",buffer);
            getchar();
            if(strcmp(buffer,"exit")==0) break;
            write(fd, buffer, strlen(buffer)+1); 
            close(fd); 
        }
    }
    else
    {
        mkfifo(myfifo2,0666);
        char str1[BUFFER_SIZE], str2[BUFFER_SIZE]; 
    	while (1)
        {
            fd1 = open(myfifo2,O_RDONLY); 
            read(fd1, str1, BUFFER_SIZE); 
            if(strcmp(str1,"exit")==0) break;
            printf("user2:\t%s\n", str1); 
            close(fd1); 
        } 
    }
    wait(NULL);
    return 0; 
}