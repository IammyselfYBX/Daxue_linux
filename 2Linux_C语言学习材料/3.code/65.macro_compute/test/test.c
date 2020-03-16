#include <stdio.h>
#include <stdlib.h>
#define PI 3.14f
#define CIRCLE(r) 2 * PI * r

int main(int argc, char *argv[]){
    printf("Please input num: ");
    char b[2] = {0};
    fgets(b, 2, stdin);
    int num = atoi(b);

    printf("The result is %g\n", CIRCLE(num));

    return 0;
}

