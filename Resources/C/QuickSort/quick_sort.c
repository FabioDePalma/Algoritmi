#include "../sort.h"



int partition(Array* array,int (*compare)(void* a, void* b), int i , int j){

    int pivot = i;
    i++;
    while(i <= j){
        if(compare(array_get(array, i), array_get(array, pivot)) <= 0){
            i++;
        }else if(compare(array_get(array, j), array_get(array, pivot)) > 0){
            j--;
        }else{
            swap(array, i,j);
            i++;
            j--;
        }
    }
    swap(array, pivot, j);
    return j;
}

void quickSort(Array* array, int (*compare)(void* a, void* b), int i, int j){
    int pivot;
    if(j > i){
        pivot = partition(array,compare, i, j);
        if(pivot > 1){
            quickSort(array,compare, i, pivot-1);
        }
        if(pivot < j-1){
            quickSort(array, compare, pivot+1, j);
        }
    }
}
