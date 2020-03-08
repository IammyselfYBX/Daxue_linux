#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
	key_t key = ftok(".",100);
	int shmid = shmget(key,sizeof(int),0666 | IPC_CREAT | IPC_EXCL);
	if(shmid == -1)
	{
		perror("shmid");
		return -1;
	}
	printf("共享内存创建完毕!\n");
	void *p = shmat(shmid,0,0);
	if(p == (void*)-1)
	{
		perror("shmat");
		return -1;
	}	
	int *pi = p;
	*pi = 100;
	shmdt(p);
	return 0;
}
