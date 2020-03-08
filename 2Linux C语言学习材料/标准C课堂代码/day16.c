/*
 * 复杂逻辑表达式演示
 */
#include <stdio.h>
int main()
{
	int num = 0,num1 = 0;
	int num2 = 0,num3 = 0;
/*	if (num < num2 || num1 > num3)
	{
		printf("执行了if\n");
	}
	else
	{
		printf("执行了else\n");
	}*/
	printf("%d\n",0 && ++num);
	printf("%d\n",1 || 0); //短路特性
	return 0;
}
