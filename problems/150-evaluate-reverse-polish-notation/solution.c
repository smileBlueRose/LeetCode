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

int stack_empty(Stack* s) {
    return s->size == 0;
}

void stack_free(Stack* s) {
    free(s->data);
    free(s);
}

int evalRPN(char** tokens, int size) {
    Stack* s = stack_create(size);

    for (int i = 0; i < size; i++) {
        char* t = tokens[i];
        if ((strcmp(t, "+") == 0 || strcmp(t, "-") == 0 ||
             strcmp(t, "*") == 0 || strcmp(t, "/") == 0) &&
            strlen(t) == 1) {
            int b = stack_pop(s);
            int a = stack_pop(s);
            int res;
            if (t[0] == '+')
                res = a + b;
            else if (t[0] == '-')
                res = a - b;
            else if (t[0] == '*')
                res = a * b;
            else
                res = a / b;
            stack_push(s, res);
        }
        else {
            stack_push(s, atoi(t));
        }
    }
    int result = stack_pop(s);
    stack_free(s);
    return result;
}