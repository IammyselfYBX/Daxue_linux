/*
 * 指针练习题
 */
#include <stdio.h>
int main()
{
	int num = 0,num1 = 0,num2 = 0;
	int *p_num = &num;
	int *p_num1 = &num1;
	int *p_num2 = &num2;
	printf("请输入三个数字:");
	scanf("%d %d %d",&num,&num1,&num2);
	if (*p_num < *p_num1)
	{
		*p_num += *p_num1;
		*p_num1 = *p_num - *p_num1;
		*p_num = *p_num - *p_num1;
	}
	if (*p_num < *p_num2)
	{
		*p_num += *p_num2;	
		*p_num2 = *p_num - *p_num2;
		*p_num = *p_num - *p_num2;
	}
	printf("最大值是:%d\n",*p_num);
	return 0;
}
