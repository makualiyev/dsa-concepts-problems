#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        std::cout << "length is " << s.length() << '\n';
        return true;
    }
};

int main(void)
{
    std::string s1 = "aaa";
    std::string s2 = "aa*";

    Solution solution;

    bool result = solution.isMatch(s1, s2);

    std::cout << "testing\tstring: " << s1 << " pattern: " << s2 << '\n';
    std::cout << "result is: " << (result ? "true" : "false") << '\n';
    return 0;
}