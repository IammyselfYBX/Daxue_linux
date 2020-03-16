/*
 *字符串演示
 */
#include <stdio.h>
 int main()
 {
	 char ch[] = "abc";
	 printf("%s\n","abcdef");
	 printf("%p\n","abcdef");
	 printf("%c\n",*"abcdef");
	 printf("ch占用了%d个字节\n",sizeof(ch));
	// *"abcdef" = 'z';错误
	 return 0;
 }
