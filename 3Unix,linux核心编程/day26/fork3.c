/*
	fork函数演示
*/
#include <stdio.h>
#include <unistd.h>
int main()
{
	printf("begin\n");
	pid_t pid = fork();
	if(pid == 0)
	{
		printf("子进程\n");
	}
	else
	{
		printf("父进程\n");
	}
	return 0;
}
