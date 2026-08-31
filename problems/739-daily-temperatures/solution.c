#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} Stack;

Stack* stack_create(size_t capacity) {
    Stack* s = malloc(sizeof(Stack));
    s->data = malloc(capacity * sizeof(int));
    s->size = 0;
    s->capacity = capacity;
    return s;
}

void stack_push(Stack* s, int value) {
    s->data[s->size++] = value;
}

int stack_pop(Stack* s) {
    return s->data[--s->size];
}

int stack_top(Stack* s) {
    return s->data[s->size - 1];
}

int stack_empty(Stack* s) {
    return s->size == 0;
}

void stack_free(Stack* s) {
    free(s->data);
    free(s);
}


int* dailyTemperatures(int* temperatures, int in_size, int* out_size)
{
    Stack* val_st = stack_create(in_size);
    Stack* idx_st = stack_create(in_size);
    int* res = calloc(in_size, sizeof(int));
    *out_size = in_size;

    for (int i = 0; i < in_size; i++) {
        while (!stack_empty(val_st) && stack_top(val_st) < temperatures[i]) {
            int top_val = stack_pop(val_st);
            int top_idx = stack_pop(idx_st);
            res[top_idx] = i - top_idx;
        }
        stack_push(val_st, temperatures[i]);
        stack_push(idx_st, i);
    }

    stack_free(val_st);
    stack_free(idx_st);
    return res;
}