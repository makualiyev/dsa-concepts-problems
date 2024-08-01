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

using std::cout, std::string;

class Solution {
public:
    string delimit_string(string& s) {
        
        long size = s.size() * 2 + 1;
        s.reserve(size);
        

        long i = 0, j = 0;
        while (i < size)
        {
            i++;
        }
        return s;
    }

    string longestPalindrome(string s) {
        // setting variables
        cout << "size: " << s.size() << '\n';
        cout << "capacity: " << s.capacity() << '\n';

        s = delimit_string(s);

        return s;
    }
};


int main(void) {
    Solution solution;
    string testCase = "abb";
    string result = solution.longestPalindrome(testCase);

    cout << "result: " << result << '\n';
    
    return 0;
}
