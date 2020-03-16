/*
 * 时间转换练习
 */
#include <stdio.h>
int main()
{
	int num = 0;
	printf("请输入一个秒数:");
	scanf("%d",&num);
	printf("      : %d\r",num % 60);
	num = num / 60;
	printf("   :%d\r",num % 60);
	printf("%d\n",num / 60);
	return 0;
}
