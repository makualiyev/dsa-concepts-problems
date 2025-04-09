#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    printf("METAINFO:\n  argc=%d\n  argv:\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("   %s\n", argv[i]);
    }
    printf("======================\n");

    if (argc == 3) {
        char* option = argv[1];
        char* filename = argv[2];
        FILE* fp = fopen(filename, "r");
    }
    return 0;
}