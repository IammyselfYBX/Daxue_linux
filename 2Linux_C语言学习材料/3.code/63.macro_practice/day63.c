/*
 *宏演示
 */
#include <stdio.h>
#define PI 3.14f
 int main()
 {
	 int num = 0;
	 printf("请输入半径:");
	 scanf("%d",&num);
	 printf("周长是%g\n",2 * PI  * num);
	 return 0;
 }
