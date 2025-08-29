/*
    -------------------------
    Topics:
    * Two Pointers
    * String
    * String Matching
    -------------------------
    Constraints:
    1 <= haystack.length, needle.length <= 10^4
    `haystack` and `needle` consist of only lowercase English characters.
    -------------------------
    Testcases:
    Input: haystack = "sadbutsad", needle = "sad"       // Output: 0
                                                        // Explanation:
                                                            "sad" occurs at index 0 and 6.
                                                            The first occurrence is at index 0, so we return 0.
    Input: haystack = "leetcode", needle = "leeto"      // Output: -1
                                                        // Explanation:
                                                            "leeto" did not occur in "leetcode", so we return -1.
    Input: haystack = "mississippi", needle = "issip"   // Output: 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int strStr(char* haystack, char* needle) {
    int index = -1;
    int i = 0;
    
    while (i < (int)strlen(haystack)) {
        int j = 0, k = i, check = 1;
        while (j < (int)strlen(needle)) {
            if (haystack[k] != needle[j]) {
                // i = k;
                check = 0;
                break;
            }
            j++;
            k++;
        }
        if (check) {
            index = i;
            break;
        }
        i++;
    }

    return index;
}

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    char haystack[] = "mississippi";
    char needle[] = "issip";
    
    clock_t start = clock();
    printf("======================\n");
    printf("testCase: \n");
    printf("\thaystack:%s\tneedle:%s\n", haystack, needle);

    int result = strStr(haystack, needle);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    
    printf("======================\n");
    printf("result:\n");
    printf("\tindex = %d\n", result);

    printf("\nTime elapsed: %.4f\n", seconds);
    return 0;
}
