/*
 * switch分支演示
 */
#include <stdio.h>
int main()
{
	int num = 0;
	printf("请输入一个数字:");
	scanf("%d",&num);
	if (!(num <= 3 && num >= 0))
	{
		printf("请重新执行程序，因为你输入了超过0-3范围的数字\n");
	}
	switch (num)
	{
		case 0:
			printf("春季\n");
			break;
		case 1:
			printf("夏季\n");
			break;
		case 2:
			printf("秋季\n");
			break;
		case 3:
			printf("冬季\n");
			break;
		default:
			break;
	}
	return 0;
}
