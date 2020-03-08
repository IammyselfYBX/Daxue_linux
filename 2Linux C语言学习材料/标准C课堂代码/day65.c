/*
 *宏命名计算公式演示
 */
#include <stdio.h>
#define PI 3.14f
#define CIRCLE(r) 2 * PI * r
 int main()
 {
	 int num = 0;
	 printf("请输入一个半径:");
	 scanf("%d",&num);
	 printf("周长是%g\n",CIRCLE(num));

	 return 0;
 }
