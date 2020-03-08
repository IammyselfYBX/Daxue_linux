/*
 * 十进制转换二进制
 */
#include <stdio.h>
int main()
{
	int num = 0;
	printf("请输入一个数字：");
	scanf("%d",&num);
	printf("%d",num / 128);
	num = num % 128;
	printf("%d",num / 64);
	num = num % 64;
	printf("%d",num / 32);
	num =  num % 32;
	printf("%d",num / 16);
	num = num % 16;
	printf("   %d",num / 8);
	num = num % 8;
	printf("%d",num / 4);
	num = num % 4;
	printf("%d",num / 2);
	num = num % 2;
	printf("%d\n",num / 1);
	num = num % 1;
	return 0;
}
