#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    if (argc > 1) {
        char* option = argv[1];
        printf("%s\n", option);
    }
    return 0;
}