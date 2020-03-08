/*
 * 输入缓冲区清空演示
 */
#include <stdio.h>
int main()
{
	int num = 0,num1 = 0,a = 0;
	for (num = 0;num <= 5;num++)
	{
		do
		{
			if(a != 0)
			{
				scanf("%*[^\n]");
				scanf("%*c");
			}
			a = 1;	
		}while(!(scanf("%d",&num1)));
		printf("你输入了%d\n",num1);
	}
	return 0;
}
