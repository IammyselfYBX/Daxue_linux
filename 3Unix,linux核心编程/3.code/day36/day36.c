#include <stdio.h>
#include <signal.h>
int main()
{
	printf("szie=%d\n",sizeof(long long int));
	printf("sigset=%d\n",sizeof(sigset_t));
	return 0;
}
