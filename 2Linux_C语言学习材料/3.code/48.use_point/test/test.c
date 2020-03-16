#include <stdio.h>

int main(int argc, char *argv[]){
    int a[10]={0};
    printf("Please input number: ");
    int num = 0;
    char k='\0';
    do{
        scanf("%d",&a[num]);
        num++;
        k=getchar();
    }while(k!='\n'&&num<10);

    printf("The num is %d\n", num);

    return 0;
}