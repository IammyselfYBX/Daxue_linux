#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{
	key_t key = ftok(".",200);
	int msgid = msgget(key,0666 | IPC_CREAT);
	if(msgid == -1)
	{
		perror("msgget");
		return -1;
	}
	printf("消息队列创建/获取成功\n");
	int res = msgsnd(msgid,"hello",5,0);
	if(res == -1)
	{
		perror("msgsnd");
		return -1;
	}
	printf("send OK\n");
	return 0;
}
