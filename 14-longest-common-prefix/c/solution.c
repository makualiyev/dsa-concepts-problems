/*
    Write a function to find the longest common prefix string amongst an array of strings.
    If there is no common prefix, return an empty string "".
    -------------------------
    Topics:
    * String
    * Trie
    -------------------------
    Constraints:
    1 <= strs.length <= 200
    0 <= strs[i].length <= 200
    strs[i] consists of only lowercase English letters.
    -------------------------
    Testcases:
    Input: strs = ["flower","flow","flight"]                        // Output: "fl"
    Input: strs = ["dog","racecar","car"]                           // Output: ""

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* longestCommonPrefix(char **strs, int strsSize)
{   
    int i = 0, j = 0, k = 0;
    printf("str : %d\n", strlen(strs[0]));

    return "ok";
}

int main(int argc, char *argv[])
{
    char *flower = "flower";
    char *flow = "flow";
    char *flight = "flight";

    char **testCaseStrs = {
        flower,
        flow,
        flight
    };
    int testCaseStrsSize = 3;
    // Output: fl

    char *result = longestCommonPrefix(testCaseStrs, testCaseStrsSize);

    printf("\n======================\n");
    printf("testCase\n\ts:%s\tp:%s\nresult:\t%s\n", testCaseS, testCaseP, (result ? "true" : "false"));

    return 0;
}
