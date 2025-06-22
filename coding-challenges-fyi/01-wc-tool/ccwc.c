#include <stdio.h>
#include <stdlib.h>

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
        
        FILE* fp;
        char ch;
        int byteCnt = 0;
        int lnCnt = 0;
        int wordCnt = 0;
        int charCnt = 0;

        fp = fopen(filename, "r");
        if (fp == NULL) {
            printf("Can't open %s\n", filename);
            exit(EXIT_FAILURE);
        }

        while ((ch = getc(fp)) != EOF) {
            if (ch == '\n')
                lnCnt++;
            if ((ch == ' ') || (ch == '\t'))
                wordCnt++;
            byteCnt++;
        }
        
        if (argv[1][1] == 'c') {
            printf("%d\t", byteCnt);
        } else if (argv[1][1] == 'l') {
            printf("%d\t", lnCnt);
        } else if (argv[1][1] == 'w') {
            printf("%d\t", wordCnt);
        } else if (argv[1][1] == 'm') {
            printf("%d\t", byteCnt);
        }
        printf("%s\n", filename);

        fclose(fp);
    }
    return 0;
}