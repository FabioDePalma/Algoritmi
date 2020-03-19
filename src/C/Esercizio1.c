#include <stdio.h>
void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}
void insertionSort(int a[], int length){
  int i;
  int j;
  for(i = 1; i<length; i++){
    j = i;
    while(j > 0 && a[j] < a[j-1]){
      swap(&a[j], &a[j-1]);
      j = j-1;
    }
  }
}

//void insertionSort(void* arr, ){

//}

int main(int argc, char const *argv[]) {
  int a[] = {4,6,2,5,7,9};
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
  []field 1;
  []field 2;
  []field 3;
  field1 = insertionSort(field1, lenghtfield1());
  field2 = insertionSort(field2, lenghtfield2());
  field3 = insertionSort(field3, lenghtfield23());
  for(i = 0; i< lenghtfield1(); i++){
    writefile(i + field1[i] + "," field2[i] + "," field3);
  }
}
