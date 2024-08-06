/*
    The algorithm for myAtoi(string s) is as follows:

    Whitespace:
        Ignore any leading whitespace (" ").
    Signedness:
        Determine the sign by checking if the next character is '-' or '+', assuming positivity is neither present.
    Conversion:
        Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string
        is reached. If no digits were read, then the result is 0.
    Rounding:
        If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in
        the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be
        rounded to 231 - 1.

    -------------------------
    Topics:
    * String
    -------------------------
    Constraints:
    0 <= s.length <= 200
    s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.
    -------------------------
    Testcases:
    TESTCASE: s = "42"                  //  42
    TESTCASE: s = " -042"               //  -42
    TESTCASE: s = "1337c0d3"            //  1337
    TESTCASE: s = "0-1"                 //  0
    TESTCASE: s = "words and 987"       //  0
    TESTCASE: s = "-91283472332"        //  0 runtime error: signed integer overflow: -2147483648 * 9 cannot be represented in type 'int'

                                                
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


char* stripStr(char* s, int* isMinusSigned)
{
    // strips string to represent just integer
    // string e.g. "4233ff3" -> "4233"

    char* digitsSet = "0123456789";
    int digitsInitSize = 1;
    char* digits = (char*)malloc(sizeof(char) * digitsInitSize);

    // flags
    int isDigitSeen = 0;
    // int _isMinusSigned = 0;

    // counters
    int caret = 0, caretDigit = 0;

    while (1)
    {
        int isCharDigit = 0;

        if (s[caret] == '\0') {
            if (caretDigit >= digitsInitSize) {
                digitsInitSize = caretDigit + 1;
                digits = (char*)realloc(digits, sizeof(char) * digitsInitSize);
                digits[caretDigit] = '\0';
            }
            break;
        }

        for (int j = 0; j < strlen(digitsSet); j++)
        {
            if (digitsSet[j] == s[caret])
            {
                isDigitSeen = 1;
                isCharDigit = 1;

                // printf("caret:%d j:%d char:%c char_num:%d\n", caret, j, s[caret], (int)s[caret] - 48);

                if (caretDigit >= digitsInitSize) {
                    digitsInitSize = caretDigit + 1;
                    digits = (char*)realloc(digits, sizeof(char) * digitsInitSize);
                }
                digits[caretDigit] = s[caret];
                caretDigit += 1;
            }
        }

        if (isCharDigit) {
            caret++;
            continue;
        }
        else {
            if (isDigitSeen) {
                if (caretDigit >= digitsInitSize) {
                    digitsInitSize = caretDigit + 1;
                    digits = (char*)realloc(digits, sizeof(char) * digitsInitSize);
                    digits[caretDigit] = '\0';
                }
                break;
            }
            else {
                if (s[caret] == ' ') {
                    caret++;
                    continue;
                }
                else if (s[caret] == '-') {
                    // isMinusSigned = 1;
                    *isMinusSigned = 1;
                    caret++;
                    continue;
                }
                else {
                    if (caretDigit >= digitsInitSize) {
                        digitsInitSize = caretDigit;
                        digits = (char*)realloc(digits, sizeof(char) * digitsInitSize);
                        digits[caretDigit] = '\0';
                    }
                    else {
                        digits[caretDigit] = '\0';
                    }
                    break;
                }
            }


        }
    }

    // for (int j = 0; j < digitsInitSize; j++) {
    //     printf("DEBUG|j:%d - digits[j]: %c | digitsInitSize %d\n", j, digits[j], digitsInitSize);
    // }
    return digits;
}

int intAtoi(char* s, int* isMinusSigned) {
    int result = 0;

    for (int i = 0; i < strlen(s); i++) {
        int digit = ((int)s[i] - 48);
        result += digit * (int)pow(10, (strlen(s) - i - 1));
    }

    if (*isMinusSigned)
    {
        return (result * (-1));
    }

    return result;
}


int myAtoi(char* s) {
    int result = 0;
    int isMinusSigned = 0;

    char* strippedS = stripStr(s, &isMinusSigned);
    result = intAtoi(strippedS, &isMinusSigned);

    printf("Stripped string: %s\n", strippedS);

    return result;
}

int main(int argc, char* argv[])
{
    char* testCase = "-91283472332";
    int result = myAtoi(testCase);


    // TESTCASE: s = " -042"               //  -42
    // TESTCASE: s = "1337c0d3"            //  1337
    // TESTCASE: s = "0-1"                 //  0
    // TESTCASE: s = "words and 987"       //  0

    printf("\ntestCase: %s\nresult:\t%d\n", testCase, result);
    printf("%d\n", '1');
    return 0;
}
