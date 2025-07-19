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
    new_stack->top = -1;

    if (!realloc_stack(new_stack, new_stack->capacity)) {
        free(new_stack);
        return NULL;
    }
    return new_stack;
}

void push_stack(char data, Stack *stack) {
    if (!stack) return;
    if (stack->top + 1 == stack->capacity) {
        if (!realloc_stack(stack, stack->capacity * 2)) return;
        stack->capacity *= 2;
    }
    stack->array[++stack->top] = data;
}

void pop_stack(Stack *stack) {
    if (!stack || stack->top == -1) return;
    stack->top--;
    if (stack->capacity > DEFAULT_CAPACITY && stack->top <= stack->capacity / 4) {
        if (realloc_stack(stack, stack->capacity / 2)) stack->capacity /= 2;
    }
}

char peek_stack(Stack *stack) { return stack && stack->top > -1 ? stack->array[stack->top] : -1; }

void free_stack(Stack *stack) {
    if (!stack) return;
    free(stack->array);
    stack->capacity = 0;
    stack->top = -1;
    free(stack);
}

char isempty_stack(Stack *stack) { return stack && stack->top > -1 ? 0 : 1; }
