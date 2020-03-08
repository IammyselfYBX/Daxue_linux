#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
	key_t key = ftok(".",100);
	int shmid = shmget(key,0,0);
	if(shmid == -1)
	{
		perror("shmid");
		return -1;
	}
	void *p = shmat(shmid,0,0);
	if(p == (void*)-1)
	{
		perror("shmat");
		return -1;
	}	
	int *pi = p;
	printf("*pi=%d\n",*pi);
	shmdt(p);
	shmctl(shmid,IPC_RMID,0);
	return 0;
}
