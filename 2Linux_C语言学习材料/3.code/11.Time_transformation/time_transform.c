/**
 * 输入秒数转换
 *   小时：分钟：秒数
*/
#include <stdio.h>

int main(int argc, char *argv[]){
    printf("Please input seconds: ");
    int i = 0;
    scanf("%d", &i);
    int hour = i/3600;
    int min = i/60 - hour*60;
    int sec = i - min*60 - hour*3600;
    printf("The time is %02d:%02d:%02d \n", hour, min, sec);

    return 0;
}