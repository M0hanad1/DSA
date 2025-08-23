#ifndef _INC_VECTOR
#define _INC_VECTOR

#include <stdbool.h>
#include <stdlib.h>

#define DEFAULT_VECTOR_CAPACITY 4

typedef struct {
    void **array;
    size_t capacity;
    size_t length;
} Vector;

Vector *create_vector();
bool push_vector(Vector *vector, void *data);
bool pop_vector(Vector *vector);
bool insert_vector(Vector *vector, void *data, size_t index);
bool remove_vector(Vector *vector, size_t index);
bool isempty_vector(Vector *vector);
bool clear_vector(Vector *vector);
void free_vector(Vector *vector);

#endif
