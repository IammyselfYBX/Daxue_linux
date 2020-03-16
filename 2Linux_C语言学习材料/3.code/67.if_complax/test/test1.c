#include <stdio.h>

int main(int argc, char *argv[]){
#ifdef _DEBUG_
    printf("denfine _DEBUG_\n");
#else
    printf("Don't denfine _DEBUG_\n");
#endif

    return 0;
}