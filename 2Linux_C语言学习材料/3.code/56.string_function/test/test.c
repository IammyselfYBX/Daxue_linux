#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    char a[]="man in NCEPU!";
    char b[]="YBX is the most hadsome ";
    printf("----strlen-----\n");
    int len = strlen(b);
    printf("The length of b is %d\n", len);

    printf("----------strcat-----------------\n");
    char *c=strcat(b, a);
    printf("Strcat: %s\n", c);

    printf("-----------strcpy------------------\n");
    char d[]="\0";
    char *s = strcpy(d, "ybx is the most briliant man in NCEPU");
    puts(d);
    puts(s);

    printf("--------------strcmp-----------\n");
    int i = strcmp(d, c);
    printf("%d\n", i);

    return 0;
}