#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void fa(int signo)
{
	printf("捕获了信号%d\n",signo);
}
int main()
{
	signal(SIGQUIT,fa);//忽略信号3
	pid_t pid = fork();
	if(pid == 0)
	{
		printf("子进程pid：%d\n",getpid());
		while(1);
	}
	printf("父进程结束\n");
	kill(pid,SIGQUIT);
	return 0;
}
