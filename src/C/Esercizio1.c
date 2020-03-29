#define _GNU_SOURCE
#include "../../Resources/C/InsertionSort/insertion_sort.h"
//#include "../../Resources/C/Array/array.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <errno.h>

//compilare con:
// gcc Esercizio1.c ../../Resources/C/InsertionSort/insertion_sort.c ../../Resources/C/Array/array.c -o Esercizio1

#define MAX_BUF_LEN 1024
#define ERROR_EXIT_CODE 1


/*

id: (tipo intero) identificatore univoco del record;
field1: (tipo stringa) contiene parole estratte dalla divina commedia,
  potete assumere che i valori non contengano spazi o virgole;
field2: (tipo intero);
field3: (tipo floating point);

*/

typedef struct{
    int id; //id record
    char* field1;//world
    int field2;//numeri a caso
    float field3;//numero a caso
} Record;

int compare_id(void* a, void* b) {
    Record * aa = (Record*)a;
    Record* bb = (Record*)b;
    return aa->id - bb->id;
}


int compare_field1(void* a, void*b){
    Record * aa = (Record*)a;
    Record* bb = (Record*)b;
    return strcmp(aa->field1, bb->field1);
}


int compare_field2(void* a, void* b) {
    Record * aa = (Record*)a;
    Record* bb = (Record*)b;
    return aa->field2 - bb->field2;
}

int compare_field3(void* a, void* b) {
    Record * aa = (Record*)a;
    Record* bb = (Record*)b;
    return aa->field3 - bb->field3;
}

void print_usage() { //insertion 1 coseacaso.csv
    printf("Insert: \n");
    printf("< -1 | 1 > <filename>\n");
    printf("    -1: sort descending order\n");
    printf("     1: sort ascending order\n");
}


void load_data(Array* array, char const* filename ) {
    FILE* file = fopen(filename, "r");

    if(!file){
        fprintf(stderr, "No such file or directory\n");
        errno = ENOENT;
        exit(EXIT_FAILURE);
    }

    int id;
    char field1[MAX_BUF_LEN];
    int field2;
    float field3;
    int i = 0;  //line number & index


    while(!feof(file)) {
        Record* record = (Record*) malloc(sizeof(Record));
        int n = fscanf(file, "%d,%1024[^,],%d,%f\n", &id, field1, &field2, &field3);




        if(n != 4) {
            if(feof(file)) {
                continue;
            }

            printf("Error while reading file at line: %d\n", i+1);
            exit(ERROR_EXIT_CODE);
        }

        record->id = id;
        record->field1 = strdup(field1);
        record->field2 = field2;
        record->field3 = field3;

        array_insert(array, record, i);
        i++;
    }
}




void print_array(Array* array) {
    for(int i=0; i<array_size(array); i++) {
        Record* rec = (Record*)array_get(array, i);///////////////////////////////////////////////////
        printf("%10d , %30s , %10d , %f\n", rec->id, rec->field1, rec->field2, rec->field3);
    }


}

void free_data(Array* array) {
    for(int i=0; i<array_size(array); i++) {
        Record* rec = (Record*)array_get(array, i);///////////////////////////////////////////////////
        free(rec->field1);
        free(rec);
    }

    array_free(array);
}

void write_file(Array* array, char const* filename){
    FILE * fptr = fopen(filename, "w");
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }
    for(int i=0; i<array_size(array); i++) {
        Record* rec = (Record*)array_get(array, i);///////////////////////////////////////////////////
        fprintf(fptr,"%10d , %30s , %10d , %f\n", rec->id, rec->field1, rec->field2, rec->field3);
    }

    fclose(fptr);

}


int main(int argc, char const *argv[]) {

    char algorithm[10];
    int order = 1;
    char filename[50]; //= {"daprovare.csv"};
    char fileDaScrivere[10] = {"ordinato"};
    clock_t start, end;
    double cpu_time_used;



    //printf("Which algorithm do you prefer to use? (insertion / quick)\n");

    strcpy(algorithm, "insertion");
    //scanf("%s", algorithm);

    //printf("How do you prefer to order? (increasing = 1 / decreasing = -1)\n");

    //scanf("%d", &order);

    printf("Which file do you want to order?\n");

    scanf("%s", filename);



    //start = clock();
    //printf("%d\n",strcmp(algorithm, "insertion") );
    printf("%s\n",algorithm );

    if(strcmp(algorithm, "insertion")==0){
        Array* array = array_new(20);
        load_data(array, filename);

        insertionSort(array, compare_field1, order);
        insertionSort(array, compare_field2, order);
        insertionSort(array, compare_field3, order);

        write_file(array, fileDaScrivere);
    }else if(strcmp(algorithm, "quick")){

    }else{
        printf("Parameters error\n");
        print_usage();
        exit(ERROR_EXIT_CODE);
    }

    //end = clock();
    //cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;


    //printf("time used by cpu is: %f\n",  cpu_time_used);
    printf("finito\n");
    //print_usage();

//DOVE FA LA PRIMA STAMPA??????????????????????
    /*
print
insertion 1 coseacaso.csv
argv[0]   1       2

 void load_data(SortedArray* array, char const* filename )
 void load_data(array, argv[2])
 sorted_array(argv[1])
 */

}
