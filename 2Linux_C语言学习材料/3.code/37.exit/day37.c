/*
 * 函数的声明方式以及exit标准函数
 */
#include <stdio.h>
#include <stdlib.h>
void hello()
{
	printf("Hello World\n");
}
int main()
{
	void name();
	hello();
	name();
	return 0;
}
void name()
{
	printf("Hello World\n");
	exit(0);
	printf("Hello World\n");
}
