/*
 * 常量演示
 */
#include <stdio.h>
int main()
{
	int a = 100;
	const int b = 10;
	printf("a的值是：%d,b的值是%d\n",a,b);
//	b = b * 10;错误，因为常量的值不可以被改变
	printf("a的值是：%d,b的值是%d\n",a,b);
	a = a++;
	printf("a的值是：%d\n",a);
	a = ++a;
	printf("a的值是:%d\n",a);
	printf("a的值是%d\n",a--);
	printf("a的值是%d\n",--a);
	printf("10 / 3 余数是： %d\n",10 % 3);
	return 0;
}
