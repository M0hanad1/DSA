#include "stack_array.h"

#include <stdio.h>
#include <stdlib.h>

static void *realloc_stack(Stack *stack, int new_capacity) {
    if (!stack) return NULL;
    void *elements_array = realloc(stack->array, new_capacity * sizeof(int));
    if (!elements_array) return NULL;
    stack->array = elements_array;
    return elements_array;
}

Stack *create_stack() {
    Stack *new_stack = malloc(sizeof(Stack));
    if (!new_stack) return NULL;

    new_stack->array = NULL;
    new_stack->capacity = DEFAULT_CAPACITY;
    new_stack->count = 0;

    if (!realloc_stack(new_stack, new_stack->capacity)) {
        free(new_stack);
        return NULL;
    }
    return new_stack;
}

void push_stack(int data, Stack *stack) {
    if (!stack) return;
    if (stack->count == stack->capacity) {
        if (!realloc_stack(stack, stack->capacity * 2)) return;
        stack->capacity *= 2;
    }
    stack->array[stack->count] = data;
    stack->count++;
}

void pop_stack(Stack *stack) {
    if (!stack || !stack->count) return;
    stack->count--;
    if (stack->capacity > DEFAULT_CAPACITY && stack->count <= stack->capacity / 4) {
        if (realloc_stack(stack, stack->capacity / 2)) stack->capacity /= 2;
    }
}

int peek_stack(Stack *stack) {
    if (!stack || !stack->count) return -1;
    return stack->array[stack->count - 1];
}

void free_stack(Stack *stack) {
    if (!stack) return;
    free(stack->array);
    free(stack);
}
