#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	int fa = open("a.pipe",O_RDWR | O_CREAT,0666);
	if(fa == -1)
	{
		perror("open");
		return -1;
	}
	for(int i = 0;i < 100;i++)
	{
		write(fa,&i,sizeof(int));
		sleep(1);
	}
	close(fa);
	return 0;
}
