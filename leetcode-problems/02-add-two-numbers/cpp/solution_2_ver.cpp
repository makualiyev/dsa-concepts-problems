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

class Solution
{
public:
    // ListNode* addElementToList(ListNode* head, int data)
    // {
    //     if (head == nullptr) {
    //         ListNode* node = new ListNode;
    //         node->val = data;
    //         head = node;
    //         node->next = nullptr;
    //     } else {
    //         ListNode* node = new ListNode;
    //         node->val = data;
    //         node->next = head;
    //         head = node;
    //     }

    //     return head;
    // }

    ListNode* addElementToList(ListNode* head, int data)
        {
            if (head == nullptr) {
                ListNode* node = new ListNode;
                node->val = data;
                head = node;
                node->next = nullptr;
            } else {
                
                ListNode* tail = head;
                ListNode* node = new ListNode;
                node->val = data;

                while (true) {
                    if (tail->next == nullptr) {
                        tail->next = node;
                        node->next = nullptr;
                        break;
                    }
                    tail = tail->next;
                }
            }

            return head;
        }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int i = 0;
        int temp = 0, rem = 0;

        ListNode *HEAD = new ListNode;
        HEAD = nullptr;

        

        while (true)
        {

            if ((l1 != nullptr) && (l2 != nullptr)) {
                cout << "[CONDITIONAL]::branch::01 -> i: " << i << ";\n";
                rem = (l1->val + l2->val + temp) % 10;
                temp = (l1->val + l2->val + temp) / 10;
                HEAD = addElementToList(HEAD, rem);
                l1 = l1->next;
                l2 = l2->next;
                i++;
                continue;
                }
            else if ((l1 == nullptr) && (l2 == nullptr)) {
                if (temp != 0) {
                    cout << "[CONDITIONAL]::branch::05 -> i: " << i << ";\n";
                    HEAD = addElementToList(HEAD, temp);
                }
                break;
            } else if ((l1 == nullptr)) {
                cout << "[CONDITIONAL]::branch::03 -> i: " << i << ";\n";
                rem = (l2->val + temp) % 10;
                temp = (l2->val + temp) / 10;
                HEAD = addElementToList(HEAD, rem);
                l2 = l2->next;
                i++;
                continue;
            } else if ((l2 == nullptr)) {
                cout << "[CONDITIONAL]::branch::04 -> i: " << i << ";\n";
                rem = (l1->val + temp) % 10;
                temp = (l1->val) / 10 + temp;
                HEAD = addElementToList(HEAD, rem);
                l1 = l1->next;
                i++;
                continue;
            } else {
                cout << "[CONDITIONAL]::branch::06 -> i: " << i << ";\n";
                break;
            }
        }
        
        return HEAD;
    }
};

int main()
{
    // EXTERME CASE
    // ListNode *lp1, *lp2;
    // ListNode l1(9);

    // ListNode l11(9);
    // ListNode l10(9, &l11);
    // ListNode l9(9, &l10);
    // ListNode l8(9, &l9);
    // ListNode l7(9, &l8);
    // ListNode l6(9, &l7);
    // ListNode l5(9, &l6);
    // ListNode l4(9, &l5);
    // ListNode l3(9, &l4);
    // ListNode l2(1, &l3);

    // lp1 = &l1;
    // lp2 = &l2;
    // 1999999999 + 9

    // NORMAL CASE
    // ListNode *lp1, *lp2;
    // ListNode l3(3);
    // ListNode l2(5, &l3);
    // ListNode l1(2, &l2);
    // ListNode l6(4);
    // ListNode l5(6, &l6);
    // ListNode l4(5, &l5);

    // // CASE 2
    // ListNode *lp1, *lp2;
    
    // ListNode l1(1);
    
    // ListNode l6(1);
    // ListNode l5(9, &l6);
    // ListNode l4(9, &l5);
    
    // lp1 = &l1;
    // lp2 = &l4;


    ListNode *lp1, *lp2;
    
    ListNode l6(2);
    ListNode l1(9, &l6);
    ListNode l5(7);
    ListNode l4(3, &l5);
    
    lp1 = &l1;
    lp2 = &l4;

    // 73+29

    Solution solution;
    ListNode *lpres = solution.addTwoNumbers(lp1, lp2);

    cout << "result: " << endl;
    cout << "\t\t" << "lpres head " << lpres->val << endl;

    int i = 0;
    while (true)
    {
        if (lpres->next == nullptr)
        {
            cout << "\t\t" << "value " << i << ": " << lpres->val << endl;
            break;
        }
        else
        {
            cout << "\t\t" << "value " << i << ": " << lpres->val << endl;
            lpres = lpres->next;
            i += 1;
        }
    }

    return 0;
}
