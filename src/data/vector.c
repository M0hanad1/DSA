#include "vector.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

static bool realloc_vector(Vector *vector) {
    if (vector->length == vector->capacity) {
        void **new_array = realloc_array(vector->array, vector->capacity * 2);
        if (!new_array) return false;
        vector->array = new_array;
        vector->capacity *= 2;
    } else if (vector->capacity > DEFAULT_VECTOR_CAPACITY && vector->length <= vector->capacity / 4) {
        void **new_array = realloc_array(vector->array, vector->capacity / 2);
        if (!new_array) return false;
        vector->array = new_array;
        vector->capacity /= 2;
    }
    return true;
}

Vector *create_vector() {
    Vector *vector = malloc(sizeof(Vector));
    if (!vector) {
        printf("Failed to allocate memory for vector\n");
        return NULL;
    }

    vector->array = NULL;
    vector->capacity = DEFAULT_VECTOR_CAPACITY;
    vector->length = 0;

    if (!(vector->array = realloc_array(vector->array, DEFAULT_VECTOR_CAPACITY))) {
        free(vector);
        return NULL;
    }
    return vector;
}

bool push_vector(Vector *vector, void *data) {
    if (!vector || !data || !realloc_vector(vector)) return false;
    vector->array[vector->length] = data;
    vector->length++;
    return true;
}

bool pop_vector(Vector *vector) {
    if (!vector || !vector->length) return false;
    vector->length--;
    realloc_vector(vector);
    return true;
}

bool insert_vector(Vector *vector, void *data, size_t index) {
    if (!vector || index > vector->length || !realloc_vector(vector)) return false;
    for (size_t i = vector->length; i > index; i--) vector->array[i] = vector->array[i - 1];
    vector->array[index] = data;
    vector->length++;
    return true;
}

bool remove_vector(Vector *vector, size_t index) {
    if (!vector || index >= vector->length) return false;
    vector->length--;
    for (size_t i = index; i < vector->length; i++) vector->array[i] = vector->array[i + 1];
    realloc_vector(vector);
    return true;
}

bool isempty_vector(Vector *vector) { return !vector || vector->length == 0; }

bool clear_vector(Vector *vector) {
    if (!vector || !vector->array) return false;
    free(vector->array);
    vector->capacity = DEFAULT_VECTOR_CAPACITY;
    vector->length = 0;
    return (vector->array = realloc_array(NULL, DEFAULT_VECTOR_CAPACITY)) ? true : false;
}

void free_vector(Vector *vector) {
    if (!vector) return;
    free(vector->array);
    vector->array = NULL;
    vector->length = 0;
    vector->capacity = 0;
    free(vector);
}
