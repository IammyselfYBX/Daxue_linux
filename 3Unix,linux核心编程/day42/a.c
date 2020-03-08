#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main()
{
	key_t key = ftok(".",100);
	int semid = semget(key,1,0666 | IPC_CREAT);
	if(semid == -1)
	{
		perror("semget");
		return -1;
	}
	int res = semctl(semid,0,SETVAL,5);
	if(res == -1)
	{
		perror("res");
		return -1;
	}
	printf("成功创建并且初始化！\n");
	return 0;
}
