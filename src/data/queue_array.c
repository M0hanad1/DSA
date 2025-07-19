#include "queue_array.h"

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

Queue *create_queue() {
    Queue *queue = malloc(sizeof(Queue));
    if (!queue) {
        printf("Failed to allocate memory for queue\n");
        return NULL;
    }

    queue->capacity = DEFAULT_CAPACITY;
    queue->front = 0;
    queue->rear = -1;
    queue->array = malloc(queue->capacity * sizeof(void *));
    if (!queue->array) {
        free(queue);
        return NULL;
    }

    return queue;
}

void enqueue(void *data, Queue *queue) {
    if (!queue) return;
    if (queue->rear + 1 == queue->capacity) {
        void **new_array = realloc_array(queue->array, queue->capacity * 2);
        if (!new_array) return;
        queue->array = new_array;
        queue->capacity *= 2;
    }
    queue->array[++queue->rear] = data;
}

void dequeue(Queue *queue) {
    if (!queue || queue->front > queue->rear) return;
    queue->front++;
    if (queue->capacity > DEFAULT_CAPACITY && queue->rear - queue->front < queue->capacity / 4) {
        for (int i = 0; i < queue->rear - queue->front + 1; i++) queue->array[i] = queue->array[queue->front + i];
        queue->rear -= queue->front;
        queue->front = 0;
        void **new_array = realloc_array(queue->array, queue->capacity / 2);
        if (new_array) {
            queue->array = new_array;
            queue->capacity /= 2;
        }
    }
}

void free_queue(Queue *queue) {
    if (!queue) return;
    queue->capacity = 0;
    queue->front = 0;
    queue->rear = -1;
    free(queue->array);
    free(queue);
}

void *peek_queue(Queue *queue) { return queue && queue->front <= queue->rear ? queue->array[queue->front] : NULL; }
char isempty_queue(Queue *queue) { return queue && queue->front <= queue->rear ? 0 : 1; }
