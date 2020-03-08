/*
 * 强制类型转换演示
 */
#include <stdio.h>
int main()
{
	int num = 10;
	double num1= 10.2;
	num = num + num1;
	printf("num是%d\n",num);
	printf("num是%lf\n",(double)num);
	return 0;
}
