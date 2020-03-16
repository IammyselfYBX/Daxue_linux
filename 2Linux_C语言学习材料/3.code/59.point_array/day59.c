/*
 *指针数组演示
 */
#include <stdio.h>
 int main()
 {
	 char *ranks[5] = {"100","200","300","400","500"};
	 int num = 0;
	 for(num = 0;num <= 4;num++)
	 {
		 printf("%s\n",ranks[num]);
	 }
	 return 0;
 }
