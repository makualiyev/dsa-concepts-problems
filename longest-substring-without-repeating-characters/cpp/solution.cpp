#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        return 0;
    }
};


int main(void) {
    Solution solution;
    string resStr = "abcabcbb";
    int ok = solution.lengthOfLongestSubstring(resStr);

    for (int i = 0; i < resStr.length(); i++) {
        cout << "\t\ti elem: " << resStr[i] << endl;
    }
    

    cout << "result: " << ok << endl;
    cout << "string len: " << resStr.length() << endl;
    
    return 0;
}