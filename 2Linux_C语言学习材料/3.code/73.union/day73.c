/*
	联合类型演示
*/
#include <stdio.h>
int main()
{
	typedef union un
	{
		char ch[2];
		int num;
	}un;
	un un1;
	un1.num = 0;
	un1.ch[0] = 'a';
	un1.ch[1] = 'b';
	printf("%x\n",un1.num);
	return 0;
}
