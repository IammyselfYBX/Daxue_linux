/*
 * 文件拷贝
 */
#include <stdio.h>
int main()
{
	char buf[128] = {};
	int size = 0;
	FILE *p_src = fopen("abc.txt","rb");
	if(!p_src)
	{
		printf("文件打开是失败\n");
		return 0;
	}	
	FILE *p_dest = fopen("def.txt","wb");
	if (!p_dest)
	{
		printf("文件打开失败\n");
		return 0;
	}
	while (size = fread(buf,sizeof(char),128,p_src))
	{
		fwrite(buf,sizeof(char),size,p_dest);
	}
	fclose(p_dest);
	p_dest = NULL;
	fclose(p_src);
	p_src = NULL;
	return 0;
}
