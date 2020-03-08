/*
 * 函数递归演示
 */
#include <stdio.h>
int sum(int num)
{
	printf("1\n");
	if (num == 1)
	{
		return 0;
	}
	sum(num-1);
}
int main()
{
	sum(10);
	return 0;
}
