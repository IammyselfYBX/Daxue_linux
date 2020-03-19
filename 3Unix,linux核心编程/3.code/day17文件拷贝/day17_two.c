/*
	文件拷贝练习
		在一个循环执行，读一块，写一块
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
int main(int argc,char *argv[])
{
	if (argc < 3)
	{
		printf("用法:%s < 源文件 > < 目标文件 >\n",argv[0]);
		return 0;
	}
	int src = open(argv[1],O_RDONLY);
	if (src == -1)
	{
		perror ("open");
		return -1;
	}
	int dst = open(argv[2],O_WRONLY | O_CREAT | O_EXCL,0666);
	if (dst == -1)
	{
		if (errno != EEXIST)
		{
   			perror ("open");
		}
		printf("文件%s 已存在，是否覆盖？（y/n)",argv[2]);
		char ch = getchar();
		if (ch != 'y' && ch != 'Y')
		{
			return 0;
		}
		if ((dst = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC,0666)) == -1)
		{
			perror ("open");
		}
		char buf[1024];
		ssize_t bytes;
		while ((bytes = read(src,buf,sizeof(buf))) > 0)
		{
			if(write(dst,buf,bytes) == -1)
			{
				perror("write");
				return -1;
			}
			if (bytes == -1)
			{
				perror("read");
				return -1;
			}
		}
		close(dst);
		close(src);
	}
	return 0;
}













