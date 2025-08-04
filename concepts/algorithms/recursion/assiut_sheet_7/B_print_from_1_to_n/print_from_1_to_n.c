/**
 * Given a number N. Print numbers from 1 to N in separate lines.
 */
#include <stdio.h>

void printFrom1ToN(int target, int count);

int main(int argc, char *argv[])
{
	int count;
	scanf("%d", &count);
	printFrom1ToN(count, 1);
	return 0;
}

void printFrom1ToN(int target, int count)
{
    if (count > target) {
        return;
    }
    printf("%d\n", count);
    count++;
    printFrom1ToN(target, count);
}