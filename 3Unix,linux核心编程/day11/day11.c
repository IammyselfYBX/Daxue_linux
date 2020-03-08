/*
	brk和sbrk演示
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main()
{
	void *p = sbrk(0);
	brk(p + 4);
	brk(p + 8);
	brk(p + 4);
	int *pi = p;
	*pi = 100;
	double *pd = sbrk(0);
	brk(pd + 1);//
	*pd = 1200.0;
	char *pc = sbrk(0);
	brk(pc + 50);
	//pc = "hello_world";//内存泄露了 -> 只读区
	strcpy(pc,"hello_world");
	printf("%d,%lf,%s\n",*pi,*pd,pc);
	printf("%p,%p,%p\n",pi,pd,pc);
	brk(pc);
	brk(pd);
	brk(pi);
	return 0;
}
