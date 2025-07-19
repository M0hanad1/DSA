#ifndef _INC_QUEUE_ARRAY
#define _INC_QUEUE_ARRAY

#define DEFAULT_CAPACITY 4

typedef struct {
    void **array;
    int capacity;
    int front;
    int rear;
} Queue;

Queue *create_queue();
void enqueue(void *data, Queue *queue);
void dequeue(Queue *queue);
void free_queue(Queue *queue);
void *peek_queue(Queue *queue);
char isempty_queue(Queue *queue);

#endif
