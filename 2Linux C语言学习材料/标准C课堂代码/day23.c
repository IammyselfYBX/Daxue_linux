/*
 * for循环演示
 */
#include <stdio.h>
int main()
{
	int num = 1,num1 = 2;
	for (num1 = 2;num1 <= 100;num1++)
	{
		num = num + num1;
	}
	printf("计算结果是%d\n",num);
	return 0;
}
