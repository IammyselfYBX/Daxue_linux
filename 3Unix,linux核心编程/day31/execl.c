/*
	execl函数演示
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	printf("begin\n");
	int res = execl("./b.out","./b.out",NULL);
	printf("end\n");
	return 0;
}

