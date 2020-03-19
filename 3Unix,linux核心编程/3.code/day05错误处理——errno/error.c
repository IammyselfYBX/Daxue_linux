/*
	错误处理函数演示
*/
#include <stdio.h>
#include <errno.h>
#include <string.h>
int main()
{
	FILE *p_file = fopen("./abc.txt","w");
	if(p_file == NULL)
	{
		printf("%s\n",strerror(errno));
		perror("fopen");
		printf("%m\n");
	}
	fclose(p_file);
	p_file = NULL;
	return 0;
}
