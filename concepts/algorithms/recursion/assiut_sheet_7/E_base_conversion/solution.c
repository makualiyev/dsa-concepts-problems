/**
 * Given a number N. Print the binary equivalent of N.
 * Note: Solve this problem using recursion.
 * Input
 *  First line contains a number T (1 ≤ T ≤ 104) number of test cases.
 *  Next T lines will contain a number N (1 ≤ N ≤ 109).
 * Output
 *  For each test case print a single line contains the answer according to the required above.
 */
#include <stdio.h>

void baseConversion(int number)
{
    if (number == 0) {
        return;
    }
    int remainder = number % 2;
    number = number / 2;
    baseConversion(number);
    printf("%d", remainder);
}

int main()
{
    int count, num;
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        scanf("%d", &num);
        baseConversion(num);
        printf("\n");
    }

    return 0;
}