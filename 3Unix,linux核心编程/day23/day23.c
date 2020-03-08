#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
int main()
{
	struct stat st;
	int res = stat("./day23.c",&st);
	if(res == -1)
	{
		perror("stat");
		return -1;
	}
	printf("size=%d\n",st.st_size);
	printf("size=%d\n",st.st_ino);
	printf("size=%d\n",st.st_nlink);
	return 0;
}
