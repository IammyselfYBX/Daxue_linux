/*
	sbrk演示
*/
#include <stdio.h>
#include <unistd.h>

int main()
{
	void *p1 = sbrk(4);
	void *p2 = sbrk(4);
	void *p3 = sbrk(4);
	void *p4 = sbrk(4);
	printf("p1=%p,p2=%p,p3=%p,p4=%p\n",p1,p2,p3,p4);
	sbrk(-4);
	sbrk(-8);
	void *p5 = sbrk(0);
	printf("p5=%p\n",p5);
	return 0;
}
