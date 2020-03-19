/*
	brk和sbrk演示
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main()
{
	void *p = sbrk(0); //取当前位置
	int i =brk(p + 4);
	void *p1 = sbrk(0);
	printf("p+4: %p, i=%d, after p1=%p\n", p, i, p1);

	brk(p + 8);
	p1 = sbrk(0);
	printf("p+8: %p, i=%d, after p1=%p\n", p, i, p1);
	
	brk(p + 4);
	p1 = sbrk(0);
	printf("p+4: %p, i=%d,  after p1=%p\n", p, i, p1);

	int *pi = p;
	*pi = 100;
	double *pd = sbrk(0);
	brk(pd + 1);//
	*pd = 1200.0;
	char *pc = sbrk(0);
	brk(pc + 50);
	//pc = "hello_world";//内存泄露了 -> 只读区
	strcpy(pc,"YBX is the most handsome man in NCEPU");
	printf("%d,%lf,%s\n",*pi,*pd,pc);
	printf("%p,%p,%p\n",pi,pd,pc);
	brk(pc);	//brk释放内存很简单
	brk(pd);
	brk(pi);
	return 0;
}
