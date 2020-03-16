/*
 * 	整形数据演示
 */
#include <stdio.h>
int main()
{
	short num = 0,num1 = 0;
	unsigned short num2 = 0;
	long int num3 = 0;
	printf("num 是%d\n",num);
	num1 = num - 10;
	printf("num1 是 %d\n",num1);
	printf("num 是%d\n",num);
	num2 = num1;
	//printf("num2是%d\n",num2);这样是错误的，因为无符号类型的不能有符号
	num3 = 100 + 200;
	printf("num3是%d\n",num3);
	return 0;
}
