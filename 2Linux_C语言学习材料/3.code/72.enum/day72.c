/*
	枚举类型
*/
#include <stdio.h>
int main()
{
	enum{SPR,SUM,AUT,WIN};
	int arr = 0;
	printf("请输入一个数字:\n");
	scanf("%d",&arr);
	if (arr == SUM)
	{
		printf("夏季\n");
	}
	return 0;
}
