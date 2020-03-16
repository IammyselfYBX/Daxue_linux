/*
 *用指针作函数
 */
#include <stdio.h>
int max(int num,int num1)
{
	return num > num1 ? num:num1;
}
int *max1(int *p_num,int *p_num1)
{
	return *p_num > *p_num1 ? p_num : p_num1;
}
int main()
{
	int num = 3,num1 = 7;
	int *p_num = max1(&num,&num1);
	printf("p_num是：%d\n",*p_num);
	return 0;
}
