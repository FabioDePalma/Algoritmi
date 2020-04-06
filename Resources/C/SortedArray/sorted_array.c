#include <stdlib.h>
#include "sorted_array.h"

#define INITIAL_CAPACITY 100

struct _SortedArray {
    void** array;
    int capacity;
    int size;
    SortedArrayCmp compare;
};


SortedArray* SortedArray_new(SortedArrayCmp compare) {
    SortedArray* result = (SortedArray*) malloc(sizeof(SortedArray));
    result->capacity = INITIAL_CAPACITY;
    result->array = (void**) malloc(sizeof(void*) * result->capacity);
    result->size = 0;
    result->compare = compare;

    return result;
}


void SortedArray_free(SortedArray* sa) {
    free(sa->array);
    free(sa);
}

void SortedArray_resize(SortedArray* sa, size_t memsize) {
    sa->capacity = memsize;
    sa->array = (void**) realloc(sa->array, sa->capacity);
}

void SortedArray_insert(SortedArray* sa, void* obj) {
    if(sa->capacity == sa->size) {
        SortedArray_resize(sa, sa->capacity * 2);
    }

    int i;
    for(i = sa->size-1; i>=0 && sa->compare(obj, sa->array[i]) < 0; i--) {
        sa->array[i+1] = sa->array[i];
    }

    sa->array[i+1] = obj;
    sa->size++;
}


void SortedArray_remove(SortedArray* sa, int i) {
    if(sa->capacity > sa->size * 2){
        SortedArray_resize(sa, sa->capacity / 2);
    }

    for(int j = i; j<sa->size-1; j++) {
        sa->array[j] = sa->array[j+1];
    }

    sa->size--;
}

void* SortedArray_get(SortedArray* sa, int i) {
    return sa->array[i];
}

int SortedArray_size(SortedArray* sa) {
    return sa->size;
}
