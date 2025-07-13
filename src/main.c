#include <stdio.h>
#include <stdlib.h>

#include "singly_list.h"
#include "stack_array.h"

void print_recursion(SinglyNode *head) {
    if (!head) {
        printf("NULL\n");
        return;
    }
    printf("%s -> ", (char *)head->data);
    return print_recursion(head->next);
}

void linked_list() {
    SinglyList *list = create_list();
    push_head("first", list);
    push_head("second", list);
    push_head("third", list);
    push_head("fourth", list);
    push_tail("zero", list);
    insert_node(0, "TEST", list);
    remove_node(0, list);
    insert_node(3, "TEST", list);
    remove_node(3, list);
    insert_node(5, "TEST", list);
    remove_node(5, list);

    print_recursion(list->head);

    pop_head(list);
    pop_tail(list);
    print_recursion(list->head);

    reverse_list(list);
    print_recursion(list->head);

    free_list(list);
}

void array_stack() {
    Stack *stack = create_stack();
    push_stack(1, stack);
    push_stack(2, stack);
    push_stack(3, stack);
    push_stack(4, stack);
    printf("Capacity: %d\n", stack->capacity);
    push_stack(0, stack);
    printf("Capacity: %d\n", stack->capacity);
    pop_stack(stack);

    for (int i = peek_stack(stack); stack->count; pop_stack(stack), i = peek_stack(stack)) printf("=====\n| %d |\n", i);
    printf("=====\n");
    printf("Capacity: %d\n", stack->capacity);

    free_stack(stack);
}

int main() {
    array_stack();
    linked_list();
}
