/**
 * 返回两个数的最大值，如果相等返回错误->2
*/

#include <stdio.h>

int main(){
    int i=0, j=0;
    printf("Please input 2 numbers: ");
    scanf("%d %d", &i , &j);
    if(i != j){
        int max = i>j?i: j;
        printf("The max is %d\n", max);
        return 0;
    }else{
        printf("EQUAL!!!\n");
        return -2;
    }
}
