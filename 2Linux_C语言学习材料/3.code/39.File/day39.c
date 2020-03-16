/*
 * 文件操作
 */
#include <stdio.h>
int main()
{
	int arr[2] = {0,0};
	FILE *p_file = fopen("a.txt","w");
	if (!p_file)
	{
		printf("文件打开失败\n");
		return 0;
	}
	fwrite(arr,sizeof(int),1,p_file);
	fclose(p_file);
	p_file = NULL;
	return 0;
}
