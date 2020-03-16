#include <stdio.h>
int max(int *a, int *b, int *c){
    int max = *a>*b?*a:*b;
    max = max>*c?max:*c;
    return max;
}

int main(int argc, char *argv[]){
    int a, b, c;
    printf("Please input 3 numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    int max_num = max(&a, &b, &c);
    printf("The max number is %d\n", max_num);

    return 0;
}