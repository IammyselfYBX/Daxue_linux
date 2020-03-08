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
	int i; 
	for(i = 0;i < 100;i++)
	{
		int x;
		read(fa,&x,sizeof(int));
		printf("x=%d\n",x);
	}
	close(fa);
	return 0;
}
