/*
	fork函数演示
*/
#include <stdio.h>
#include <unistd.h>
int main()
{
	printf("begin\n");
	fork();
	printf("end\n");
	return 0;
}
