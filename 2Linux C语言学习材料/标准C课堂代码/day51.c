/*
 * 指针型参演示
 */
#include <stdio.h>
void swap(int *p_num,int *p_num1)
{
	int tmp = *p_num;
	*p_num = *p_num1;
	*p_num1 = tmp;
}
int main()
{
	int num = 10,num1 = 3;
	printf("num是%d,num1是%d\n",num,num1);
	swap(&num,&num1);
	printf("num是%d,num1是%d\n",num,num1);
	return 0;
}
