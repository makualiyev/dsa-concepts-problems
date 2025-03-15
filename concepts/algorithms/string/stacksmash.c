#include <stdio.h>

void myfunc(char *const src, int len) {
    int i;
    for (i = 0; i < len; ++i) {
        src[i] = 42;
    }
}

int main(void) {
    char arr[] = {'a', 'b', 'c', 'd'};
    int len = sizeof(arr);
    myfunc(arr, len + 1); /* Cause smashing by writing one byte too many. */
    return 0;
}