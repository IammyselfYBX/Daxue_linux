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
	int res = connect(sockfa,(struct sockaddr*)&addr,sizeof(addr));
	if(res == -1)
	{
		perror("bind");
		return -1;
	}
	char buf[100] = "达学网校";
	int len = write(sockfa,buf,sizeof(buf));
	if(len == -1)
	{
		perror("read");
		return -1;
	}
	close(sockfa);
	return 0;
}
