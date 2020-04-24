#include "Array/array.h"
#include <float.h>
#include <math.h>

int partition(Array* array,int (*compare)(void* a, void* b), int i , int j);

void quickSort(Array* array, int (*compare)(void* a, void* b), int i, int j);

void insertionSort(Array* array, int (*compare)(void* a, void* b), int check);
