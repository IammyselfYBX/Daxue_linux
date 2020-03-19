/*
	kill函数演示
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void fa(int signo)
{
	printf("进程%d捕获了信号%d\n",getpid(),signo);
}
int main()
{
	signal(SIGINT,fa);
	pid_t pid = fork();
	if(pid == 0)
	{
		while(1);
	}
	printf("父进程PID:%d\n",getpid());
	kill(pid,SIGINT);
	return 0;
}
