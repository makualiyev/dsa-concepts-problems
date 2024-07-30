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

    TESTCASE = "babad"              // "bab"     | Explanation: "aba" is also a valid answer.
    TESTCASE = "cbbd"               // "bb"      |
    TESTCASE = "ac"                 // "a"       |
    TESTCASE = "abb"                // "bb"      |
    TESTCASE = "tacocat"            // "tacocat" |
    TESTCASE = "aacabdkacaa"        // "aca"     |

*/
#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        // setting variables
        

        return s;
    }
};


int main(void) {
    Solution solution;
    
    string testCase = "abb";

    string result = solution.longestPalindrome(testCase);

    std::cout << "result: " << result << std::endl;
    
    return 0;
}
