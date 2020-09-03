#include<pthread.h>
#include<stdio.h>
int goal=0;
long fib[400];
void *runner(void *param)
{
	if(goal<=0)
		pthread_exit(0);
	fib[0]=0;
	if(goal>1)
	{
		fib[1]=1;
		for(int i=2;i<goal;i++)
			fib[i]=fib[i-1]+fib[i-2];
		pthread_exit(0);
	}
}
int main(int argc, char *argv[])
{
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	printf("Enter the number of fibonacci number series to be printed: ");
	scanf("%d", &goal);
	if(goal>400)
	{
		printf("Printing as many as possible: 400\n");
		goal = 400;
	}
	pthread_create(&tid,&attr,runner,argv[1]);
	pthread_join(tid, NULL);
	if(goal>0)
	{
		printf("%ld", fib[0]);
	}
	for (int i=1;i<goal;i++)
	{
		printf(", %ld", fib[i]);
	}
	printf("\n");
	return 0;
}
