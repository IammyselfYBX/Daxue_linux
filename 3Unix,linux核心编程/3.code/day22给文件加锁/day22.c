/*
	fcntl函数->文件加锁演示
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd = open ("a.txt",O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return -1;
	}
	struct flock lck;
	//先加锁
	lck.l_type = F_RDLCK;
	lck.l_whence = SEEK_SET;
	lck.l_start = 0;
	lck.l_len = 0;
	lck.l_pid = -1;
	fcntl(fd,F_SETLKW,&lck);

	//在解锁
	lck.l_type = F_UNLCK;
	lck.l_whence = SEEK_SET;
	lck.l_start = 0;
	lck.l_len = 0;
	lck.l_pid = -1;
	fcntl(fd,F_SETLKW,&lck);
	close(fd);
	return 0;
}
