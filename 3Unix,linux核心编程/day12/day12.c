/*
	mmap和munmap演示
*/
#include <stdio.h>
#include <sys/mman.h>
int main()
{
	void *p = mmap(0,sizeof(int),PROT_READ | PROT_WRITE,MAP_ANONYMOUS | MAP_PRIVATE,0,0);
	if (p == MAP_FAILED)
	{
		perror("mmap");
		return -1;
	}
	int *pi = p;
	*pi = 100;
	*(pi + 100) = 200;
	printf("%d\n",*(pi + 100));
	munmap(p,sizeof(int));
	return 0;
}
