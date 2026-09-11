/*
Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
*/
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int len = 0;
    struct ListNode* curr = head;
    while (curr) {
        curr = curr->next;
        len++;
    }
        
    int index = len - n;
    if (index == 0) {
        struct ListNode* res = head->next;
        free(head);
        return res;
    }
    struct ListNode* node = head, *prev = NULL;

    while (index > 0) {
        prev = node;
        node = node->next;
        index--;
    }
    prev->next = node->next;
    free(node);
    return head;
}