#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode *prev = NULL, *next, *curr = head;
    
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}