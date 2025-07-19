#ifndef _INC_STACK_ARRAY
#define _INC_STACK_ARRAY

#define DEFAULT_CAPACITY 4

typedef struct {
    void **array;
    int capacity;
    int top;
} Stack;

Stack *create_stack();
void push_stack(void *data, Stack *stack);
void pop_stack(Stack *stack);
void free_stack(Stack *stack);
void *peek_stack(Stack *stack);
char isempty_stack(Stack *stack);

#endif
