#include <stdio.h>
#include <stdlib.h>
typedef struct _Array{
    int* array;
    int size;
    int capacity;
}ArrayDyn;

ArrayDyn* newarrayDyn();
void resize(ArrayDyn* a, size_t memsize);
void insertarr(ArrayDyn* a, int elem, int index);
int arrayDyn_size(ArrayDyn* a);
int arrayDyn_get(ArrayDyn* a, int i);
void freeData(ArrayDyn* array);
