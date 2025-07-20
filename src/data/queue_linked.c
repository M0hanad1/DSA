#include "queue_linked.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "singly_list.h"

QueueLinked *create_queue_linked() {
    QueueLinked *queue = malloc(sizeof(QueueLinked));
    if (!queue) {
        printf("Failed to allocate memory for queue\n");
        return NULL;
    }
    queue->list = create_list();
    if (!queue->list) {
        free(queue);
        return NULL;
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue_linked(void *data, QueueLinked *queue) {
    if (!queue) return;
    if (!push_tail(data, queue->list)) return;
    queue->rear = queue->list->tail;
    queue->front = queue->list->head;
}

void dequeue_linked(QueueLinked *queue) {
    if (!queue || !queue->front) return;
    pop_head(queue->list);
    queue->front = queue->list->head;
    queue->rear = queue->list->tail;
}

void free_queue_linked(QueueLinked *queue) {
    if (!queue || !queue->list) return;
    free_list(queue->list);
    queue->list = NULL;
    queue->front = NULL;
    queue->rear = NULL;
    free(queue);
}

void *peek_queue_linked(QueueLinked *queue) { return queue && queue->front ? queue->front->data : NULL; }
bool isempty_queue_linked(QueueLinked *queue) { return queue && queue->front ? false : true; }
