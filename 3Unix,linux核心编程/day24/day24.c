/*
	access函数演示
*/
#include <stdio.h>
#include <unistd.h>
int main()
{
	if(!access("./a.txt",R_OK))
	{
		printf("可读\n");
	}
	if(!access("./a.txt",W_OK))
	{
		printf("可写\n");
	}
	if(!access("./a.txt",X_OK))
	{
		printf("可执行\n");
	}
	else
	{
		printf("不可执行\n");
	}
	return 0;
}
