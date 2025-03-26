#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE* fptr = fopen("test.txt", "r");
    printf("%zu\n", fptr);

    if (argc > 1) {
        char* option = argv[1];
        char* opton = argv[2];
        printf("\t argc = %d\n", argc);
        if (argv[3] == NULL) {
            printf("argv[3] is NULL\n");
        }
        printf("%s\n", opton);
    }
    return 0;
}