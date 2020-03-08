/*
 * switch分支演示
 */
#include <stdio.h>
int main()
{
	int num = 0;
	printf("请输入一个数字:");
	scanf("%d",&num);
	if (!(num < 4 && num > -1))
	{
		printf("请重新运行程序，因为你输入了超过0-3这个范围的数字!\n");
		return 0;
	}
	if (num == 0)
	{
		printf("春季\n");
	} 
	if (num == 1)
	{
		printf("夏季\n");
	}
	if(num == 2)
	{
		printf("秋季\n");
	}
	if(num == 3)
	{
		printf("冬季\n");
	}
	return 0;
}
