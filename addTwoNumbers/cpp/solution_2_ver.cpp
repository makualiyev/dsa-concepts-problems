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
    ListNode* makeListFromArray(int* arr, int arr_size) {
        
        // while (true) {

        // }
        return node;
    }

    void printList(ListNode* l) {
        cout << l << endl;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return l1;
    }
};


int main()
{
    int list1[3] = {2,4,3};
    int list2[3] = {5,6,4};
    struct ListNode *l1 = makeListFromArray(list1, 3);
    struct ListNode *l2 = makeListFromArray(list2, 3);

    printList(l1);
    printList(l2);

    struct ListNode *answer = addTwoNumbers(l1, l2);
    printList(answer);

    
    return 0;
}
