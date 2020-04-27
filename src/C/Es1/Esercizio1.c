#define _GNU_SOURCE
#include "../../../Resources/C/sort.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <errno.h>

#define MAX_BUF_LEN 512
#define ERROR_EXIT_CODE 1

/*

id: (tipo intero) identificatore univoco del record;
field1: (tipo stringa) contiene parole estratte dalla divina commedia,
  potete assumere che i valori non contengano spazi o virgole;
field2: (tipo intero);
field3: (tipo floating point);

*/

typedef struct{
    int id;
    char* field1;
    int field2;
    float field3;
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
    float diff = aa->field3 - bb->field3;
    if(diff < 0){
        return -1;
    }else if (diff == 0){
        return 0;
    }else{
        return 1;
    }
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
        int n = fscanf(file, "%d,%512[^,],%d,%f\n", &id, field1, &field2, &field3);


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

    fclose(file);
}

void print_array(Array* array) {
    for(int i=0; i<array_size(array); i++) {
        Record* rec = (Record*)array_get(array, i);
        printf("%10d , %30s , %10d , %f\n", rec->id, rec->field1, rec->field2, rec->field3);
    }
}

void free_data(Array* array) {
    for(int i=0; i<array_size(array); i++) {
        Record* rec = (Record*)array_get(array, i);
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
        Record* rec = (Record*)array_get(array, i);
        fprintf(fptr,"%10d , %30s , %10d , %f\n", rec->id, rec->field1, rec->field2, rec->field3);
    }

    fclose(fptr);

}




int main(int argc, char const *argv[]) {
    Array* array;
    char algorithm[10];
    int order = 1;
    char filename[50];
    char fileDaScrivere[10] = {"ordinato"};
    clock_t start, end, startalgo, endalgo;
    double cpu_time_used, algo_time;
    int choice;
    int numRecord;

    printf("Which algorithm do you prefer to use? (insertion / quick)\n");
    scanf("%s", algorithm);
    printf("Which file do you want to order?\n");
    printf("do you want order:\n 1. records.csv\n 2. other file\n");
    scanf("%d", &choice);

    if(choice == 1){
        strcpy(filename, "../../../test/test1/records.csv");
    }else{
        scanf("%s", filename);
    }
    printf("how many record?\n");
    scanf("%d", &numRecord);




    printf("---------START-----------\n");
    start = clock();


    if(strcmp(algorithm, "insertion")==0){
        array = array_new(numRecord);
        load_data(array, filename);
        startalgo = clock();
        insertionSort(array, compare_field1, order);
        insertionSort(array, compare_field2, order);
        insertionSort(array, compare_field3, order);
        endalgo = clock();
    }else if(strcmp(algorithm, "quick")==0){
        array = array_new(numRecord);
        load_data(array, filename);
        startalgo = clock();
        quickSort(array, compare_field1, 0, array->size-1);
        quickSort(array, compare_field2, 0, array->size-1);
        quickSort(array, compare_field3, 0, array->size-1);
        endalgo = clock();
    }else{
        printf("Parameters error\n");
        exit(ERROR_EXIT_CODE);
    }

    algo_time = ((double) (endalgo - startalgo)) / CLOCKS_PER_SEC;
    printf("---------END ALGO-----------\n");
    printf("time used by cpu for algorithm: %f\n",  algo_time);

    printf("---------writing file-----------\n");
    write_file(array, fileDaScrivere);

    free_data(array);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Total time used by cpu is: %f\n",  cpu_time_used);

    printf("---------END-----------\n");
}
