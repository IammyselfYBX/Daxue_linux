/*
	fork函数演示
*/
#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("begin\n");
	fork();
	printf("end\n");	//因为子进程复制父进程，所以父进程执行，子进程也执行
	return 0;
}
