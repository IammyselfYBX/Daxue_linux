/*
	access函数演示
*/
#include <stdio.h>
#include <unistd.h>
int main()
{
	if(!access("./test.txt",R_OK))
	{
		printf("可读\n");
	}else
	{
		printf("不可读\n");
	}
	
	if(!access("./test.txt",W_OK))
	{
		printf("可写\n");
	}else
	{
		printf("不可写\n");
	}
	
	if(!access("./tesr.txt",X_OK))
	{
		printf("可执行\n");
	}
	else
	{
		printf("不可执行\n");
	}
	return 0;
}
