#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void fa(int signo){
    printf("get signal %d\n", signo);
}

int main(){
    signal(SIGALRM, fa);
    alarm(1000);
    sleep(3);
    alarm(3);   //实际就等待 6 秒，之前的 alarm(100); 会被取消
    while(1);

    return 0;
}
