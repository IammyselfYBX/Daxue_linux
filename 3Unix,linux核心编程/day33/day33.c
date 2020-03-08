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
	if(signal(SIGINT,fa) == SIG_ERR)
	{
		perror("signal 2"),exit(-1);
	}
	signal(SIGQUIT,SIG_IGN);//忽略信号3
	pid_t pid = fork();
	if(pid == 0)
	{
		printf("子进程pid：%d\n",getpid());
		while(1);
		exit(0);
	}
	printf("父进程结束\n");
	return 0;
}
