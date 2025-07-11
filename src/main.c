#include <stdio.h>
#include <stdlib.h>

#include "singly_list.h"

int main() {
    SinglyNode *head = NULL;
    add_node("first", &head);
    add_node("second", &head);
    add_node("third", &head);
    append_node("zero", &head);
    remove_node(0, &head);

    for (SinglyNode *i = head; i != NULL; i = i->next) {
        printf("%s -> ", (char *)i->data);
    }
    printf("NULL\n");

    free_list(head);
}
