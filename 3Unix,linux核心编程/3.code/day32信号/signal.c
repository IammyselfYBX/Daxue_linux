#include <stdio.h>
#include <signal.h>

void fa(int signo)//signo就是信号
{
	printf("捕获了信号%d\n",signo);
}
int main()
{
	signal(SIGINT,fa);//把信号2改成自定义处理并打印信号对应数字
	signal(SIGKILL,fa);//把信号9改成默认，信号9是默认的，无视任何修改
	signal(SIGQUIT,SIG_IGN);
	printf("pid=%d\n",getpid());
	while(1);
	return 0;
}
