#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxSubstLen = 0;
        int substrLen = 0;
        int substrStart = 0;
        // int counter = 0;
        // char CHAR__;

        for (int i = 0; i < (int)s.size(); i++) {
            substrLen += 1;

            int j = substrStart;
            while (j != i) {
                if (s[j] == s[i]) {
                    substrLen = substrLen - (j - substrStart) - 1;
                    substrStart = j + 1;
                    break;
                }
                j += 1;
            }
            
            if (substrLen > maxSubstLen) {
                maxSubstLen = substrLen;
            }
            
            // cout << "func-end| i:" << i << " s[i]:" << s[i]  << " j:" << j << " counter:" << counter << " substrenl:" << substrLen << '\n';
        }
        
        return maxSubstLen;
    }
};


int main(void) {
    Solution solution;

    // string resStr = "bbtablud";
    // string resStr = "abcabcbb"; // 3
    // string resStr = "bbbbb"; // 1 
    // string resStr = "pwwkew"; // 3
    // string resStr = " "; // 1 
    // string resStr = "au"; // 2
    // string resStr = "dvdf"; // 3
    // string resStr = "bbtablud"; // 6

    int result = solution.lengthOfLongestSubstring(resStr);

    
    cout << "result: " << result << endl;
    
    return 0;
}

/*
    Constraints:

    0 <= s.length <= 5 * 104
    s consists of English letters, digits, symbols and spaces.



    TESTCASE1 = 'abcabcbb' // 3
    TESTCASE2 = 'bbbbb' // 1 
    TESTCASE3 = 'pwwkew' // 3
    TESTCASE4 = ' ' // 1 
    TESTCASE5 = 'au' // 2
    TESTCASE6 = 'dvdf' // 3
    TESTCASE7 = 'bbtablud' // 6


*/
/*

*/
