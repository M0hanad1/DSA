#ifndef _INC_QUEUE_ARRAY
#define _INC_QUEUE_ARRAY

#define DEFAULT_QUEUE_CAPACITY 4

#include <stdbool.h>

typedef struct {
    void **array;
    int capacity;
    int front;
    int rear;
} Queue;

Queue *create_queue();
void enqueue(void *data, Queue *queue);
void dequeue(Queue *queue);
void clear_queue(Queue *queue);
void free_queue(Queue *queue);
void *peek_queue(Queue *queue);
bool isempty_queue(Queue *queue);

#endif
