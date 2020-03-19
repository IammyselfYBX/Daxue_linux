/*
	alarm函数演示
*/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void fa(int signo)
{
	printf("捕获了信号%d\n",signo);
}
int main()
{
	signal(SIGALRM,fa);
	int res = alarm(100);
	printf("res=%d\n",res);
	sleep(3);
	res = alarm(5);
	printf("res=%d\n",res);
	while(1);
	return 0;
}
