#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>

typedef struct _myArray{
    void** array;//array generic type
    int size;
}Array;

typedef int (*compare)(void*, void*);


Array* array_new(int size);
void array_free(Array* array);
int array_size(Array* arr);
void* array_get(Array* array, int position);
void swap(Array* array, int i, int j);
void array_insert(Array* array, void* n, int i);
