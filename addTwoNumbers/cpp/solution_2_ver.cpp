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
    ListNode* addElementToList(ListNode* head, int data)
    {
        if (head == nullptr) {
            ListNode* node = new ListNode;
            node->val = data;
            head = node;
            node->next = nullptr;
        } else {
            ListNode* node = new ListNode;
            node->val = data;
            node->next = head;
            head = node;
        }

        return head;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int i = 0, j = 0;
        ListNode *HEAD = new ListNode;
        HEAD = nullptr;

        int temp = 0, rem = 0;

        while (true)
        {
            rem = (l1->val + l2->val + temp) % 10;
            temp = (l1->val + l2->val) / 10;
            HEAD = addElementToList(HEAD, rem);
            l1 = l1->next;
            l2 = l2->next;
            if ((l1->next == nullptr) && (l2->next == nullptr)) {
                rem = (l1->val + l2->val + temp) % 10;
                temp = (l1->val + l2->val) / 10;
                HEAD = addElementToList(HEAD, rem);
                break;
            }

            // if ((l1->next != nullptr) && (l2->next != nullptr))
            // {
            //     rem = (l1->val + l2->val + temp) % 10;
            //     temp = (l1->val + l2->val) / 10;
            //     HEAD = addElementToList(HEAD, rem);
            //     l1 = l1->next;
            //     l2 = l2->next;
            //     continue;
            // }
            // else if ((l1->next == nulptr) && (l2->next != nulptr))
            // {
            //     rem = l2->val + temp;
            //     addElementToList(HEAD, rem);
            //     l2 = l2->next;
            //     temp = 0;
            // }
            // else if (l2->next == nulptr)
            // {
            //     rem = l2->val + temp;
            //     addElementToList(HEAD, rem);
            //     l2 = l2->next;
            //     temp = 0;
            // }
            // else
            // {
            //     break;
            // }

            i++;
            j++;
        }

        // cout << "test1: " << 12 % 10 << "---" << 12 / 10 << endl;
        // cout << "test2: " << 2 % 10 << "---" << 2 / 10 << endl;

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

    
    ListNode *lp1, *lp2;
    ListNode l3(3);
    ListNode l2(5, &l3);
    ListNode l1(2, &l2);
    ListNode l6(4);
    ListNode l5(6, &l6);
    ListNode l4(5, &l5);
    
    lp1 = &l1;
    lp2 = &l4;
    

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
