#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]){
    FILE *p_file = fopen("aaa.txt", "r");
    if(NULL == p_file)
	{
		printf("strerror: %s\n",strerror(errno));
		perror("perror: fopen");
		printf("printf: %m\n");
	}
	fclose(p_file);
	p_file = NULL;

    return 0;
}