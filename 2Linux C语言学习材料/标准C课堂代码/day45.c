/*
 * volatile关键字演示
 */
#include <stdio.h>
int main()
{
	volatile int i = 10;
	int j = i;
	int k = i;
	printf("i is %d,j is %d k is %d\n",i,j,k);
	return 0;
}
