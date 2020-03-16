/*
	条件编译演示
*/
#include <stdio.h>
int main()
{
#ifndef ONE
	printf("执行了1\n");
#else
	printf("执行了2\n");
#endif
	return 0;
}
