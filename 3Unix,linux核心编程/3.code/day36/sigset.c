#include <stdio.h>
#include <signal.h>

int main()
{
	printf("size=%d\n",sizeof(sigset_t));
	sigset_t set;
	printf("set=%d\n",set);
	sigemptyset(&set);
	printf("set=%d - 清空后\n",set);
	sigaddset(&set,SIGINT);
	printf("set=%d - 放入信号2\n",set);
	sigaddset(&set,SIGQUIT);
	printf("set=%d - 放入信号3\n",set);
	sigaddset(&set,SIGBUS);
	printf("set=%d - 放入信号7\n",set);
	sigdelset(&set,SIGBUS);//删除信号7
	printf("set=%d - 删除信号7\n",set);
	if(sigismember(&set,2))
	{
		printf("信号2在信号集中\n");
	}
	return 0;
}
