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
    Input: strs = [""]                                              // Output: ""
    Input: strs = ["ab", "a"]                                       // Output: "a"


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* longestCommonPrefix(char **strs, int strsSize)
{   
    char prefix[200];
    char prefixCheck;
    int check = 1;
    int i = 0;


    while (1)
    {
        for (int j = 0; j < strsSize; j++)
        {
            if ((i < strlen(strs[j])) && (prefix[i] != '\0'))
                {
                    if (prefix[i] != strs[j][i])
                        {
                            prefix[i] = '\0';
                            check = 0;
                            break;
                        }
                }
            else if ((i >= strlen(strs[j])) && (prefix[i] != '\0'))
                {
                    prefix[i] = '\0';
                    check = 0;
                    break;
                }
            else if ((prefix[i] == '\0') && (strs[j][i] != '\0'))
                {
                    prefix[i] = strs[j][i];
                }
            else if ((prefix[i] == '\0') && (strs[j][i] == '\0'))
                {
                    check = 0;
                    prefix[i] = '\0';
                    break;
                }
            else
                break;
        }

        if (check == 0)
            break;
        i++;
    }

    printf("buffer : %s\n", prefix);
    printf("str : %d\n", strlen(strs[0]));

    char *prefixResult = (char *)malloc(sizeof(char) * (strlen(prefix) + 1));
    memcpy(prefixResult, prefix, sizeof(char) * (strlen(prefix) + 1));

    return prefixResult;
}

int main(int argc, char *argv[])
{

    // char *testCaseStrs[] = {
    //     "flower",
    //     "flow",
    //     "flight"
    // };
    // int testCaseStrsSize = 3;
    // // Output: fl

    // char *testCaseStrs[] = {
    //     ""
    // };
    // int testCaseStrsSize = 1;
    // // Output: ""

    char *testCaseStrs[] = {
        "ab",
        "a"
    };
    int testCaseStrsSize = 2;
    // Output: "a"
    
    

    char *result = longestCommonPrefix(testCaseStrs, testCaseStrsSize);

    printf("\n======================\n");
    // printf("testCase\n\ts:%s\tp:%s\nresult:\t%s\n", testCaseS, testCaseP, (result ? "true" : "false"));
    printf("\nresult:\t%s\n", result);

    return 0;
}
