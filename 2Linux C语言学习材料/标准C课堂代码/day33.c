/*
 * 麦穗问题
 */
#include <stdio.h>
int main()
{
	int num[10],wol = 0,col = 0;
	for (wol = 0;wol <= 9;wol++)
	{
		printf("请输入一个数字:");
		scanf("%d",&num[wol]);
		printf("\n");
	}
	for (wol = 0;wol <= 9;wol++)
	{
		col = num[wol] > num[wol + 1] ? num[wol] : num[wol + 1];
	}
	printf("最大值是:%d\n",col);
	return 0;
}
