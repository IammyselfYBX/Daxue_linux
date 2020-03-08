/*
	vfrok函数演示
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	pid_t pid = vfork();
	if(pid == 0)
	{//子进程的分支
		sleep(1);
		printf("子进程结束\n");
//		exit(0);
	}
	printf("父进程结束\n");
	return 0;
}
