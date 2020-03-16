/*
 * void指针实战:接收来源不名的数据地址
 */
#include <stdio.h>
void swap(void *arr,int num)
{
	if(num == 0)
	{
		printf("*arr的值是%d\n",*(int*)arr);
	}
	else if(num == 1)
	{
		printf("*arr的值是%c\n",*(char*)arr);
	}
	else
	{
		printf("*arr的值是%g\n",*(float*)arr);
	}
}
int main()
{
	int number = 999;
	float fnumber = 77.66f;
	char ch = 'h';
	swap(&number,0);
	swap(&ch,1);
	swap(&fnumber,3);
	return 0;
}










