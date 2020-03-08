/*
	write演示
*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd = open("write.txt",O_WRONLY | O_CREAT | O_TRUNC,0666);
	if(fd == -1)
	{
		perror("open");
		return -1;
	}
	const char *text = "Hello,World!";
	printf("要写入内容：%s\n",text);
	size_t  towrite = strlen(text) * sizeof(text[0]);//秋字符窜长度
	size_t written = write(fd,text,towrite);
	if (written == -1)
	{
		perror("write");
		return -1;
	}
	printf("希望写入的字节数：%d，实际写入字节数：%d\n",towrite,written);
	close(fd);
	return 0;
}
