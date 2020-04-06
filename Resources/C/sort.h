#include "Array/array.h"

int partition(Array* array,int (*compare)(void* a, void* b), int i , int j);

void quickSort(Array* array, int (*compare)(void* a, void* b), int i, int j);

void insertionSort(Array* array, int (*compare)(void* a, void* b), int check);
