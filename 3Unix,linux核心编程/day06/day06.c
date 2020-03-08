/*
	环境表打印演示
*/
#include <stdio.h>
#include <string.h>
int main()
{
	extern char** environ;
	char** p=environ;
	while(*p != NULL)
	{
		printf("%s\n",*p);
		p++;
	}
	p = environ;
	char value[100] = {};
	while(*p)
	{
		if(!strncmp(*p,"PWD",3))
		{
			strcpy(value,*p+4);//以\0结尾
			break;
		}
		p++;
	}
	printf("value=%s\n",value);
	return 0;
}
