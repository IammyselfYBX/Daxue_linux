/*
	fork函数演示
*/
#include <stdio.h>
#include <unistd.h>
int main()
{
	printf("begin\n");
	pid_t pid = fork();
	printf("%d\n",pid);
	return 0;
}
