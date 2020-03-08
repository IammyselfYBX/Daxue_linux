#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int sockfa = socket(PF_UNIX,SOCK_DGRAM,0);
	if(sockfa == -1)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_un addr;
	addr.sun_family = PF_UNIX;
	strcpy(addr.sun_path,"a.sock");
	int res = bind(sockfa,(struct sockaddr*)&addr,sizeof(addr));
	if(res == -1)
	{
		perror("bind");
		return -1;
	}
	char buf[100] = {};
	int len = read(sockfa,buf,sizeof(buf));
	if(len == -1)
	{
		perror("read");
		return -1;
	}
	printf("读到%d字节，内容:%s\n",len,buf);
	close(sockfa);
	return 0;
}
