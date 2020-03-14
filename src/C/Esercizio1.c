#include <stdio.h>
void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}
void insertionSort(int a[], int length){
  int i;
  int j;
  for(i = 0; i<length; i++){
    j = i;
    while(j > 0 && a[j] < a[j-1]){
      swap(&a[j], &a[j-1]);
      j = j-1;
    }
  }
}

void insertionSort(void* arr, ){

}

int main(int argc, char const *argv[]) {
  int a[] = {4, 6,2,5,7,9};
  int i;
  int length = sizeof(a)/sizeof(int);
  for(i = 0; i<length; i++){
    printf( "%d ", a[i] );
  }
  printf("\n" );
  insertionSort(a, length);
  for(i = 0; i<length; i++){
    printf( "%d ", a[i] );
  }
  return 0;
}
