/*
 * void型指针
 */
#include <stdio.h>
int main()
{
	char ch = 'a';
	int num = 99;
	void *p_val = &ch;
	printf("%c\n",*(char*)p_val);
	p_val = &num;
	printf("%d\n",*(int*)p_val);
	return 0;
}
