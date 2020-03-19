/*
	malloc深入讲解
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,b,c;//系统自动分配和回收（栈区）
	printf("a=%p, b=%p, c=%p\n",&a,&b,&c);
	int *p1 = malloc(4);
	int *p2 = malloc(4);
	int *p3 = malloc(4);
	printf("p1=%p, p2=%p, p3=%p\n",&p1,&p2,&p3);
	free(p1);
	free(p2);
	free(p3);
	return 0;
}
