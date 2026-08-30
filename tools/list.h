#ifndef LIST_H
#define LIST_H

#include <stddef.h>
#include <stdbool.h>

typedef struct ListNode ListNode;
typedef struct List List;
typedef struct ListIterator ListIterator;

List* list_create(void);
ListNode* list_node_create(void* data, size_t data_size);
int list_push_back(List* list, void* data, size_t data_size);
int list_push_front(List* list, void* data, size_t data_size);
int list_pop_back(List* list, void* out_data);
int list_pop_front(List* list, void* out_data);
int list_get_at(List* list, size_t index, void* out_data);
int list_set_at(List* list, size_t index, void* data, size_t data_size);
int list_remove_at(List* list, size_t index);

void list_free(List* list);
void list_print(List* list, void (*print_data)(void* data));
size_t list_count(List* list);

ListIterator* list_iterator_create(List* list);
void list_iterator_free(ListIterator* it);
bool list_iterator_has_next(ListIterator* it);
void* list_iterator_next(ListIterator* it, size_t* out_size);

#endif /* LIST_H */
