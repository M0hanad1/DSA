#include "stack_array.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

Stack *create_stack() {
    Stack *stack = malloc(sizeof(Stack));
    if (!stack) {
        printf("Failed to allocate memory for stack\n");
        return NULL;
    }

    stack->capacity = DEFAULT_STACK_CAPACITY;
    stack->top = -1;
    if (!(stack->array = realloc_array(NULL, stack->capacity))) {
        free(stack);
        return NULL;
    }
    return stack;
}

void push_stack(void *data, Stack *stack) {
    if (!stack) return;
    if (stack->top + 1 == stack->capacity) {
        void **new_array = realloc_array(stack->array, stack->capacity * 2);
        if (!new_array) return;
        stack->array = new_array;
        stack->capacity *= 2;
    }
    stack->array[++stack->top] = data;
}

void pop_stack(Stack *stack) {
    if (!stack || stack->top == -1) return;
    stack->top--;
    if (stack->capacity > DEFAULT_STACK_CAPACITY && stack->top <= stack->capacity / 4) {
        void **new_array = realloc_array(stack->array, stack->capacity / 2);
        if (new_array) {
            stack->array = new_array;
            stack->capacity /= 2;
        }
    }
}

void clear_stack(Stack *stack) {
    if (!stack) return;
    free(stack->array);
    stack->capacity = DEFAULT_STACK_CAPACITY;
    stack->top = -1;
    stack->array = realloc_array(NULL, stack->capacity);
}

void free_stack(Stack *stack) {
    if (!stack) return;
    free(stack->array);
    stack->array = NULL;
    stack->capacity = 0;
    stack->top = -1;
    free(stack);
}

void *peek_stack(Stack *stack) { return stack && stack->top > -1 ? stack->array[stack->top] : NULL; }
bool isempty_stack(Stack *stack) { return stack && stack->top > -1 ? false : true; }
