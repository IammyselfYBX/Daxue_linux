/**
 * 传入一个字符串，如果传入的字符串是'error'，返回错误，
 * 如果不是‘error’ 返回原来的字符串
*/

#include <stdio.h>
#include <string.h>

int cmp(char *a){
    char e[5] = "error";
    if(strcmp(a, e)){
        return 1;
    }else{
        return -1;
    }
    
}

int main(int argc, char *argv[]){
    char a[5]={'\0'};
    printf("Please input string: ");
    fgets(a, 6, stdin);
    if(1 == cmp(a)){
        printf("%s", a);
    }else
    {
        printf("ERROR\n");
    }
    
    return 0;
}