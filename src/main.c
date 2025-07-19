#include <stdio.h>
#include <stdlib.h>

#include "singly_list.h"
#include "stack_array.h"
#include "stack_linked.h"

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

void stack_array() {
    Stack *stack = create_stack();
    push_stack(1, stack);
    push_stack(2, stack);
    push_stack(3, stack);
    push_stack(4, stack);
    printf("Empty: %d\n", isempty_stack(stack));
    printf("Capacity: %d\n", stack->capacity);
    push_stack(0, stack);
    printf("Capacity: %d\n", stack->capacity);
    pop_stack(stack);

    for (int i = peek_stack(stack); !isempty_stack(stack); pop_stack(stack), i = peek_stack(stack)) {
        printf("=====\n| %d |\n", i);
    }

    printf("=====\n");
    printf("Empty: %d\n", isempty_stack(stack));
    printf("Capacity: %d\n", stack->capacity);
    free_stack(stack);
}

void stack_linked() {
    StackLinked *stack = create_stack_linked();
    push_stack_linked("1th", stack);
    push_stack_linked("2th", stack);
    push_stack_linked("3th", stack);
    push_stack_linked("4th", stack);
    printf("Empty: %d\n", isempty_stack_linked(stack));
    push_stack_linked("TEST", stack);
    pop_stack_linked(stack);

    for (void *i = stack->top->data; !isempty_stack_linked(stack); pop_stack_linked(stack), i = peek_stack_linked(stack)) {
        printf("=======\n| %s |\n", (char *)i);
    }

    printf("=======\n");
    printf("Empty: %d\n", isempty_stack_linked(stack));
    free_stack_linked(stack);
}

char valid_parentheses(char *exp) {
    if (!exp) return 0;
    Stack *stack = create_stack();
    if (!stack) return 0;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            push_stack(exp[i], stack);
        } else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            if (isempty_stack(stack)) {
                free_stack(stack);
                return 0;
            }
            char stack_top = peek_stack(stack);
            if ((stack_top == '(' && exp[i] != ')') ||
                (stack_top == '[' && exp[i] != ']') ||
                (stack_top == '{' && exp[i] != '}')) {
                free_stack(stack);
                return 0;
            }
            pop_stack(stack);
        }
    }

    char empty = isempty_stack(stack);
    free_stack(stack);
    return empty ? 1 : 0;
}

int main() {
    printf("=====================\n");
    linked_list();
    printf("=====================\n");
    stack_array();
    printf("=====================\n");
    stack_linked();
    printf("=====================\n");
    printf("%d\n", valid_parentheses("[(A * B) + {C + D}]"));
    printf("%d\n", valid_parentheses("[}]"));
    printf("%d\n", valid_parentheses("("));
    printf("%d\n", valid_parentheses("{[}]"));
    printf("%d\n", valid_parentheses("[{()}]"));
    printf("=====================\n");
}
