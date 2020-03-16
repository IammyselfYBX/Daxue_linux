/*
 * 逗号操作符演示
 */
#include <stdio.h>
int main()
{
	int num = 0;
	num =( 4 + 7,8 - 6);
	printf("%d\n",(8 + 2,6 - 3));
	printf("%d\n",num);
	num = 10;
	printf("%d\n",num);
	num +=10;
	printf("%d\n",num);
	num *= 2 + 3;
	printf("%d\n",num);
	return 0;
}
