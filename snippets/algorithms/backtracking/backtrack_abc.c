/* The example from this site : https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/ 
#include <stdio.h>
#include <string.h>

void swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

void permuteRec(char *str, int idx, int n)
{
    if (idx == (n - 1))
    {
        printf("%s\n", str);
        return;
    }

    for (int i = idx; i < n; i++)
    {
        swap(&str[idx], &str[i]);

        permuteRec(str, (idx + 1), n);

        swap(&str[idx], &str[i]);
    }
}

void permute(char *str)
{
    int n = strlen(str);
    permuteRec(str, 0, n);
}

int main(int argc, char *argv[])
{
    char str[] = "ABC";
    permute(str);
    return 0;
}