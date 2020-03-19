/*
	exit函数演示
*/
#include <stdio.h>
#include <stdlib.h>

void fa()
{
	printf("fa被调用了\n");
}
int main()
{
	atexit(fa);
	printf("begin\n");//先打印begin，在打印 fa()
	exit(0);
	printf("end");
}

