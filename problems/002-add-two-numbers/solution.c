#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    const int len = 101;
    int res[len];

    for (int i = 0; i < len; i++)
        res[i] = 0;

    int i = 0;
    while (l1) {

        res[i++] = l1->val;
        l1 = l1->next;
    }

    int carry = 0;
    i = 0;
    while (l2) {
        res[i] += l2->val + carry;
        carry = res[i] >= 10;
        res[i] -= 10 * carry;

        i++;
        l2 = l2->next;
    }

    while (carry) {
        res[i] += carry;

        if (res[i] >= 10) {
            res[i] %= 10;
            carry = 1;
        }
        else {
            carry = 0;
        }

        i++;
    }

    int last = len - 1;
    while (last > 0 && res[last] == 0)
        last--;

    struct ListNode* nodes = malloc(sizeof(struct ListNode) * (last + 1));

    for (int j = 0; j < last; j++) {
        nodes[j].val = res[j];
        nodes[j].next = &nodes[j + 1];
    }
    nodes[last].val = res[last];
    nodes[last].next = NULL;

    return nodes;
}