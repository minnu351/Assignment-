#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
 
int main()
{
    pid_t pid;
    char *message;
    int n,exit_code;
    printf("Fork program starting\n");
    pid=fork();
    switch(pid)
    {
        case -1:
            perror("Fork faild\n");
            exit(1);
        case 0:
            message="This is the child\n";
            n=20;
            break;
        default:
            message="This is the parent\n";
            n=2;
            break;
    }
    for(;n>0;n--)
    {
        puts(message);
        printf("pid=%d,parent=%d\n",getpid(),getppid());
        sleep(1);
 
    }
    exit(0);
}
