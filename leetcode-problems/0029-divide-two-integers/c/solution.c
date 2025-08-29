/*
    -------------------------
    Topics:
    * Math
    * Bit Manipulation
    -------------------------
    Constraints:
    -2^31 <= dividend, divisor <= 2^31 - 1
    divisor != 0
    -------------------------
    Testcases:
    Input: dividend = 10, divisor = 3       // Output: 3
                                            // Explanation:
                                                10/3 = 3.33333.. which is truncated to 3.
    Input: dividend = 7, divisor = -3       // Output: -2
                                            // Explanation:
                                                7/-3 = -2.33333.. which is truncated to -2.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int divide(int dividend, int divisor) {
    return 0;
}

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int dividend = 10;
    int divisor = 3;
    
    clock_t start = clock();
    printf("======================\n");
    printf("testCase: \n");
    printf("\tdividend:%d\tdivisor:%d\n", dividend, divisor);

    int result = divide(dividend, divisor);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    
    printf("======================\n");
    printf("result:\n");
    printf("\tquotient = %d\n", result);

    printf("\nTime elapsed: %.4f\n", seconds);
    return 0;
}
