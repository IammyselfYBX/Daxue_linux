#include <stdio.h>

int main(int argc, char *argv[]){
    printf("Please input some number: ");
    int a[10]={0};
    char k = '\0';
    int num = 0;
    do{
        scanf("%d", &a[num]);
        k = getchar();
        num++;
    }while(k!='\n' && num <10);

    //从小到大
    int tmp = 0;
    for(int i=0; i<num; i++){
        for(int j = 0; j<i; j++){
            if(a[j]>a[i]){
                tmp = a[j];
                a[j]=a[i];
                a[i]=tmp;
            }
        }
    }

    printf("Sort: ");
    for(int i = 0; i<num; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}