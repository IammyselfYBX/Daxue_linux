#include <stdio.h>
#include <errno.h>
#include <string.h>
int main()
{
	FILE *p_file = fopen("./abc.txt","r");
	if(p_file == NULL)
	{
		printf("%m\n");
	}
	return 0;
}
