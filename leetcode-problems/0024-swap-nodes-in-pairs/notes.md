# 24. Swap Nodes in pairs

## Problem overview

Let's take the following linked list **->1->2** where the output should be **->2->1**, where we are required to use recursion. Recursion in linked lists are represented in a way where a node always points to another linked list. If we take our example and the first node **->1** it points to a linked list with its HEAD pointed to **2**. In this example we need them swapped as we would do it with chars for example 

```c
char a, b;
char temp = a;
a = b;
b = temp;
```

```c
struct ListNode* temp;
temp = head;
temp->next = head->next->next;
head = head->next;
head->next = temp;
```

![linked-list-recursion](assets/linked-list-recursion.drawio.png)

## Implementation

## Resources
