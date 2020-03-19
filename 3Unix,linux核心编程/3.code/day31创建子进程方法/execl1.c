#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    printf("Begining...\n");
    int res = execl("/bin/ls", "ls", "-la", NULL);
    printf("end\n");

    return 0;
}
