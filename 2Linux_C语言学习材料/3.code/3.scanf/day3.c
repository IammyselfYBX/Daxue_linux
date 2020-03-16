/*
 * scanf标准函数演示
 */
#include <stdio.h>
int main()
{
	int num = 0,num1 = 0,num2 = 0;
	int arr = 0;
	printf("num的值是%d\n",num);
	printf("请输入一个整数：");
	scanf("%d%d%d",&num,&num1,&num2);
	printf("num的值是%d\n",num);
	printf("num1是%d\n",num1);
	printf("num2是%d\n",num2);
	printf("arr是%d\n",num + num1 + num2);
	return 0;
}
