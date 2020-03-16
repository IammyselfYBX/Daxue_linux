#include <stdio.h>

int main(int argc, char *argv[]){
    char a[10] = {'Y', 'B', 'C', ' ', 'H', 'a', 'n', 'd', '\0'};
    FILE *p_file = fopen("a.txt", "w");
    if(!p_file){
        printf("File open fail");
        return 0;
    }
    fwrite(a, sizeof(char), 7, p_file);
    fclose(p_file);
    p_file = NULL;

    return 0;
}