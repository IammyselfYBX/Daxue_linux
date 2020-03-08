/*
	read函数演示
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	int fd = open("read.txt",O_RDONLY);
	if(fd == -1)
	{
		perror("open");
		return -1;
	}
	char text[256];
	size_t toread = sizeof(text);
	ssize_t readed = read(fd,text,toread);
	if(readed == -1)
	{
		perror("read");
		return -1;
	}
	printf("希望读取%d字节，世纪读取%d字节\n",toread,readed);
	close(fd);
	return 0;
}
