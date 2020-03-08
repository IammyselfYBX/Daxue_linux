#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
int semid;
void fa(int signo)
{
	semctl(semid,0,IPC_RMID);
	printf("以删除！");
	exit(0);
}
int main()
{
	signal(2,fa);
	key_t key = ftok(".",100);
	printf("按ctrl+C结束!\n");
	semget(key,1,0666 | IPC_CREAT);
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
	while(1);
	return 0;
}
