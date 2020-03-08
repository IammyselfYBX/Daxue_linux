/*
 * 编程自动生成一张彩票
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	srand(time(0));
	int arr[7],num = 0;
	for (num = 0;num <= 6;num++)
	{
		arr[num] = 0;
	}
	for (num = 0;num <= 6;num++)
	{
		arr[num] = rand() % 36 + 1;
	}
	for (num = 0;num <= 6;num++)
	{
		printf("%d   ",arr[num]);
	}
	return 0;
}
