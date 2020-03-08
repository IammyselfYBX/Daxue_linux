#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{
	key_t key = ftok(".",200);
	int msgid = msgget(key,0);
	if(msgid == -1)
	{
		perror("msgget");
		return -1;
	}
	printf("消息队列创建/获取成功\n");
	char buf[50] = {};
	int res = msgrcv(msgid,buf,sizeof(buf),0,0);
	if(res == -1)
	{
		perror("msgrcv");
		return -1;
	}
	printf("收到了%d字节的数据，内容：%s\n",res,buf);
	msgctl(msgid,IPC_RMID,0);
	return 0;
}
