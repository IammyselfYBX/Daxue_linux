#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    char a[50] = {'0'};
    FILE *p_file = fopen("test1.txt", "r");
    if(!p_file){
        printf("File open fail");
        return 0;
    }
    int size = fread(a, sizeof(char), 50, p_file);
    printf("size = %d\n", size);
    printf("Reading ...\n");
    printf("----------------------\n");
    printf("Writing ...\n");
    FILE *p_file1 = fopen("test_copy.txt", "w");
    if(!p_file1){
        printf("File open fail");
        return 0;
    }

    char b[]="I am copy \n";
    fwrite(b , sizeof(char), strlen(b), p_file1);
    fwrite(a, sizeof(char), size, p_file1);
    fclose(p_file);
    p_file1 = NULL;
    p_file = NULL;
    printf("----------------------------\n");
    printf("Finished \n");

    return 0;
}