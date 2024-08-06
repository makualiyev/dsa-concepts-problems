/*
    -------------------------
    Topics:
    * Math
    -------------------------
    Constraints:
    -2^31 <= x <= 2^31 - 1
    -------------------------
    Testcases:
    TESTCASE: x = 123                   //  321
    TESTCASE: x = -123                  //  -321
    TESTCASE: x = 120                   //  21
    TESTCASE: x = 0                     //  0
    TESTCASE: x = 1534236469            //  0
    TESTCASE: x = -2147483648           //  0
                                                
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>


int reverse(int x){
    
    int i = 0, init_size = 3;
    int *digits = (int *)malloc(sizeof(int) * init_size);
    long long result = 0;

    while (1)
    {
        if (i >= init_size) {
            init_size = i + 1;
            digits = (int *)realloc(digits, sizeof(int) * init_size);
        }

        digits[i] = x % 10;
        if (x / 10) {
            x = x / 10;
        }
        else if (((x / 10) == 0) && (i < init_size)) {
            init_size = i + 1;
            digits = (int *)realloc(digits, sizeof(int) * init_size);
            break;
        }
        else {
            break;
        }
        i++;
    }

    for (int i = 0; i < init_size; i++) {
        result += digits[i] * (long long)pow(10, init_size - i - 1);
    }

    free(digits);
    if ((result > INT_MAX) || (result < INT_MIN)) {
        return 0;
    }
    return result;
}


int main(int argc, char* argv[])
{
    int testCase = -2147483648;
    int result = reverse(testCase);


    printf("\ntestCase: %d\nresult:\t%d\n", testCase, result);
    return 0;
}
