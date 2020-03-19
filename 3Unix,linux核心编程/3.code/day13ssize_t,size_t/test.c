#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int *p = NULL;
#ifdef __x86_64__
    printf("system is x86_64\n");
#elif __i386__
    printf("system is x86");
#endif
    printf("sizeof point = %d\n", sizeof(p));
    printf("size_t = %d\n", sizeof(size_t));
    printf("int = %d\n", sizeof(int));
    printf("unsigned int = %d\n", sizeof(unsigned int));
    printf("long = %d\n", sizeof(long));
    printf("unsigned long = %d\n", sizeof(unsigned long));
    printf("ssize_t = %d\n", sizeof(ssize_t));


    return 0;
}