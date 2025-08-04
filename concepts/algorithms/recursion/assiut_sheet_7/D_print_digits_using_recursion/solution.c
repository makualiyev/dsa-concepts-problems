/**
 * Given a number N. Print the digits of N separated by a space.
 * 
 * Note: Solve this problem using recursion.
 * 
 * Input
 *  First line contains a number T (1 ≤ T ≤ 10) number of test cases.
 *  Next T lines will contain a number N (0 ≤ N ≤ 109).
 * Output
 *  For each test case print a single line contains the digits of the number separated by space.
 */
#include <stdio.h>

void printDigits(int number, int count)
{
    if (number == 0) {
        // printf("\tcount:%d\n", count);
        return;
    }
    int digit = number % 10;
    number = number / 10;
    count++;
    printDigits(number, count);
    printf("%d %s", digit, (count == 1 ? "\n": ""));
}

int main()
{
    int count, num, pos = 0;
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        scanf("%d", &num);
        printDigits(num, pos);
    }

    return 0;
}