/*
 * 变量重名演示
 */
#include <stdio.h>
int num;
int main()
{
	printf("num is %d\n",num);
	int num = 1;
	printf("num is %d\n",num);
	{
		printf("num is %d\n",num);
		int num = 2;
		printf("num is %d\n",num);
	}
	printf("num is %d\n",num);
	return 0;
}
