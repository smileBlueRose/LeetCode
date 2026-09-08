#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode* res = malloc(sizeof(struct ListNode));
    if (res == NULL)
        return NULL;

    struct ListNode* res_head = res;

    res->val = 0;
    res->next = NULL;

    while (list1 && list2) {
        if (list1->val <= list2->val) {
            res->next = list1;
            list1 = list1->next;
        } else {
            res->next = list2;
            list2 = list2->next;
        }
        res = res->next;
    }
    while (list1) {
        res->next = list1;
        list1 = list1->next;
        res = res->next;
    }
    while (list2) {
        res->next = list2;
        list2 = list2->next;
        res = res->next;
    }
    res = res_head->next;
    free(res_head);

    return res;
}