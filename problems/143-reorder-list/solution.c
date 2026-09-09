#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* prev = NULL, * curr = head, * next = NULL;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void reorderList(struct ListNode* head)
{
    if (!head || !head->next) {
        return;
    }

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    struct ListNode* right = reverseList(slow);
    struct ListNode* left = head->next;
    struct ListNode* tail = head;
    char turn = 1;

    while (left != slow) {
        if (turn) {
            tail->next = right;
            right = right->next;
        }
        else {
            tail->next = left;
            left = left->next;
        }
        tail = tail->next;
        turn ^= 1;
    }

    tail->next = right;
}