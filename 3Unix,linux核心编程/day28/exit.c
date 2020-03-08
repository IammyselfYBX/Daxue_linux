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
	printf("begin\n");
	exit(0);
	printf("end");
}

