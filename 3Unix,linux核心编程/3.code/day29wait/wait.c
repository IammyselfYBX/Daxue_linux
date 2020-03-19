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
	printf("准备进入子进程\n");
	printf("--------------------------------\n");
	sleep(1);
	pid_t pid = fork();
	if(pid == 0)//子进程执行的分支)
	{
		printf("子进程pid=%d\n",getpid());
		sleep(1);
		printf("子进程结束\n");
		printf("--------------------------------\n");
		exit(255);	//退出码是0-255
		printf("YBX is the most handsome man in NCEPU");//不执行
	}
	int stat;
	pid_t wpid = wait(&stat);	//获取子进程的 PID
	printf("父进程继续运行了\n");
	printf("结束子进程的PID:%d\n",wpid);
	if(WIFEXITED(stat))
	{
		printf("是正常结束\n");
		printf("退出码：%d\n",WEXITSTATUS(stat));
	}
	return 0;
}
