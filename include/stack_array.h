#ifndef _INC_STACK_ARRAY
#define _INC_STACK_ARRAY

#define DEFAULT_CAPACITY 4

typedef struct {
    int *array;
    int capacity;
    int count;
} Stack;

Stack *create_stack();
void push_stack(int data, Stack *stack);
void pop_stack(Stack *stack);
void free_stack(Stack *stack);
int peek_stack(Stack *stack);

#endif
