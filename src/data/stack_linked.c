#include "stack_linked.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "singly_list.h"

StackLinked *create_stack_linked() {
    StackLinked *stack = malloc(sizeof(StackLinked));
    if (!stack) {
        printf("Failed to allocate memory for stack\n");
        return NULL;
    }

    stack->list = create_list();
    if (!stack->list) {
        free(stack);
        return NULL;
    }
    stack->top = NULL;
    return stack;
}

void push_stack_linked(void *data, StackLinked *stack) {
    if (!stack) return;
    if (!push_head(data, stack->list)) return;
    stack->top = stack->list->head;
}

void pop_stack_linked(StackLinked *stack) {
    if (!stack || !stack->top) return;
    pop_head(stack->list);
    stack->top = stack->list->head;
}

void free_stack_linked(StackLinked *stack) {
    if (!stack || !stack->list) return;
    free_list(stack->list);
    stack->list = NULL;
    stack->top = NULL;
    free(stack);
}

void *peek_stack_linked(StackLinked *stack) { return stack && stack->top ? stack->top->data : NULL; }
bool isempty_stack_linked(StackLinked *stack) { return stack && stack->top ? false : true; }
