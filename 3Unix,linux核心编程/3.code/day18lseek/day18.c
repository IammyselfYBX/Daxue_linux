/*
	lseek函数演示
*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
	int fd = open ("seek.txt",O_RDWR | O_CREAT | O_TRUNC,0666);
	if(fd == -1)
	{
		perror("open");
		return -1;
	}
	const char *text = "Hello,World!";
	if (write(fd,text,strlen(text) * sizeof(text[0])) == -1)
	{
		perror ("write");
		return -1;
	}
	if(lseek(fd,-6,SEEK_CUR) == -1)
	{
		perror("lseek");
		return -1;
	}
	text = "Linux";
	if(write(fd,text,strlen(text) * sizeof(text[0])) == -1)
	{
		perror("write");
		return -1;
	}
	close(fd);
	return 0;
}
