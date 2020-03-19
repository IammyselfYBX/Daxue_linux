#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int i1 = 10;
int main()
{
	int i2 = 10;//子进程复制的
	char *str = malloc(10);
	strcpy(str,"abcd");
	pid_t pid = fork();
	int i3 = 10;//：父子进程都自己创建的
	if(pid == 0)
	{
		i1 = 20;i2 = 20;i3 = 30;
		str[0] = '1';
		printf("子进程:i1 = %d,i2 = %d,i3 = %d,str =%s\n",i1,i2,i3,str);
		printf("子进程:i1 = %p,i2 = %p,i3 = %p,str =%p\n",&i1,&i2,&i3,str);
		exit(0);//可以用来退出子进程
	}
	sleep(1);
	printf("父进程:i1 = %d,i2 = %d,i3 = %d,str =%s\n",i1,i2,i3,str);
	printf("父进程:i1 = %p,i2 = %p,i3 = %p,str =%p\n",&i1,&i2,&i3,str);
	return 0;	
}
