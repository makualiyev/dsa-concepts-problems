/*
    Given two strings s and t, return true if t is an anagram of s, and false otherwise.
    Follow up: What if the inputs contain Unicode characters? How would you adapt your
    solution to such a case?

    -------------------------
    Topics:
    * Hash Table
    * String
    * Sorting
    -------------------------
    Constraints:
    1 <= s.length, t.length <= 5 * 10^4
    s and t consist of lowercase English letters.
    -------------------------
    Testcases:
    Input: s = "anagram", t = "nagaram"                 // Output: true
    Input: s = "rat", t = "car"                         // Output: false

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

bool isAnagram(char* s, char* t)
{
    
    return true;
}

int main(int argc, char *argv[])
{
    printf("METAINFO:\targv:[%s] argc:[%d]\n", argv[0], argc);
    printf("======================\n");
    
    char *s = "anagram";
    char *t = "nagaram";
    
    printf("======================\n");
    printf("testCase: \n");
    printf("s:%s\tt:%s\n", s, t);    

    clock_t start = clock();
    bool result = isAnagram(s, t);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    printf("result:\t%s", (result? "true": "false"));

    printf("\nTime elapsed: %.4f\n", seconds);
    return 0;
}
