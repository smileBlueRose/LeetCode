#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "list.h"

typedef struct ListNode {
    void* data;
    size_t data_size;
    struct ListNode* next;
} ListNode;

typedef struct List {
    ListNode* head;
    ListNode* tail;
    size_t count;
} List;

typedef struct ListIterator {
    ListNode* current;
} ListIterator;

List* list_create(void)
{
    return calloc(1, sizeof(List));
}

ListNode* list_node_create(void* data, size_t data_size)
{
    ListNode* node = malloc(sizeof(ListNode));
    if (node == NULL)
        return NULL;

    void* data_copy = malloc(data_size);
    if (data_copy == NULL) {
        free(node);
        return NULL;
    }

    memcpy(data_copy, data, data_size);
    node->data = data_copy;
    node->data_size = data_size;
    node->next = NULL;

    return node;
}

static ListNode* list_get_node_at(List* list, size_t index)
{
    if (list == NULL || index >= list->count) {
        return NULL;
    }
    ListNode* node = list->head;
    size_t position = 0;
    while (node) {
        if (position == index) {
            return node;
        }
        node = node->next;
        position++;
    }
    return NULL;
}

int list_push_back(List* list, void* data, size_t data_size)
{
    if (list == NULL) {
        return 1;
    }
    ListNode* node = list_node_create(data, data_size);
    if (node == NULL) {
        return 1;
    }

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    }
    else {
        list->tail->next = node;
        list->tail = node;
    }
    list->count++;
    return 0;
}

int list_push_front(List* list, void* data, size_t data_size)
{
    if (list == NULL) {
        return 1;
    }
    ListNode* node = list_node_create(data, data_size);
    if (node == NULL) {
        return 1;
    }

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    }
    else {
        node->next = list->head;
        list->head = node;
    }
    list->count++;
    return 0;
}

int list_pop_back(List* list, void* out_data)
{
    if (list == NULL || list->count == 0) {
        return 1;
    }
    if (list->count == 1) {
        if (out_data != NULL) {
            memcpy(out_data, list->head->data, list->head->data_size);
        }
        free(list->head->data);
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->count--;
        return 0;
    }
    ListNode* old_tail = list->tail;
    ListNode* penultimate = list_get_node_at(list, list->count - 2);
    assert(penultimate != NULL);
    list->tail = penultimate;
    penultimate->next = NULL;

    if (out_data != NULL) {
        memcpy(out_data, old_tail->data, old_tail->data_size);
    }
    free(old_tail->data);
    free(old_tail);
    list->count--;
    return 0;
}

int list_pop_front(List* list, void* out_data)
{
    if (list == NULL || list->count == 0) {
        return 1;
    }
    if (list->count == 1) {
        int pop_result = list_pop_back(list, out_data);
        if (pop_result != 0) {
            return 1;
        }
        return 0;
    }
    ListNode* old_head = list->head;
    list->head = list->head->next;

    if (out_data != NULL) {
        memcpy(out_data, old_head->data, old_head->data_size);
    }
    free(old_head->data);
    free(old_head);
    list->count--;
    return 0;
}

int list_get_at(List* list, size_t index, void* out_data)
{
    ListNode* node = list_get_node_at(list, index);
    if (out_data == NULL || node == NULL) {
        return 1;
    }
    memcpy(out_data, node->data, node->data_size);
    return 0;
}

int list_set_at(List* list, size_t index, void* data, size_t data_size)
{
    if (list == NULL || data == NULL || index >= list->count) {
        return 1;
    }
    ListNode* node = list_get_node_at(list, index);
    if (node == NULL) {
        return 1;
    }
    void* new_data = realloc(node->data, data_size);
    if (new_data == NULL) {
        return 1;
    }
    node->data = new_data;
    memcpy(node->data, data, data_size);
    node->data_size = data_size;
    
    return 0;
}

int list_remove_at(List* list, size_t index)
{
    if (list == NULL || index >= list->count) {
        return 1;
    }
    if (index == 0) {
        int pop_result = list_pop_front(list, NULL);
        if (pop_result != 0) {
            return 1;
        }
        return 0;
    }
    else if (index == list->count - 1) {
        int pop_result = list_pop_back(list, NULL);
        if (pop_result != 0) {
            return 1;
        }
        return 0;
    }
    else {
        ListNode* node = list->head;
        ListNode* prev;
        size_t position = 0;
        while (node) {
            if (position == index) {
                break;
            }
            prev = node;
            node = node->next;
            position++;
        }
        prev->next = node->next;
        free(node->data);
        free(node);
        list->count--;
        return 0;
    }
}

void list_free(List* list)
{
    if (list == NULL)
        return;

    ListNode* node = list->head;

    while (node) {
        ListNode* next = node->next;
        free(node->data);
        free(node);
        node = next;
    }
    free(list);
    return;
}

void list_print(List* list, void (*print_data)(void* data))
{
    ListNode* node = list->head;
    while (node) {
        print_data(node->data);
        node = node->next;
    }
    printf("\n");
}

size_t list_count(List* list)
{
    if (list == NULL)
        return 0;
    return list->count;
}

bool list_contains(List* list, void* data, size_t data_size)
{
    if (list == NULL || data == NULL)
        return false;
    ListNode* node = list->head;
    
    while (node) {
        if (node->data_size == data_size && memcmp(node->data, data, data_size) == 0)
            return true;
        node = node->next;
    }
    return false;
}

ListIterator* list_iterator_create(List* list)
{
    ListIterator* it = malloc(sizeof(ListIterator));
    if (it == NULL)
        return NULL;
    it->current = (list != NULL) ? list->head : NULL;
    return it;
}

void list_iterator_free(ListIterator* it)
{
    free(it);
}

bool list_iterator_has_next(ListIterator* it)
{
    return it != NULL && it->current != NULL;
}

void* list_iterator_next(ListIterator* it, size_t* out_size)
{
    if (it == NULL || it->current == NULL)
        return NULL;
    void* data = it->current->data;
    if (out_size)
        *out_size = it->current->data_size;
    it->current = it->current->next;
    return data;
}

// END