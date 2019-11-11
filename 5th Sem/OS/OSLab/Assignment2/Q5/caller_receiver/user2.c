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
	int fd1,fd; 
	char * myfifo = "./myfifo1"; 
    char* myfifo2 = "./myfifo2";
    if(fork()==0)
    {
        mkfifo(myfifo,0666);
        char str1[BUFFER_SIZE], str2[BUFFER_SIZE]; 
        while (1)
        { 
            fd1 = open(myfifo,O_RDONLY); 
            read(fd1, str1, BUFFER_SIZE);
            if(strcmp(str1,"exit")==0) break; 
            printf("user1:\t%s\n", str1); 
            close(fd1); 
        }
    }
    else
    {
        mkfifo(myfifo2,0666);
        char buffer[BUFFER_SIZE], dummy; 
        while (1)
        { 
            fd = open(myfifo2, O_WRONLY); 
            // printf("Enter Message: ");
            scanf("%[^\n]s",buffer);
            scanf("%c",&dummy); 
            if(strcmp(buffer,"exit")==0) break;
            write(fd, buffer, strlen(buffer)+1); 
            close(fd); 
        }
    }
    wait(NULL);
    return 0; 
} 