#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	int sockfa = socket(PF_INET,SOCK_DGRAM,0);
	if(sockfa == -1)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_in addr;
	addr.sin_family = PF_INET;
	addr.sin_port = htons(2222);
	addr.sin_addr.s_addr = inet_addr("192.168.1.6");
	int res = connect(sockfa,(struct sockaddr*)&addr,sizeof(addr));
	if(res == -1)
	{
		perror("bind");
		return -1;
	}
	char buf[100] = "达学网校";
	write(sockfa,buf,sizeof(buf));
	close(sockfa);
	return 0;
}
