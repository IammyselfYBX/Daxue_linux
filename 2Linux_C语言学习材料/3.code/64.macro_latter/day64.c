/*
 *使用宏编写彩票程序
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
 int main()
 {
	 int arr[SIZE] = {},num = 0;
	 srand(time(0));
	 for(num = 0;num <= SIZE - 1;num++)
	 {
		 arr[num] = rand() % 36 + 1;
	 }
	 for (num = 0;num <= SIZE - 1;num++)
	 {
		 printf("%d  ",arr[num]);
	 }
	 printf("\n");
	 return 0;
 }
