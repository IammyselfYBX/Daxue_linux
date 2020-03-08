/*
	wait函数演示
*/
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	printf("pid=%d\n",getpid());
	pid_t pid = fork();
	if(pid == 0)//资金从执行的分支)
	{
		printf("子进程pid=%d\n",getpid());
		sleep(1);
		printf("子进程结束\n");
		exit(10);
	}
	int stat;
	pid_t wpid = wait(&stat);
	printf("父进程继续运行了\n");
	printf("结束子进程的PID:%d\n",wpid);
	if(WIFEXITED(stat))
	{
		printf("是正常结束\n");
		printf("退出码：%d\n",WEXITSTATUS(stat));
	}
	return 0;
}
