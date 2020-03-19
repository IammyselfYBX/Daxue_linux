/*
	fcntl函数 -> 文件状态操作演示
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
void pflags(int flags)
{
	printf("文件状态标志:");
	struct
	{
		int flag;
		const char *desc;
	}flist[] = {
		{O_RDONLY,"O_RDONLY"},
		{O_WRONLY,"O_WRONLY"},
		{O_RDWR,"O_RDWR"},
		{O_APPEND,"O_APPENG"},
		{O_CREAT,"O_CREAT"},
		{O_EXCL,"O_EXCL"},
		{O_TRUNC,"O_TRUNC"}
	};
	size_t i;

	for(i = 0;i < sizeof(flist) / sizeof(flist[0]);++i)
	{
		if(flags & flist[i].flag)
		{
			printf("%s ",flist[i].desc);
		}
	}
	printf("\n");
}
int main()
{
	int fd = open("flags.txt",O_WRONLY | O_CREAT | O_TRUNC,0666);
	if(fd == -1)
	{
		perror("open");
		return -1;
	}
	int flags = fcntl(fd, F_GETFL);			//F_GETFL 获取文件状态标志位
	if(flags == -1)
	{
		perror("fcntl");
		return -1;
	}
	//文件状态标志 
	pflags(flags);
	printf("----------------------------------\n");
	printf("Change flages O_APPEND \n");
	if(fcntl(fd,F_SETFL,O_APPEND) == -1)	//F_SETFL 设置文件状态标志位， 使用非常有限，只能够追加两位，一个是O_APPEND,O_NOBLOCK
	{
		perror("fcnt;");
		return -1;
	}
	flags = fcntl(fd,F_GETFL);
	if(flags == -1)
	{
		perror("fcntl");
		return -1;
	}
	pflags(flags);
	close(fd);
	return 0;
}
