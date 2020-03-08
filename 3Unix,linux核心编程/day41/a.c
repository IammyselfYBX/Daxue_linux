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
	int msgid = msgget(key,IPC_CREAT | 0666);
	if(msgid == -1)
	{
		perror("msgget");
		return -1;
	}
	struct Msg msg1,msg2;
	msg1.mtype = 1;
	strcpy(msg1.buf,"达学网校");
	msg2.mtype = 2;
	strcpy(msg2.buf,"编程课堂");
	msgsnd(msgid,&msg1,sizeof(msg1),0);
	msgsnd(msgid,&msg2,sizeof(msg2),0);

	return 0;
}
