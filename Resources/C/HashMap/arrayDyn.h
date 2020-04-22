#include <stdio.h>
#include <stdlib.h>
typedef struct _Array{
    int* array;
    int size;
    int capacity;
}Array;

Array* newArray();
void resize(Array* a, size_t memsize);
void insertarr(Array* a, int elem, int index);
