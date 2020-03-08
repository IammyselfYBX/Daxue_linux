/*
 * 生命周期和作用域
 */
#include <stdio.h>
int num = 999;
int main()
{
	int num1 = 888;
	printf("num1这个局部变量的值是%d\n",num1);
	printf("num这个全局变量的值是%d\n",num);
	for(num = 0;num < 1;num++)
	{
		int num2 = 777;
		printf("num2这个块变量是%d\n",num2);
		num = 1;
	}
	return 0;
}
