#include <iostream>
#include <math.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    long long int sumOfListNodes(ListNode* l)
        {
            long long int res = 0;
            int i = 0;

            while (true) {
                res += (*l).val * (long long int)pow(10, i);
                if ((*l).next == nullptr) {
                    break;
                } else {
                    l = (*l).next;
                    i += 1;
                }        
            }

            return res;
        }
    int getDigitsCountFromNumber(long long int* ptr_i)
        {
            long long int res = *ptr_i;
            int num = 0;
            int digits_count = 1;

            while (true) {
                num = ((res % (long long int)pow(10, digits_count)) - (res % (long long int)pow(10, digits_count - 1))) / (long long int)pow(10, digits_count - 1);
                cout << ": " <<  num << endl;

                if ((res / (long long int)pow(10, digits_count)) == 0) {
                    break;
                }
                digits_count += 1;
            }

            return digits_count;
        }

    void getDigitsFromNumber(long long int* ptr_i, int* digits_count, long long int* digits)
        {
            long long int num = *ptr_i;

            for (int i = 0; i < *digits_count; i++) {
                digits[i] = num % 10;
                num = num / 10;
            }

            // return 0;
        }

    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        long long int res1, res2;
        res1 = sumOfListNodes(l1);
        res2 = sumOfListNodes(l2);

        long long int res = res1 + res2;

        long int fakeres = 1999999999 + 9;
        cout << "res: " << res << endl;
        cout << "fake res: " << fakeres << endl;

        // MAIN body
        ListNode* HEAD = new ListNode;
        HEAD = nullptr;

        int digits_count = getDigitsCountFromNumber(&res);
        cout << "digits count: " << digits_count << endl;
        
        long long int* arr = new long long int[digits_count];
        getDigitsFromNumber(&res, &digits_count, arr);
        
        for (int i = 0; i < digits_count; i++) {
            ListNode* new_node = new ListNode;
            if (HEAD == nullptr) {
                HEAD = new_node;
                new_node->val = arr[i];
                new_node->next = nullptr;
            } else {
                new_node->val = arr[i];
                new_node->next = HEAD;
                HEAD = new_node;
            }
        }

        return HEAD;
    }
};


int main()
{
    // ListNode l3(3);
    // ListNode l2(4, &l3);
    // ListNode l1(2, &l2);
    // ListNode l6(4);
    // ListNode l5(6, &l6);
    // ListNode l4(5, &l5);
    
    // lp1 = &l1;
    // lp2 = &l4;
    ListNode* lp1, *lp2;
    ListNode l1(9);

    ListNode l11(9);
    ListNode l10(9, &l11);
    ListNode l9(9, &l10);
    ListNode l8(9, &l9);
    ListNode l7(9, &l8);
    ListNode l6(9, &l7);
    ListNode l5(9, &l6);
    ListNode l4(9, &l5);
    ListNode l3(9, &l4);
    ListNode l2(1, &l3);

    lp1 = &l1;
    lp2 = &l2;

    Solution solution;
    // ListNode* lpres = new ListNode;
    ListNode* lpres = solution.addTwoNumbers(lp1, lp2);

    cout << "result: " << endl;
    cout << "\t\t" << "lpres head " << lpres->val << endl;

    // for (int i = 0; i < 3; i++) {
    //     cout << "\t\t" << "value " << i << ": " << lpres[i].val << endl;
    // }

    int i = 0;
    while (true) {
        if (lpres->next == nullptr) {
            cout << "\t\t" << "value " << i << ": " << lpres->val << endl;
            break;
        } else {
            cout << "\t\t" << "value " << i << ": " << lpres->val << endl;
            lpres = lpres->next;
            i += 1;
        }        
    }

    return 0;
}
