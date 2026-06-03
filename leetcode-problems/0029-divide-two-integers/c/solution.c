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
	if (dividend == INT_MIN) printf("\tDEBUG: INT MIN has been reached\n");
    int isDiff = (dividend ^ divisor) < 0;
    if (dividend < 0) dividend = ~dividend + 1;
    if (divisor < 0) divisor = ~divisor + 1;
    int quotient = 0;

    while (dividend >= divisor) {
        dividend = dividend - divisor;
        quotient++;
    }
	
	int a = 2000;
	int b = 2;
	printf("\tDEBUG: a=%d\tb=%d\ta << b=%d\ta >> b=%d\n", a, b, a << b, a >> b);
	int v = 43;
	printf("\tDEBUG2: v=%d\n", v);
	// v--;
	// printf("\tDEBUG2: v--=%d\n", v);
	v |= v >> 1;
	printf("\tDEBUG2: v|= v >> 1 : %d\n", v);
	v |= v >> 2;
	printf("\tDEBUG2: v|= v >> 2 : %d\n", v);
	v |= v >> 4;
	printf("\tDEBUG2: v|= v >> 4 : %d\n", v);
	v |= v >> 8;
	printf("\tDEBUG2: v|= v >> 8 : %d\n", v);
	v |= v >> 16;
	printf("\tDEBUG2: v|= v >> 16 : %d\n", v);
	// v++;
    // printf("\tDEBUG2: v++ : %d\n", v);
	v = v ^ (v >> 1);
	printf("\tDEBUG2: v ^ ( v >> 1) : %d\n", v);



	if (isDiff)
		return ~quotient + 1;
    return quotient;
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
