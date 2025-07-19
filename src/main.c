#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "queue_array.h"
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
    int f = 1, s = 2, t = 3, fo = 4;

    push_stack(&f, stack);
    push_stack(&s, stack);
    push_stack(&t, stack);
    push_stack(&fo, stack);

    printf("Empty: %d\n", isempty_stack(stack));
    printf("Capacity: %d\n", stack->capacity);
    push_stack("TEST", stack);
    printf("Capacity: %d\n", stack->capacity);
    pop_stack(stack);

    while (!isempty_stack(stack)) {
        void *i = peek_stack(stack);
        printf("=====\n| %d |\n", *(int *)i);
        pop_stack(stack);
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

bool valid_parentheses(char *exp) {
    if (!exp) return false;
    Stack *stack = create_stack();
    if (!stack) return false;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            push_stack(&exp[i], stack);
        } else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            if (isempty_stack(stack)) {
                free_stack(stack);
                return false;
            }
            char stack_top = *(char *)peek_stack(stack);
            if ((stack_top == '(' && exp[i] != ')') ||
                (stack_top == '[' && exp[i] != ']') ||
                (stack_top == '{' && exp[i] != '}')) {
                free_stack(stack);
                return false;
            }
            pop_stack(stack);
        }
    }

    bool empty = isempty_stack(stack);
    free_stack(stack);
    return empty ? true : false;
}

void queue_array() {
    Queue *queue = create_queue();
    float f = 1.1, s = 2.2, t = 3.3, fo = 4.4;

    enqueue("TEST", queue);
    enqueue(&f, queue);
    enqueue(&s, queue);
    enqueue(&t, queue);
    enqueue(&fo, queue);

    printf("Empty: %d\n", isempty_queue(queue));
    printf("Capacity: %d\n", queue->capacity);
    dequeue(queue);

    while (!isempty_queue(queue)) {
        void *i = peek_queue(queue);
        printf("=======\n| %g |\n", *(float *)i);
        dequeue(queue);
    }

    printf("=======\n");
    printf("Empty: %d\n", isempty_queue(queue));
    printf("Capacity: %d\n", queue->capacity);
    free_queue(queue);
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
    queue_array();
    printf("=====================\n");
}
