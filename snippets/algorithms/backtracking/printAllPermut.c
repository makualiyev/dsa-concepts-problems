#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap(char* x, char* y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void permuteRec(char* str, int idx, int n) {
    // Base case
    if (idx == n - 1) {
        printf("%s\n", str);
        return;
    }

    for (int i = idx; i < n; i++) {
        // Swapping
        swap(&str[idx], &str[i]);

        // First idx + 1 characters fixed
        permuteRec(str, idx + 1, n);

        // Backtrack
        swap(&str[idx], &str[i]);
    }
}

void permute(char* str) {
    int n = strlen(str);
    permuteRec(str, 0, n);
}

int main(int argc, char *argv[])
{
    char str[] = "abcdef";
    permute(str);
    return 0;
}