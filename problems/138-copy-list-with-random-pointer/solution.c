#include <stdlib.h>
#include <stdbool.h>

#define likely(x)   __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)


struct Node {
    int val;
    struct Node* next;
    struct Node* random;
};

struct Node* copyRandomList(struct Node* head)
{
    if (unlikely(head == NULL))
        return NULL;
    
    struct Node *node = head;
    while (node) {
        struct Node* node_copy = malloc(sizeof(struct Node));
        *node_copy = *node;
        node->next = node_copy;
        node = node_copy->next;
    }

    struct Node* copied_node = head->next;
    struct Node* res = copied_node;
    struct Node* res_head = res;
    while (true) {
        if (res->random != NULL)
            res->random = res->random->next;
        
        if (unlikely(copied_node->next == NULL))
            break;

        copied_node = copied_node->next->next;
        res->next = copied_node;
        res = res->next;
    }

    return res_head;
}