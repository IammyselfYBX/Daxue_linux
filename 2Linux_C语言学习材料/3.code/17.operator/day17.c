/*
 * 位运算符演示
 */
#include <stdio.h>
int main()
{
	printf("%d\n",3 & 5);
	printf("%d\n",3 | 5);
	printf("%d\n",3 ^ 5);
	printf("~0x83是%hhx\n",~0x83);
	printf("%d\n",3 << 2);
	return 0;
}
