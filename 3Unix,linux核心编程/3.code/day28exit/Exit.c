/*
	_exit函数演示
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void fa()
{
	printf("fa被调用了\n");
}
int main()
{
	atexit(fa);
	printf("begin\n");
	_exit(0);//不会打印 fa()
	printf("end");
}

