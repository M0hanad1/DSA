#include "singly_list.h"

#include <stdio.h>
#include <stdlib.h>

SinglyNode *add_node(void *data, SinglyNode **head) {
    if (!head) return NULL;

    SinglyNode *node = malloc(sizeof(SinglyNode));
    if (!node) {
        printf("Failed to allocate memory!\n");
        return NULL;
    }

    node->data = data;
    node->next = *head;
    *head = node;
    return node;
}

SinglyNode *get_node(int index, SinglyNode *head) {
    int count = 0;
    for (SinglyNode *node = head; node; count++, node = node->next) {
        if (count == index) return node;
    }
    return NULL;
}

SinglyNode *get_last_node(SinglyNode *head) {
    if (!head) return NULL;
    SinglyNode *temp = head;
    for (; temp->next; temp = temp->next);
    return temp;
}

SinglyNode *insert_node(int index, void *data, SinglyNode **head) {
    if (!head) return NULL;
    if (index == 0) return add_node(data, head);

    SinglyNode *new_node = malloc(sizeof(SinglyNode));
    if (!new_node) {
        printf("Failed to allocate memory!\n");
        return NULL;
    }

    SinglyNode *node_prev = get_node(index - 1, *head);
    if (node_prev) {
        new_node->data = data;
        new_node->next = node_prev->next;
        node_prev->next = new_node;
        return new_node;
    }

    free(new_node);
    return NULL;
}

SinglyNode *append_node(void *data, SinglyNode **head) {
    if (!head) return NULL;
    if (!*head) return add_node(data, head);

    SinglyNode *last_node = get_last_node(*head);
    if (!last_node) return NULL;

    SinglyNode *new_node = malloc(sizeof(SinglyNode));
    if (!new_node) {
        printf("Failed to allocate memory!\n");
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;
    last_node->next = new_node;
    return new_node;
}

void remove_node(int index, SinglyNode **head) {
    if (!head) return;
    SinglyNode *remove = NULL;
    if (index == 0) {
        remove = *head;
        *head = (*head)->next;
        free(remove);
        return;
    }

    SinglyNode *node_prev = get_node(index - 1, *head);
    if (node_prev && node_prev->next) {
        remove = node_prev->next;
        node_prev->next = node_prev->next->next;
        free(remove);
    }
}

void free_list(SinglyNode *head) {
    SinglyNode *temp = NULL;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
