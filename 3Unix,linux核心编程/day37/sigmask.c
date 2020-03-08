#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void fa(int signo)
{
	printf("捕获了信号%d\n",signo);
}

int main()
{
	signal(SIGINT,fa);
	signal(50,fa);
	printf("pid=%d\n",getpid());
	printf("执行普通代码，不屏蔽信号\n");
	sleep(20);
	printf("执行关键代码,开始屏蔽\n");
	sigset_t new,lod;
	sigemptyset(&new);
	sigemptyset(&lod);
	sigaddset(&new,SIGINT);
	sigaddset(&new,50);
	sigprocmask(SIG_SETMASK,&new,&lod);
	sleep(15);
	printf("代码执行完毕，解除屏蔽\n");
	sigprocmask(SIG_SETMASK,&lod,NULL);
	return 0;
}
