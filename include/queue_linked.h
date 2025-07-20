#ifndef _INC_QUEUE_LINKED
#define _INC_QUEUE_LINKED

#define DEFAULT_CAPACITY 4

#include <stdbool.h>

#include "singly_list.h"

typedef struct {
    SinglyList *list;
    SinglyNode *front;
    SinglyNode *rear;
} QueueLinked;

QueueLinked *create_queue_linked();
void enqueue_linked(void *data, QueueLinked *queue);
void dequeue_linked(QueueLinked *queue);
void free_queue_linked(QueueLinked *queue);
void *peek_queue_linked(QueueLinked *queue);
bool isempty_queue_linked(QueueLinked *queue);

#endif
