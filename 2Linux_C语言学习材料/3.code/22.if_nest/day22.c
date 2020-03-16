/*
 * if分支另一种使用方式   嵌套
 */
#include <stdio.h>
int main()
{
	int num = 9,num1 = 10;
	if (num < num1)
	{
		printf("执行了if，因为num比num1小\n");
		if (num == 9)
		{
			if(num1 == 10)
			{
				printf("num1是等于10 \n");
			}
			printf("num等于9\n");
		}
		if (num1 != 10)
		{
			printf("num1不等于10\n");
		}
		else
		{
			printf("num不等于10是错误的!\n");
		}
	}
	return 0;
}
