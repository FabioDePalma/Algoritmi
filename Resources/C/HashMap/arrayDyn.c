#include "arrayDyn.h"


Array* newArray(){
    Array* array = (Array*)malloc(sizeof(Array));
    array->capacity = 100;
    array->array = (int*)malloc(sizeof(int) * array->capacity);
    array->size = 0;
    return array;
}

void resize(Array* a, size_t memsize){
    a->capacity = memsize;
    a->array = (int*)realloc(a->array, sizeof(int) * a->capacity);

}

void insertarr(Array* a, int elem, int index){
    if(a->capacity == a->size){
        resize(a, a->capacity*2);
    }
    a->array[index] = elem;
    a->size++;
}
