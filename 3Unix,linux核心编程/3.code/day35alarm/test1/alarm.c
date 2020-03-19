#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void fa(int signo){
    printf("get singal%d\n", signo);
}

int main(){
    alarm(5);
    while(1);

    return 0;
}
