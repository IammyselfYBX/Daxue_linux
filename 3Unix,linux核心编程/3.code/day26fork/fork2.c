/*
	fork函数演示
*/
#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("begin\n");
	pid_t pid = fork();
	printf("process ID = %d\n",pid);
	//fork函数只有父进程执行一次，fork之之后代码，父子进程都执行一遍（执行了2次）
	//fork函数有两次返回，父同时运行，如果子进程先结束，父进程返回子进程的PID，子进程返回0；

	return 0;
}
