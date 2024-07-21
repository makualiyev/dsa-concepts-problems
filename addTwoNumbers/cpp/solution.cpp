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
    int sumOfListNodes(ListNode* l)
        {
            int res = 0;
            int i = 0;

            while (true) {
                res += (*l).val * (int)pow(10, i);
                if ((*l).next == nullptr) {
                    break;
                } else {
                    l = (*l).next;
                    i += 1;
                }        
            }

            return res;
        }
    int getDigitsCountFromNumber(int* ptr_i)
        {
            int res = *ptr_i;
            int num = 0;
            int digits_count = 1;

            while (true) {
                num = ((res % (int)pow(10, digits_count)) - (res % (int)pow(10, digits_count - 1))) / (int)pow(10, digits_count - 1);
                cout << ": " <<  num << endl;

                if ((res / (int)pow(10, digits_count)) == 0) {
                    break;
                }
                digits_count += 1;
            }

            return digits_count;
        }

        void getDigitsFromNumber(int* ptr_i, int* digits_count, int* digits)
        {
            int num = *ptr_i;

            for (int i = 0; i < *digits_count; i++) {
                digits[i] = num % 10;
                num = num / 10;
            }

            // return 0;
        }


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int res1, res2;
        res1 = sumOfListNodes(l1);
        res2 = sumOfListNodes(l2);

        int res = res1 + res2;

        // MAIN body
        // ListNode* list_node_ptr = new ListNode;
        int digits_count = getDigitsCountFromNumber(&res);
        cout << "digits count: " << digits_count << endl;
        
        int* arr = new int[digits_count];
        ListNode* list_node_arr = new ListNode[digits_count];
        getDigitsFromNumber(&res, &digits_count, arr);
        

        for (int i = 0; i < digits_count; i++) {
            cout << "digits arr " << i << " : " << arr[i] << endl;
        }

        for (int i = 0; i < digits_count; i++) {
            list_node_arr[i].val = arr[i];
            if (i != 0) {
                list_node_arr[i - 1].next = &list_node_arr[i];
            }
            else if (i == digits_count - 1) {
                list_node_arr[i].next = nullptr;
            }
        }

        for (int i = 0; i < digits_count; i++) {
            cout << "list_node arr " << i << " : " << list_node_arr[i].val << endl;
        }

        return list_node_arr;
    }
};


int main()
{
    ListNode l3(3);
    ListNode l2(2, &l3);
    ListNode l1(1, &l2);
    ListNode l6(6);
    ListNode l5(5, &l6);
    ListNode l4(4, &l5);
    ListNode* lp1, *lp2;
    lp1 = &l1;
    lp2 = &l4;

    Solution solution;
    ListNode* lpres = solution.addTwoNumbers(lp1, lp2);

    cout << "result: " << endl;
    cout << "\t\t" << "lpres head " << lpres->val << endl;

    for (int i = 0; i < 3; i++) {
        cout << "\t\t" << "value " << i << ": " << lpres[i].val << endl;
    }

    delete [] lpres;
    return 0;
}
