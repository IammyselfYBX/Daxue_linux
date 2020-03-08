#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
	pid_t pid1 = fork();
	pid_t pid2;
	if(pid1> 0)
	{
		pid2 = fork();
	}
	if(pid1==  0)
	{
		printf("pid1=%d\n",getpid());
		sleep(1);
		printf("pid1结束\n");
		exit(10);
	}
	if(pid2 == 0)
	{
		printf("pid2=%d\n",getpid());
		sleep(3);
		printf("pid2结束\n");
		exit(20);
	}
	int stat;
	pid_t wpid = waitpid(-1,&stat,0);
	printf("父进程结束\n");
	return 0;
}
