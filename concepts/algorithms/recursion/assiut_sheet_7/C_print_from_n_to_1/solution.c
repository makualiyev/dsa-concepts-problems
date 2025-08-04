/**
 * Given a number N. Print all numbers from N to 1 separated by a
 * single space.
 */
#include <stdio.h>

void printFromNto1(int count)
{
    if (count == 0) {
        printf("\n");
        return;
    }
    printf("%d%s", count, (count == 1? "": " "));
    count--;
    printFromNto1(count);
}

int main()
{
    int count;
    scanf("%d", &count);
    
    printFromNto1(count);

    return 0;
}