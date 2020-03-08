/*
 * 占位符
 */
#include <stdio.h>
int main()
{
	char ch = 'a';
	printf("ch是%hhd\n",ch);
	printf("%-10d %-10d %-10d\n",123,456,789);
	printf("%010d %010d %010d\n",123,456,789);
	printf("%10.4f\n",123.4567);
	return 0;
}
