#include <stdio.h>

int main(int argc, char *argv[]){
    FILE *p_file = fopen("a.txt", "rb");
    if(!p_file){
        printf("File open faile!\n");
        return 0;
    }
    printf("locate point in %ld\n", ftell(p_file));
    fseek(p_file, 4, SEEK_SET);
    printf("locate point in %ld\n", ftell(p_file));
    fclose(p_file);
    rewind(p_file);
    printf("locate point in %ld\n", ftell(p_file));
    p_file=NULL;

    return 0;
}
