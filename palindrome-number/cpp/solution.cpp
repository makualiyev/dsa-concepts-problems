#include <iostream>
#include <cstdio>

using namespace std;

class Solution {
public:
    int digitCount(int* num)
    {
        int remainder = 0;
        int i = 0;
        int x = *num;

        while (true)  {
            remainder = x % 10;
            if (x / 10 == 0) {
                remainder = x % 10;
                break;
            }
            x = x / 10;
            i++;
        } 

        return i + 1;
    }
    
    int* getDigits(int x, int xdc) {
        int* arr = (int*)malloc(sizeof(int) * xdc);

        for (int i = 0; i < xdc; i++) {
            arr[i] = x % 10;
            if (x / 10 == 0) {
                arr[i] = x % 10;
                break;
            }
            x = x / 10;
        }
        return arr;
    }
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int digit_count = digitCount(&x);
        if (digit_count == 1) {
            return true;
        }
        int* arrP = getDigits(x, digit_count);

        for (int i = 0; i < digit_count / 2; i++) {
            if (arr[i] != arr[digit_count-1-i]) {
                return false;
            }
        }
        
        return true;
    }
};

int main(void)
{
    int test_int = 121;
    Solution solution;
    
    int digit_count = solution.digitCount(&test_int);
    bool result = solution.isPalindrome(test_int);
    // int* arrRes = solution.getDigits(test_int, digit_count);

    // for (int i = 0; i < digit_count; i++) {
    //     cout << "arrRes::\t" << i << ": " << arrRes[i] << endl;
    // }

    cout << "testing : " << 3 / 2 << "\n";

    
    printf("digit_count is: %d\n", digit_count);
    return 0;
}