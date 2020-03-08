#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
struct Msg
{
	long mtype;
	char buf[50];
};

int main()
{
	key_t key = ftok(".",100);
	int msgid = msgget(key,0);
	if(msgid == -1)
	{
		perror("msgget");
		return -1;
	}
	struct Msg msg;
	int res = msgrcv(msgid,&msg,sizeof(msg),22,0);
	printf("接收了%d字节数据,内容：%s\n",res,msg.buf);
	return 0;
}
