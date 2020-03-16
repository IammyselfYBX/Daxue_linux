/*
	多文件编程演示
*/
#include <stdio.h>
#include "add.h"
extern int res;
int main()
{
	add(99,1);
	printf("%d\n",res);
	return 0;
}
