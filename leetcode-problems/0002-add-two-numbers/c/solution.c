#include <stdio.h>
#include <math.h>
#include <stdlib.h>


struct ListNode
{
    int val;
    struct ListNode *next;
};

int sumOfListNodes(struct ListNode *l)
{
    int res = 0;
    int i = 0;

    while (1)
    {
        res += (*l).val * (int)pow(10, i);
        if ((*l).next == NULL)
        {
            break;
        }
        else
        {
            l = (*l).next;
            i += 1;
        }
    }

    return res;
}

int getDigitsCountFromNumber(int *ptr_i)
{
    int res = *ptr_i;
    int num = 0;
    int digits_count = 1;

    while (1)
    {
        num = ((res % (int)pow(10, digits_count)) - (res % (int)pow(10, digits_count - 1))) / (int)pow(10, digits_count - 1);
        printf(": %d\n", num);

        if ((res / (int)pow(10, digits_count)) == 0)
        {
            break;
        }
        digits_count += 1;
    }

    return digits_count;
}

void getDigitsFromNumber(int *ptr_i, int *digits_count, int *digits)
{
    int num = *ptr_i;

    for (int i = 0; i < *digits_count; i++)
    {
        digits[i] = num % 10;
        num = num / 10;
    }
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    int res1, res2;
    res1 = sumOfListNodes(l1);
    res2 = sumOfListNodes(l2);

    int res = res1 + res2;

    // MAIN body
    int digits_count = getDigitsCountFromNumber(&res);
    printf("digits count: %d \n", digits_count);

    int *arr = malloc(sizeof(int) * digits_count);
    struct ListNode *list_node_arr = malloc(sizeof(struct ListNode) * digits_count);

    getDigitsFromNumber(&res, &digits_count, arr);

    for (int i = 0; i < digits_count; i++)
    {
        printf("digits arr %d : %d \n", i, arr[i]);
    }

    for (int i = 0; i < digits_count; i++)
    {
        list_node_arr[i].val = arr[i];
        if (i != 0)
        {
            list_node_arr[i - 1].next = &list_node_arr[i];
        }
        else if (i == digits_count - 1)
        {
            list_node_arr[i].next = NULL;
        }
    }

    for (int i = 0; i < digits_count; i++)
    {
        printf("list_node arr %d : %d \n", i, list_node_arr[i].val);
    }

    return list_node_arr;
}

int main()
{
    struct ListNode l3 = { 3 };w
    struct ListNode l2 = { 2, &l3 };
    struct ListNode l1 = { 1, &l2 };
    struct ListNode l6 = { 6 };
    struct ListNode l5 = { 5, &l6 };
    struct ListNode l4 = { 4, &l5 };
    struct ListNode *lp1, *lp2;
    lp1 = &l1;
    lp2 = &l4;

    struct ListNode *lpres = addTwoNumbers(lp1, lp2);

    printf("result: \n");
    // printf("\t\t lpres head %d\n", lpres->val);

    for (int i = 0; i < 3; i++) {
        printf("\t\t value for %d : %d \n", i, lpres[i].val);
    }

    return 0;
}
