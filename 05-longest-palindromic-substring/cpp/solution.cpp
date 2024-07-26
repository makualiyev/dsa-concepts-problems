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

    TESTCASE = "babad"             // "bab" | Explanation: "aba" is also a valid answer.
    TESTCASE = "cbbd"              // "bb"  |
    TESTCASE = "ac"                // "a"   |
    TESTCASE = "abb"               // "bb"  |

*/
#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        string result = "";

        int sSize = (int)s.size();
        int mid = sSize / 2;

        cout << "size: " << sSize << " mid: " << mid << endl;
        
        for (int i = 0, j = (sSize - 1); i < sSize; i++, j--) {
            int left = i - 1;
            int right = i + 1;
        }

        return result;
    }
};


int main(void) {
    Solution solution;
    
    string testCase = "abb";
    // string testCase = "aa";
    // string testCase = "tacocat";

    string result = solution.longestPalindrome(testCase);

    std::cout << "result: " << result << std::endl;
    
    return 0;
}
