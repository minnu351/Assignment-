#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
 
int main()
{
    pid_t pid,pid1;
    char *message;
    printf("Fork program starting\n");
    pid=fork();
    if(pid==0)
    {
        pid1=fork();
        if(pid1==0)
        {
            printf("Child 3 %d\n",getpid());
        }
        else
        {
            wait();
            printf("Child 2 %d\n",getpid());
            printf("Child 1 %d\n",getpid());
        }
    }
    else
    {
     wait();
        printf("Parent %d\n",getpid());
    }
    exit(0);
}
