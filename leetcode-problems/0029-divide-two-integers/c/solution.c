/*{{{
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
	Input: dividend = 1, divisor = 1		// Output: 1
	Input: dividend = -1, divisor = -1		// Output: 1
    Input: dividend = -2147483648, divisor = 1
	Input: dividend = -2147483648, divisor = -1		// Output: 2147483647
	Input: dividend = -2147483648, divisor = 2		// Output: -1073741824
*//*}}}*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int divide(int dividend, int divisor) {
    long long divd = (long long)dividend;
    long long divr = (long long)divisor;
    int signFlag = (divd < 0) ^ (divr < 0);
    
    if (divd < 0) {
        divd = ~divd + 1LL;
    }
    if (divr < 0) {
        divr = ~divr + 1LL;
    }

    long long rem = divd;
    long long quotient = 0;
    
    // printf("\tDEBUG: divd=%lld\n", divd);
    // printf("\tDEBUG: divr=%lld\n", divr);


    for (int i = 31; i >= 0; i--) {
        if ((divr << i) <= rem) {
            rem -= (divr << i);
            quotient += (1LL << i);
        }
    }
    // printf("\tDEBUG: quotient=%lld\n", quotient);
    // printf("\tDEBUG: sign=%d\n", sign);
    
    if (signFlag) {
        quotient = ~quotient + 1LL;
    }

    
    if (quotient < INT_MIN) {
        return INT_MIN;
    } else if (quotient > INT_MAX) {
        return INT_MAX;
    }

	return (int)quotient;
}

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int dividend = 92;
	int divisor = 7;
    
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
