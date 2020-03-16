/*
 * sizeof演示
 */
#include <stdio.h>
int main()
{
	printf("short类型的变量占用内存%d个字节\n",sizeof(short));
	printf("unsigned short类型的变量占用内存%d个字节\n",sizeof(unsigned short));
	printf("int类型的变量占用内存%d个字节\n",sizeof(int));
	printf("long int类型的变量占用内存%d个字节\n",sizeof(long int));
	printf("unsigned long int类型的变量占用内存%d个字节\n",sizeof(unsigned long int));
	printf("float类型的变量占用内存%d个字节\n",sizeof(float));
	printf("double类型的变量占用内存%d个字节\n",sizeof(double));
	printf("char类型的变量占用内存%d个字节\n",sizeof(char));
	return 0;
}
