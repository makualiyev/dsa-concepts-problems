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
    TESTCASE: s = "AB", numRows = 1                         //  "AB"
    TESTCASE: s = "AB", numRows = 2                         //  "AB"
    TESTCASE: s = "orfefwofihmozumjkgeilldtosfnorocltisrxxbelrdhdormtaxeftuxyhosxsdtbxkyuoehfkolyfxthwympskqcaibsnutkhtevylciznigkcohccywooaoychlycvfwbcuofepuowfqmouoordfttdvapudkbzmgvclzsfpomiaccqtvvyppdmrsiufkvtqqvdrnkjbzrddtwwrtwiiaucsdwzpushmomgdyphxgmdbibucycmyxoscnutjmcvcqdgoupocbremuaqsdcsctneihzrvboyrsghmvvpyovkjvadadwcylggshzninnbhvjusglrvibgdejgjfihqrpkyoajdpkllvhfeswzaahfeqlnyuwqnlblbdwesjpdewjiohjqjqynjlchhyxulagmdcrwlgbsfmcvwomfgmtpxxyfywzjyhycmpyxxbrcowakkmpqakixkgciectdjrhvghvgiokykkkuycnymvwydagicanorwladiilxsmhfwedytenocltcsdfusvnognrrvfoqrxvpdyowedmgoijilqeelsstfmkdtatkaobforctuqbjyktmayqnqkhxytarwvdyjfdawhvrywcyhxkjvcxnpglnbnfxjkxspbuoiphimjhvgteewbrnhcajqhibugtjjqzrfgctploygteewvrgaupsbztxhohqegkmpmfezuefpiklgbrgviazktwrjfiooucdihjhdqosayegcxozgoaqjzjtgtjunlzvuleydvqdtwkxuazcpzuaafthzedorfmmqqktlcyhbigvjfzahvahawozcsouxaipsukgwipztvuebvgiqgpregqhagdzilobfajdiyddtzhwvpgnwyecexlgfofozvrgvamfarlvsuspkydiyjkegwkokpcmkvuhvipvzaquwkjglmojyzogxyuhqwvctsmoadlcfewbqfibuwnuxdaudvevtbyntmdup"
    numrows = 620
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


long scanZigzag(char* s, int numRows)
{
    // prints zigzag in console
    int size = strlen(s);

    // it's basically a row without the first
    // and the last element
    int rowShift = (numRows > 2) ? numRows - 2: 0;

    long i = 0, x = 0;
    int isSliding = 0;

    while (1)
    {
        if (i >= size) break;
    
        if (isSliding) {

            // sliding loop 
            // 0    1   2   3 -- j
            //
            // P    A   Y   P
            // *    P   *   * 
            // *    *   A   *
            // *    L   A   P --- implement sliding
            //
            for (int shiftPos = 0, k = 0; shiftPos < rowShift; shiftPos++)
            {
                
                for (int j = 0; j < numRows; j++)
                {
                    if ((j == (numRows - 2 - shiftPos)) && ((i + k) < size))
                    {
                        printf("%c\t", s[i+k]);
                        k++;
                        continue;
                    }
                    else {
                            printf("*\t");
                        }

                }
                printf("\n");
            }
            
            
            isSliding = 0;
            i += rowShift;
            x += numRows * rowShift;
        }    
        else {
            for (int j = 0; j < numRows; j++)
                {
                    if ((i + j) < size)
                    {
                        printf("%c\t", s[i + j]);
                        continue;
                    } else {
                        printf("*\t");
                    }
                }
                printf("\n");
                isSliding = 1;
                i += numRows;
                x += numRows;
        }
        
    }

    printf("-------------------------------\n");
    printf("func:scanZigzag: x:%ld\ti:%ld\n", x, i);
    return (x / numRows);
}

void fill2dArr(char* s, char* charArr, int numRows)
{
    int size = strlen(s);
    int rowShift = (numRows > 2) ? numRows - 2: 0;
    
    long i = 0, x = 0;
    int isSliding = 0;

    while (1)
    {
        if (i >= size) {
            charArr[x] = '\0';
            break;
        }
    
        if (isSliding) {
           for (int shiftPos = 0, k = 0; shiftPos < rowShift; shiftPos++)
            {
                for (int j = 0; j < numRows; j++)
                {
                    if ((j == (numRows - 2 - shiftPos)) && ((i + k) < size))
                    {
                        charArr[x + j] = s[i + k];
                        k++;
                    }
                    else
                    {
                        charArr[x + j] = '*';
                    }
                }
                x += numRows;
            }
            isSliding = 0;
            i += rowShift;
            // x += numRows + rowShift; ????
        }    
        else {
            for (int j = 0; j < numRows; j++)
                {
                    if ((i + j) < size)
                    {
                        charArr[x + j] = s[i+j];
                        continue;
                    } else {
                        charArr[x + j] = '*';
                    }
                }
                isSliding = 1;
                i += numRows;
                x += numRows;
        }
    }
}

void transFill2dArr(char* charArr, char* resultStr, int numRows, long numCols)
{
    long x = 0;
    
    for (int j = 0; j < numRows; j++)
    {
        for (long i = 0; i < numCols; i++)
        {
            if (charArr[i * numRows + j] == '*') {
                continue;
            }
            else {
                resultStr[x] = charArr[i * numRows + j];
                x += 1;
            }
        }
    }
    resultStr[x] = '\0';
}

char* convert(char* s, int numRows) {
    int size = strlen(s);
    long numCols = scanZigzag(s, numRows);
    char* targetArr = (char *)malloc(sizeof(char) * ((numRows * numCols) + 1));
    char* resultStr = (char *)malloc(sizeof(char) * ((size) + 1));

    if (numRows == 1) {
        return s;
    }

    fill2dArr(s, targetArr, numRows);
    transFill2dArr(targetArr, resultStr, numRows, numCols);

    printf("-------------------------------\n");
    printf("fill2dArr: %s\n", targetArr);
    printf("len(fill2dArr): %d\n", (int)strlen(targetArr));
    printf("-------------------------------\n");
    printf("numRows: %d\tnumCols: %ld\tresultStr: %s\n", numRows, numCols, resultStr);
    printf("strlen(resultStre): %d\n", (int)strlen(resultStr));

    free(targetArr);
    return resultStr;
}

int main(int argc, char* argv[])
{
    int numRows = 3;
    char* testCase = "PAYPALISHIRING";
    char* result = convert(testCase, numRows);
    printf("\nsize: %d\tresult: %s\n", (int)strlen(testCase), result);
    return 0;
}