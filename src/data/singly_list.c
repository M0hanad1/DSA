#include "singly_list.h"

#include <stdio.h>
#include <stdlib.h>

SinglyList *create_list() {
    SinglyList *list = malloc(sizeof(SinglyList));
    if (!list) {
        printf("Failed to allocate memory for list!\n");
        return NULL;
    }

    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
    return list;
}

SinglyNode *insert_node(int index, void *data, SinglyList *list) {
    if (!list) return NULL;
    if (!index) return push_head(data, list);
    if (index < 0 || index > list->count) return NULL;
    if (index == list->count) return push_tail(data, list);

    SinglyNode *node_prev = get_node(index - 1, list);
    if (node_prev) {
        SinglyNode *new_node = malloc(sizeof(SinglyNode));
        if (!new_node) {
            printf("Failed to allocate memory!\n");
            return NULL;
        }

        new_node->data = data;
        new_node->next = node_prev->next;
        node_prev->next = new_node;
        list->count++;
        return new_node;
    }

    return NULL;
}

SinglyNode *push_head(void *data, SinglyList *list) {
    if (!list) return NULL;

    SinglyNode *node = malloc(sizeof(SinglyNode));
    if (!node) {
        printf("Failed to allocate memory!\n");
        return NULL;
    }

    node->data = data;
    node->next = list->head;
    if (!list->head) list->tail = node;
    list->head = node;
    list->count++;
    return node;
}

SinglyNode *push_tail(void *data, SinglyList *list) {
    if (!list) return NULL;
    if (!list->head) return push_head(data, list);

    SinglyNode *new_node = malloc(sizeof(SinglyNode));
    if (!new_node) {
        printf("Failed to allocate memory!\n");
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;
    list->tail->next = new_node;
    list->tail = new_node;
    list->count++;
    return new_node;
}

void pop_head(SinglyList *list) {
    if (!list || !list->head) return;
    SinglyNode *remove = list->head;
    list->head = remove->next;
    if (!list->head) list->tail = NULL;
    list->count--;
    free(remove);
}

void pop_tail(SinglyList *list) {
    if (!list || !list->head) return;
    return remove_node(list->count - 1, list);
}

void remove_node(int index, SinglyList *list) {
    if (!list || !list->head) return;
    if (index < 0 || index >= list->count) return;
    if (!index) return pop_head(list);

    SinglyNode *node_prev = get_node(index - 1, list);
    if (node_prev && node_prev->next) {
        SinglyNode *remove = node_prev->next;
        node_prev->next = remove->next;
        if (index == list->count - 1) list->tail = node_prev;
        list->count--;
        free(remove);
    }
}

SinglyNode *get_node(int index, SinglyList *list) {
    if (index < 0 || index >= list->count) return NULL;
    int count = 0;
    for (SinglyNode *node = list->head; node; count++, node = node->next) {
        if (count == index) return node;
    }
    return NULL;
}

void clear_list(SinglyList *list) {
    if (!list) return;
    SinglyNode *temp = NULL;
    while (list->head) {
        temp = list->head;
        list->head = temp->next;
        free(temp);
    }
    list->count = 0;
}

void free_list(SinglyList *list) {
    if (!list) return;
    clear_list(list);
    free(list);
}

void reverse_list(SinglyList *list) {
    if (!list) return;
    SinglyNode *prev = NULL;
    SinglyNode *curr = list->head;
    SinglyNode *next = NULL;

    list->tail = list->head;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    list->head = prev;
}
