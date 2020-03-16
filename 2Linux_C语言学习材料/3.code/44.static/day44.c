/*
 * 静态变量演示
 */
#include <stdio.h>
int f()
{
	static int num = 10;
	printf("num is %d\n",num);
	num = 3;
}
int main()
{
	f();	
	f();
	return 0;
}
