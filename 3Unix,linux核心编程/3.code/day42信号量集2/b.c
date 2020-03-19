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
	int i;
	for(i = 0;i < 10;i++)
	{
		pid_t pid = fork();
		if(pid == 0)
		{
			printf("进程%d开始启动，访问共享资源！\n",getpid());
			struct sembuf op;
			op.sem_num = 0;
			op.sem_op = -1;
			op.sem_flg = 0;
			semop(semid,&op,1);
			printf("进程%d释放资源!\n",getpid());
			exit(0);
		}
	}
	semctl(semid,0,IPC_RMID);
	return 0;
}
