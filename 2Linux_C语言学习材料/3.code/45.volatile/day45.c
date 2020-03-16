/*
 * volatile关键字演示
 */
#include <stdio.h>
int main()
{
	volatile int i = 10;
	int j = i;
	int k = i;
	printf("i is %d\nj is %d \nk is %d\n",i,j,k);
	return 0;
}
