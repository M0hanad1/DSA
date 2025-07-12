#include <stdio.h>
#include <stdlib.h>

#include "singly_list.h"

void print_recursion(SinglyNode *head) {
    if (!head) {
        printf("NULL\n");
        return;
    }
    printf("%s -> ", (char *)head->data);
    return print_recursion(head->next);
}

int main() {
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
