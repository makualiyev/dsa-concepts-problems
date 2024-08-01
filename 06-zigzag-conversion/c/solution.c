/*
    -------------------------
    Topics:
    * String
    -------------------------
    Constraints:

    1 <= s.length <= 1000
    s consists of English letters (lower-case and upper-case), ',' and '.'
    1 <= numRows <= 1000

    -------------------------
    Testcases:

    TESTCASE: s = "PAYPALISHIRING", numRows = 3             //  "PAHNAPLSIIGYIR"
                                                            //  P   A   H   N
                                                            //  A P L S I I G
                                                            //  Y   I   R

    TESTCASE: s = "PAYPALISHIRING", numRows = 4             //  "PINALSIGYAHRPI"
                                                            //  P     I    N
                                                            //  A   L S  I G
                                                            //  Y A   H R
                                                            //  P     I

    TESTCASE: s = "A", numRows = 1                          //  "A"

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* convert(char* s, int numRows) {
    int size = strlen(s);
    int numCols = 7;
    
    int k = 0;

    for (int i = 0; i < numRows; i++) {
        printf("%c", s[i]);
        for (int j = 0; j < numCols; j++) {
            printf("%c", '0');
        }
        printf("\n");
    }
    

    
    return s;
}

int main(int argc, char* argv[])
{
    int numRows = 3;
    char* testCase = "PAYPALISHIRING";

    char* result = convert(testCase, numRows);
    printf("\nresult: %s\n", result);
    return 0;
}