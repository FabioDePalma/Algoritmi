#include "../sort.h"

void insertionSort(Array* array, int (*compare)(void* a, void* b), int check){
    int i,j;
    int length = array_size(array);
    /*Descending*/
    if(check == -1){
        for(i = 1; i<length; i++){
            j = i;
            while(j > 0 && compare(array_get(array, j-1), array_get(array, j)) < 0 ){
                swap(array, j-1, j);
                j = j-1;
            }
        }
    /*Ascending*/
    }else if(check == 1){
        for(i = 1; i<length; i++){
            j = i;
            while(j > 0 && compare(array_get(array, j-1), array_get(array, j)) > 0 ){
                swap(array, j-1, j);
                j = j-1;
            }
        }
    }else{
        printf("Parameters error\n");
        exit(0);
    }
}
