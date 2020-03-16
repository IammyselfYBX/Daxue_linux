/*
 * 指针类型变量作强制类型转换
 */
#include <stdio.h>
int main()
{
	int num = 300;
	int *p_num = &num;
	printf("p_num是%p,*p_num是%d\n",p_num,*p_num);
	printf("(char*)p_num是%p,*(char*)p_num是%d\n",(char*)p_num,*(char*)p_num);
	return 0;
}
