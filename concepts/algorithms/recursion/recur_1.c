/**
 * https://www.youtube.com/watch?v=IJDJ0kBx2LM 
 * `Recursion in Programming - Full Course` by @thesimpleengineer
 * first example of reversing string
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * partitions string
 * 0    1   2   3   4
 * p    r   o   v   e
 * len = 5
 * posFrom = 0
 * posTo = 4 (strlen(str) - 1)
 * posTo - posFrom = 4
 */
char* partitionString(char* str, int posFrom, int posTo)
{
    size_t len = strlen(str);

    if (len == 0) {
        return "";
    }
    if ((posFrom > len) || (posTo > len)) {
        printf("Error: one of the indices is out of bounds!\n");
        return "";
    }
    if (posTo - posFrom < 0) {
        printf("Error: second index is out of bounds!\n");
        printf("\tError: str:[%s] posFrom:[%d] posTo:[%d]\n", str, posFrom, posTo);
        char* newStr = (char *)malloc(sizeof(char));
        newStr[0] = '\0';
        return newStr;
    }
    size_t slen = posTo - posFrom + 1;

    char* newStr = (char *)malloc(sizeof(char) * (slen + 1));
    if (newStr == NULL) {
        printf("Fatal Error: cannot allocate memory for a string");
        return NULL;
    }

    for (int i = posFrom; i <= posTo; i++) {
        newStr[i - posFrom] = str[i];
    }
    newStr[slen] = '\0';
    return newStr;
}

char* reverseString(char* str)
{
    /* Base case when an empty string */
    if (strlen(str) == 0) {
        return "";
    }
    /* Recursive case */
    char* result = reverseString(partitionString(str, 1, strlen(str) - 1));
    // char* firstChar = partitionString(str, 0, 0);
    // if (strlen(result) < strlen(firstChar)) {
    //     return strcat(firstChar, result);
    // } else {
    //     return strcat(result, firstChar);
    // }
    char* buffer = (char *)malloc(sizeof(char) * (strlen(result) + 2));
    char* firstChar = partitionString(str, 0, 0);
    buffer = strncpy(buffer, result, strlen(result));
    buffer = strcat(buffer, firstChar);
    return strcat(result, firstChar);
}

int main(int argc, char* argv[])
{
    char ok[] = "prove";
    // char ok[] = "epp";
    // char ok[] = "mississipi";

    char* result = reverseString(ok);
    // char* result = partitionString(ok, 1, 0);
    printf("\t\tresult: %s\n", result);
    free(result);
    return 0;
}
