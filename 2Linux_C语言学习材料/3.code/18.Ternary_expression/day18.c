/*
 * 三目表达式演示
 */
#include <stdio.h>
int main()
{
	int num = 0,num1 = 0;
	printf("请输入两个整数:");
	scanf("%d %d",&num,&num1);
/*	if (num < num1)
	{
		printf("最大值是%d\n",num1);
	}
	else
	{
		printf("最大值是%d\n",num);
	}*/
	num = num < num1 ? num1:num;
	printf("%d\n",num);
	return 0;
}
