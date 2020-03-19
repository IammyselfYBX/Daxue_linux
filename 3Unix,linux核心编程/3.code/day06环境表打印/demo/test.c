/*
	环境表打印演示
*/
#include <stdio.h>

int main(int argc, char *argv[]){
    extern char **environ;
    char **p=environ;
    while(*p != NULL)
	{
		printf("%s\n",*p);
		p++;
	}

    return 0;
}
