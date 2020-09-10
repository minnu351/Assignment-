#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
/*
The output in this case is intermixed because of the switch in control of execution b/w child and the parent process.
This is unavoidable. 
The possible solutions be either to make the parent sleep this the child completes execution or use vfork() system call.
*/

int main()
{
    int j=1;
    int pid=fork();
    if(pid==0)
    {
        for(;j<=10;j++)
         printf("Child Process\tChild_cnt= %d\n", j);
         exit(0);
    }
    else 
    {
        for(;j<=10;j++)
         printf("Parent process \tParent_cnt = %d\n", j);

    }
   return 0;
}
