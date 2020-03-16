/*
 * 浮点型变量演示
 */
#include <stdio.h>
int main()
{
	float a = 12.5;
	double b = 17.67;
	float num = 0.123456789123456789123456789; //27个小数点
	double num1 = 0.123456789123456789123456789;
	double num2 = 10.66;
	printf("a是%f,b是%f\n",a,b);
	printf("a是%g,b是%g\n",a,b);
	printf("num是%.20f,num1是%.20f\n",num,num1);
	printf("num2是%50f\n",num2);
	printf("演示1\n");
	printf("演示2\r演示3\n");
	printf("演示\t演示\t演示\n");
	printf("演示\t演示\t演示\n");
	printf("演示\t演示\t演示\n");
	printf("演示\t演示\t演示\n");
	printf("演示\t演示\t演示\n");
	return 0;
}
