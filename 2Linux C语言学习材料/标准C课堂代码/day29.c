/*
 * 数组演示
 */
#include <stdio.h>
int main()
{
	int num[10];
	int arr = 0;
	for (arr = 0;arr <= 9;arr++)
	{
		num[arr] = arr;
	}
	printf("%d\n",num[6]);
	return 0;
}
