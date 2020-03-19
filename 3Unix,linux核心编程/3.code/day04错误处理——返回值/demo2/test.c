/**
 * 返回0-1之间的随机数，如果随机到0，返 1 回错误
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ran10(){
    srand(time(0));
    int ra = rand() % 11;
    if(0 == ra){
        return -1;
    }
}

int main(){
    int i = ran10();
    if(-1 == i){
        printf("ERROR!!!\n");
    }else
    {
        printf("No 0\n");
    }
    

    return 0;
}