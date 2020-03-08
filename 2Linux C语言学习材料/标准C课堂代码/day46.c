/*
 * 指针演示
 */
#include <stdio.h>
int main()
{
	int *p_num = NULL;
	int num = 0;
	p_num = &num;
	*p_num = 10;
	printf("num is %d\n",num);
	return 0;
}
