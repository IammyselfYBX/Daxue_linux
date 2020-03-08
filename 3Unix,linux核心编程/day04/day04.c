/*
	错误处理演示
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int max(int num,int num1,int* pi)
{
	if(num == num1)
	{
		return -1;
		*pi = num > num1 ? num : num1;
	}
}
int ran10()
{
	srand(time(0));
	int ra = rand() % 11;
	if(ra == 0)
	{
		return -1;
	}
	return ra;
}
char* print(char* str)
{
	if(!strcmp(str,"error"))
	{
		return NULL;
	}
	return str;
}
void print1(char* str)
{
	printf("%s\n",str);
}
int main()
{
	int num = 0;
	int r = max(-1,-2,&num);
	if(r == -1)
	{
		printf("出错拉\n");
	}
	else
	{
		printf("r = %d,max = %d\n",r,num);
	}
	r = ran10();
	if(r == -1)
	{
		printf("ran出错\n");
	}
	else
	{
		printf("r = %d\n",r);
	}
	char* s=print("OK");
	if(s == NULL)
	{
		printf("str出错拉\n");
	}
	else
	{
		printf("s = %s\n",s);
	}
	print1("Visual Fetters");
	return 0;
}
