/*
 *字符串函数演示
 */
#include <stdio.h>
#include <string.h>
 int main()
 {
	 char ch[] = "abcdef";
	 char buf[20] = "abc";
	 printf("ch的有效字符一共有%d个\n",strlen(ch));
	 printf("合并后的结果是%s\n",strcat(buf,ch));
	 printf("复制后的字符串是%s\n",strcpy(buf,"qazwsxedc"));
	 printf("比较后的结果是:%d\n",strcmp("poiuytrewq","zxcvbnm"));
	 return 0;
 }
