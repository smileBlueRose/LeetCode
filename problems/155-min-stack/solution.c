const int STACK_SIZE = 10;

typedef struct {
    int pos;
    int* values;
    int* mins;
    int size;
} MinStack;


MinStack* minStackCreate() {
    MinStack* stack = malloc(sizeof(MinStack));
    stack->values = malloc(STACK_SIZE * sizeof(int));
    stack->mins = malloc(STACK_SIZE * sizeof(int));
    stack->pos = -1;
    stack->size = STACK_SIZE;
    return stack;
}

void minStackPush(MinStack* stack, int value) {
    if (stack->pos + 1 == stack->size) {
        int old_size = stack->size;
        stack->size *= 2;
        int* new_values = malloc(stack->size * sizeof(int));
        int* new_mins = malloc(stack->size * sizeof(int));
        for (int i = 0; i < old_size; i++) {
            new_values[i] = stack->values[i];
            new_mins[i] = stack->mins[i];
        }
        free(stack->values);
        free(stack->mins);
        stack->values = new_values;
        stack->mins = new_mins;
    }
    int p = ++stack->pos;
    stack->values[p] = value;
    
    if (p == 0)
        stack->mins[p] = value;
    else if (value < stack->mins[p - 1])
        stack->mins[p] = value;
    else
        stack->mins[p] = stack->mins[p - 1];
}

void minStackPop(MinStack* stack) {
    if (stack->pos == -1)
        return;
    stack->pos--;
}

int minStackTop(MinStack* stack) {
    return stack->values[stack->pos];
}

int minStackGetMin(MinStack* stack) {
    return stack->mins[stack->pos];
}

void minStackFree(MinStack* stack) {
    free(stack->values);
    free(stack->mins);
    free(stack);
}
