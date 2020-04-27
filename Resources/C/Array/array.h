#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>

typedef struct _myArray{
    void** array;//array generic type
    int size;
}Array;

typedef int (*compare)(void*, void*);

/**
 * Create a new Static Array
 * Parameter: size of array
 */
Array* array_new(int size);

/**
 * Frees the memory alloced by array_new.
 * Note: it does not free the memory of the objects
 *       in the array.
 */
void array_free(Array* array);

/** Returns the number of elements currently present
 * in the array.
 */
int array_size(Array* arr);

/**
 *  Returns the object in position 'position'
 */
void* array_get(Array* array, int position);
/**
 * swap two elements by index
 * Parameter: array, index a, index b.
 *
 */
void swap(Array* array, int i, int j);

/**
 * Inserts a new object in the array.
 */
void array_insert(Array* array, void* n, int i);
