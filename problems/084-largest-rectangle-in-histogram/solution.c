#include <stdio.h>
#include <stdlib.h>
 
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

int largestRectangleArea(int* heights, int heightsSize) {
    int n = heightsSize + 1;
    Stack* s = stack_create(n);
    int max_area = 0;
    
    int* copy = malloc(sizeof(int) * n);
    copy[n - 1] = 0;
    for (int i = 0; i < heightsSize; i++)
        copy[i] = heights[i];

    for (int i = 0; i < n; i++) {
        if (stack_empty(s) || copy[stack_top(s)] <= copy[i]) {
            stack_push(s, i);
            continue;
        }
        else {
            while (!stack_empty(s) && copy[stack_top(s)] > copy[i]) {
                int k = stack_pop(s);
                
                int left = stack_empty(s) ? -1 : stack_top(s);
                int right = i;
                int width = right - left - 1;
                int area = width * copy[k];
                max_area = area > max_area ? area : max_area;
            }
            stack_push(s, i);
        }

    }
    free(copy);
    stack_free(s);
    return max_area;
}