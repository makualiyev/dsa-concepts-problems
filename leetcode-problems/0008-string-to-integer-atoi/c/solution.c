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
    TESTCASE: s = "-91283472332"        //  -2147483648 runtime error: signed integer overflow: -2147483648 * 9 cannot be represented in type 'int'
    TESTCASE: s = ""
    TESTCASE: s = "-"
    TESTCASE: s = "+1"                  //  1
    TESTCASE: s = "20000000000000000000"
    TESTCASE: s = "  0000000000012345678"
    TESTCASE: s = "  +  413"

                                                
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
    int caret = 0, caretDigit = 0, isCharDigit = 0, prevWasSign = 0, isLeadingZero = 0;

    while (1)
    {
        isCharDigit = 0;

        if (s[caret] == '\0') {
            if (caret == 0) {
                digits = NULL;
                break;
            } 
            if (!isDigitSeen) {
                digits = NULL;
                break;
            }
            if (isLeadingZero) {
                digits = NULL;
                break;
            }

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
                if (isLeadingZero && s[caret] == '0') {
                    isDigitSeen = 1;
                    isLeadingZero = 1;
                    isCharDigit = 1;
                    break;
                }
                if (!isDigitSeen && s[caret] == '0') {
                    isDigitSeen = 1;
                    isLeadingZero = 1;
                    isCharDigit = 1;
                    if (caretDigit >= digitsInitSize) {
                        digitsInitSize = caretDigit + 1;
                        digits = (char*)realloc(digits, sizeof(char) * digitsInitSize);
                    }
                    digits[caretDigit] = s[caret];
                    caretDigit += 1;
                    break;
                }
                isDigitSeen = 1;
                isCharDigit = 1;
                isLeadingZero = 0;

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
            prevWasSign = 0;
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
                    if (prevWasSign) {
                        digits = NULL;
                        break;
                    }
                    prevWasSign = 0;
                    caret++;
                    continue;
                }

                else if (s[caret] == '-') {
                    if (prevWasSign) {
                        digits = NULL;
                        break;
                    }
                    
                    prevWasSign = 1;
                    *isMinusSigned = 1;
                    caret++;
                    continue;
                }
                
                else if (s[caret] == '+') {
                    if (prevWasSign) {
                        digits = NULL;
                        break;
                    }

                    prevWasSign = 1;
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
    return digits;
}

int intAtoi(char* s, int* isMinusSigned) {
    long long result = 0;

    if (strlen(s) > 14)
    {
        // string length greater than 10 e . g. INTMAX
        if (*isMinusSigned) {
            return INT_MIN;
        } else {
            return INT_MAX;
        }
    }

    for (int i = 0; i < strlen(s); i++) {
        int digit = ((int)s[i] - 48);
        result += (long long)digit * (long long)pow(10, (int)(strlen(s) - i - 1));
        printf("\tDEBUG|i:%d digit:%c digit_int:%d pow:%d\tresult:%lld\n", i, s[i], digit, (int)(strlen(s) - i - 1), result);
    }

    if (*isMinusSigned)
    {
        result = (result * (-1LL));
    }

    if (result < INT_MIN) {
        return INT_MIN;
    }
    else if (result > INT_MAX) {
        return INT_MAX;
    } else {
        return (int)result;
    }

}


int myAtoi(char* s) {
    int result = 0;
    int isMinusSigned = 0;
    char* strippedS = stripStr(s, &isMinusSigned);

    if (strippedS == NULL) {
        return 0;
    }

    result = intAtoi(strippedS, &isMinusSigned);
    printf("Stripped string: %s\n", strippedS);
    free(strippedS);
    return result;
}

int main(int argc, char* argv[])
{
    char* testCase = "  +  413";
    int result = myAtoi(testCase);

    printf("\ntestCase: %s\nresult:\t%d\n", testCase, result);
    printf("%d\n", '1');
    return 0;
}
