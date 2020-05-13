#include "arrayDyn.h"


ArrayDyn* newarrayDyn(){
    ArrayDyn* arrayDyn = (ArrayDyn*)malloc(sizeof(arrayDyn));
    arrayDyn->capacity = 2;
    arrayDyn->array = (int*)malloc(sizeof(int) * arrayDyn->capacity);
    arrayDyn->size = 0;
    return arrayDyn;
}

void resize(ArrayDyn* a, size_t memsize){
    a->capacity = memsize;
    a->array = (int*)realloc(a->array, sizeof(int) * a->capacity);
}
int arrayDyn_size(ArrayDyn* a){
    return a->size;
}
int arrayDyn_get(ArrayDyn* a, int i){
    return a->array[i];
}

void freeData(ArrayDyn* ArrayDyn){
    free(ArrayDyn->array);
    free(ArrayDyn);
}

void insertarr(ArrayDyn* a, int elem, int index){
    if(a->size == a->capacity){
        resize(a, a->capacity*2);
    }
    a->array[index] = elem;
    a->size++;
}
