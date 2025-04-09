/**
 * Idioms from C Programming Language, a Modern Approach
 */
#include <stdio.h>
#include <stdlib.h>

size_t my_strlen_1(const char *s)
{
    size_t n;

    for (n = 0; *s != '\0'; s++) {
        n++;
    }
    return n;
}

size_t my_strlen_2(const char *s)
{
    size_t n = 0;

    for (; *s != '\0'; s++) {
        n++;
    }
    return n;
}

size_t my_strlen_3(const char *s)
{
    size_t n = 0;
    while (*s++)
        n++;
    return n;
}

size_t my_strlen_4(const char *s)
{
    const char *p = s;
    while (*s)
        s++;
    return s - p;
}

size_t my_strlen(const char *s)
{
    size_t n = 0;

    while (*s++ != '\0')
        n++;
    return n;
}

char *my_strcat(char *s1, const char *s2)
{
    /**
     * copying a string
     */
    char *p = s1;

    while (*p != '\0'){
        p++;
    }
    while (*s2 != '\0') {
        *p = *s2;
        p++;
        s2++;
    }
    *p = '\0';
    return s1;
}

int main(int argc, char* argv[])
{
    char stringC[15] = "why,";
    char string[] = "ok my man";
    // size_t sizeOfString1 = my_strlen_1(string);
    // size_t sizeOfString2 = my_strlen_2(string);
    // size_t sizeOfString3 = my_strlen_3(string);
    // size_t sizeOfString4 = my_strlen_4(string);
    // size_t sizeOfString = my_strlen(string);
    char* catted = my_strcat(stringC, string);
    
    // printf("size of a string 1 - > %zu \n", sizeOfString1);
    // printf("size of a string 2 - > %zu \n", sizeOfString2);
    // printf("size of a string 3 - > %zu \n", sizeOfString3);
    // printf("size of a string 4 - > %zu \n", sizeOfString4);
    // printf("size of a string 5 - > %zu \n", sizeOfString);
    printf("concatenated string - > %s \n", catted);
    return 0;
}