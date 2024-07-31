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
    // string *delimit_string(string s, string* delim_s) {
        
    //     long size = s.size() * 2 + 1;
    //     const char delim = '|';

    //     long i = 0, j = 0;
    //     while (i < (size * 2 + 2))
    //     {
    //         if (i % 2 == 0)
    //         {
    //             *delim_s[i] = delim;
    //         }
    //         else
    //         {
    //             *delim_s[i] = s[j];
    //             j++;
    //         }
    //         i++;
    //     }
    //     return delim_s;
    // }

    string longestPalindrome(string s) {
        // setting variables
        cout << "size: " << s.size() << '\n';
        cout << "capacity: " << s.capacity() << '\n';
        string superstr;
        // superstr = delimit_string(s, &superstr);

        // cout << "superstr: " << superstr << '\n';

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
