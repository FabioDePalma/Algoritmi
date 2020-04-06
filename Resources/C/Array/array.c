#include <stdio.h>
#include "array.h"


Array* array_new(int size){
    Array* result = (Array*)malloc(sizeof(Array));
    result->array = (void**)malloc(sizeof(void*) * size);
    result->size = size+1;
    return result;
}


void array_free(Array* array){
    free(array->array);
    free(array);
}

int array_size(Array* arr){
    assert(arr != NULL);
    return arr->size;
}

void* array_get(Array* array, int position) {
    assert(array != NULL);
    if(position > array->size ) {
        fprintf(stderr, "Array index (%d) out of bounds (0:%d)\n", (unsigned int)position, (unsigned int)array->size);
        errno = ENOMEM;
        exit(EXIT_FAILURE);
    }
    return array->array[position];
}

void array_insert(Array* array, void* n, int i){
    array->array[i] = n;
}

void swap(Array* array, int i, int j){
    void* temp = array_get(array, i);
    array->array[i] = array->array[j];
    array->array[j] = temp;
}
