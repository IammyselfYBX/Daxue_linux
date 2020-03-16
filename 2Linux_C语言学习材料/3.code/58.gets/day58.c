/*
 *fgets函数演示
 */
#include <stdio.h>
 int main()
 {
	 char buf[10] = {};
	 printf("请输入一个字符串：");
	 fgets(buf,10,stdin);
	 printf("输入的字符串是%s\n",buf);
	 return 0;
 }
