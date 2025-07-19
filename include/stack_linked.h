#ifndef _INC_STACK_LINKED
#define _INC_STACK_LINKED

#include "singly_list.h"

typedef struct {
    SinglyList *list;
    SinglyNode *top;
} StackLinked;

StackLinked *create_stack_linked();
void push_stack_linked(void *data, StackLinked *stack);
void pop_stack_linked(StackLinked *stack);
void free_stack_linked(StackLinked *stack);
void *peek_stack_linked(StackLinked *stack);
char isempty_stack_linked(StackLinked *stack);

#endif
