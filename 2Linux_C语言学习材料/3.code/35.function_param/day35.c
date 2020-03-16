/*
 * 函数参数演示
 */
#include <stdio.h>
int main()
{
	int num = 0;
	int Hello(int x,int y);
	num = Hello(5,5);
	printf("计算结果是:%d\n",num);
	return 0;
}
int Hello(int x,int y)
{
	int z = 0;
	z = x + y;
	return z;
}
