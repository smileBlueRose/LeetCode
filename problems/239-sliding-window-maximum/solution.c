#include <limits.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int left;
    int right;
    size_t size;
    size_t capacity;
} Deque;

Deque* deque_create(size_t capacity) {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->data = (int*)malloc(capacity * sizeof(int));
    dq->left = 0;
    dq->right = -1;
    dq->size = 0;
    dq->capacity = capacity;
    return dq;
}

void deque_push_front(Deque* dq, int value)
{
    dq->left = (dq->left - 1 + dq->capacity) % dq->capacity;
    dq->data[dq->left] = value;
    if (dq->size == 0) {
        dq->right = dq->left;
    }
    dq->size++;
}

void deque_push_back(Deque* dq, int value)
{
    dq->right = (dq->right + 1) % dq->capacity;
    dq->data[dq->right] = value;
    if (dq->size == 0) {
        dq->left = dq->right;
    }
    dq->size++;
}

int deque_pop_front(Deque* dq)
{
    int value = dq->data[dq->left];
    dq->left = (dq->left + 1) % dq->capacity;
    dq->size--;
    return value;
}

int deque_pop_back(Deque* dq)
{
    int value = dq->data[dq->right];
    dq->right = (dq->right - 1 + dq->capacity) % dq->capacity;
    dq->size--;
    return value;
}

int deque_peek_front(Deque* dq)
{
    return dq->data[dq->left];
}

int deque_peek_back(Deque* dq)
{
    return dq->data[dq->right];
}

int deque_is_empty(Deque* dq)
{
    return dq->size == 0;
}

void deque_destroy(Deque* dq)
{
    free(dq->data);
    free(dq);
}

int* maxSlidingWindow(int* nums, int nums_len, int window, int* return_len)
{
    *return_len = nums_len - window + 1;
    int* result = calloc(*return_len, sizeof(int));

    if (nums_len == 1) {
        result[0] = nums[0];
        return result;
    }
    Deque* dq = deque_create((size_t)window + 1);

    for (int i = 0; i < nums_len; i++) {
        while (!deque_is_empty(dq)) {
            int back = deque_peek_back(dq);
            bool in_window = i - back < window;
            if (!in_window || nums[back] >= nums[i]) {
                break;
            }
            deque_pop_back(dq);
        }
        deque_push_back(dq, i);

        int front = deque_peek_front(dq);
        bool out_of_window = i - front >= window;
        if (out_of_window) {
            deque_pop_front(dq);
        }

        front = deque_peek_front(dq);
        int insert_idx = 0;
        if (i >= window) {
            insert_idx = i - window + 1;
        }
        result[insert_idx] = nums[front];
    }

    deque_destroy(dq);
    return result;
}