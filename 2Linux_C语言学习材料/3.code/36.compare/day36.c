/*
 * 数字大小比较   使用函数
 */
#include <stdio.h>
int main()
{
	int max = 0,min = 0,col = 0;
	int Fetters(int x,int y);
	printf("请输入两个数字:");
	scanf("%d %d",&max,&min);
	col = Fetters(max,min);
	printf("最大值是%d\n",col);
	return 0;
}
int Fetters(int x,int y)
{
	int z = 0;
	z = x < y ? y:x;
	return z;
}
