#include <stdio.h>
#include <stdlib.h>

void **realloc_array(void **array, int new_capacity) {
    void **new_array = realloc(array, new_capacity * sizeof(void *));
    if (!new_array) {
        printf("Failed to reallocate memory for array\n");
        return NULL;
    }
    return new_array;
}
