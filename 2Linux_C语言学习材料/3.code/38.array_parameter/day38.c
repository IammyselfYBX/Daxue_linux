/*
 * 数组形参
 */
#include <stdio.h>
int main()
{
	int arr[10],num = 0;
	void max(int arr[],int num);
	max(arr,6);
	for (num = 0;num <= 5;num++)
	{
		printf("%d\n",arr[num]);
	}
	return 0;
}
void max(int arr[],int num)
{
	int z = 0;
	for (z = 0;z <= 5;z++)
	{
		arr[z] = 9;
	}
}
