#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *longestPalindrome(char *s)
{
    int size = strlen(s);
    char *substr = malloc(sizeof(char) * 15);
    int counter = 0;

    for (int i = 0; i < size; i++)
    {
        int left = i - 1;
        int right = i + 1;

        while (1)
        {
            if ((left >= 0) && (right < size))
            {
                for (int k = 0; k < 3; k++) {
                    substr[counter + k] = s[left + k];
                }
                substr[right+3] = '\t';
                counter += right + 1;
                printf("while|branch1: left->%d right->%d i->%d\n", left, right, i);
            }
            else if (left >= 0)
            {
                if (s[left] == s[i])
                {
                    printf("while|branch2-1: left->%d right->%d i->%d\n", left, right, i);
                    break;
                }
                else
                {
                    break;
                }
                printf("while|branch2-2: left->%d right->%d i->%d\n", left, right, i);
            }
            else if (right < 0)
            {
                if (s[i] == s[right])
                {
                    printf("while|branch3-1: left->%d right->%d i->%d\n", left, right, i);
                    break;
                }
                printf("while|branch3-2: left->%d right->%d i->%d\n", left, right, i);
                break;
            }
            else
            {
                break;
            }
            left--;
            right++;
        }

        // printf("%d:%c \n", i, s[i]);
    }

    // printf("string: %s\tsize: %d\n", s, size);

    printf("substr: ");
    if (substr != NULL)
    {
        int substr_c = 0;
        while (1)
        {
            if (substr[substr_c] == '\0')
            {
                break;
            }
            printf("%c", substr[substr_c]);
            substr_c++;
        }
    }
    printf("\n");
    return s;
}

int main(int argc, char *argv[])
{
    char *testCase = "babad";
    char *result = longestPalindrome(testCase);

    printf("result: %s\n", result);

    return 0;
}

/*
    -------------------------
    Topics:
    * Two Pointers
    * String
    * Dynamic Programming

    -------------------------
    Constraints:

    1 <= s.length <= 1000
    s consist of only digits and English letters.

    -------------------------
    Testcases:

    TESTCASE1 = "babad"             // "bab" | Explanation: "aba" is also a valid answer.
    TESTCASE2 = "cbbd"              // "bb"  |

*/