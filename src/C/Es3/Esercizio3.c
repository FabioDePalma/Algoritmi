#include "../../../Resources/C/HashMap/hash_map.h"
#include "../../../Resources/C/sort.h"
#include <errno.h>
#include <time.h>
#define CAPACITYHM 4000000
#define CAPACITYARR 6321078
#define RANDOMKEY 10000000

typedef struct _pair{
    int key;
    int value;
}Pair;


int hashFun(int lengthHashmap, int key){
    return key % lengthHashmap;
}
int compare(void * a, void* b){
    int* aa = (int*)a;
    int* bb = (int*)b;
    return aa-bb;
}
int compareArr(void* a, void* b){
    Pair* aa = (Pair*)a;
    Pair* bb = (Pair*)b;
    return aa->key - bb->key;
}
void load_array(Array* array, char const* filename){
    FILE* file = fopen(filename, "r");
    if(!file){
        fprintf(stderr, "No such file or directory\n");
        errno = ENOENT;
        exit(EXIT_FAILURE);
    }

    int key;
    int value;
    int i = 0;

    while(!feof(file)) {
        Pair* pair = (Pair*) malloc(sizeof(Pair));
        int n = fscanf(file, "%d,%d\n", &key, &value);


        if(n != 2) {
            if(feof(file)) {
                continue;
            }

            printf("Error while reading file at line: %d\n", i+1);
            exit(1);
        }

        pair->key = key;
        pair->value = value;
        array_insert(array, pair, i);
        i++;
    }

    fclose(file);
}


void load_hashmap(HashMap* hashMap, char const* filename){
    FILE* file = fopen(filename, "r");
    if(!file){
        fprintf(stderr, "No such file or directory\n");
        errno = ENOENT;
        exit(EXIT_FAILURE);
    }

    int key;
    int value;
    int hashFunction;
    int i = 0;


    while(!feof(file)) {

        int n = fscanf(file, "%d,%d\n", &key, &value);
        if(n != 2) {
            if(feof(file)) {
                continue;
            }

            printf("Error while reading file at line: %d\n", i+1);
            exit(1);
        }

        hashFunction = hashFun(hashMap->capacity, key);

        insert(hashMap, (int*)key, (int*)value , compare,hashFunction);

    }
    fclose(file);
}

int timeGetValueRandom(HashMap* map, Array* randomKey){
    void* valuee;
    long keyy;
    int numberOfKey = 0;
    for(int i = 0; i<randomKey->size; i++){
        keyy = (long)array_get(randomKey, i);
        valuee = get_value(map, (long*)keyy, compare, hashFun(map->capacity, keyy));
        if(valuee != NULL){
            numberOfKey++;
        }
    }
    return numberOfKey;
}

int binary(Array* arraySorted, int left, int right, int elem){
    int m = floor((left+ right)/2);
    Pair* pair = (Pair*)array_get(arraySorted, m);
    if(m<left || right < 0){
        return -1;
    }else if(elem < pair->key){
        return binary(arraySorted, left, m-1,elem);
    }else if(elem > pair->key){
        return binary(arraySorted, m+1, right,elem);
    }else{
        return pair->value;
    }

}



int timeGetValueSorted(Array* arraySorted, Array* randomKey){
    int numberOfKey = 0;
    long keyToSearch;
    int value;

    for(int i = 0; i<randomKey->size; i++){
        keyToSearch = (long)array_get(randomKey, i);
        value = binary(arraySorted, 0, arraySorted->size-1, keyToSearch);
        if(value != -1){
            numberOfKey++;
        }
    }
    return numberOfKey;
}



int main() {

    /*---------------------HashMap, caricamento diretto-------------------------*/

    clock_t hashstart, hashend;
    double cpu_time_hash;
    HashMap* map = new_HashMap(CAPACITYHM);
    char filecsv[40] = {"../../../test/test3/hashes.csv"};

    hashstart = clock();
    load_hashmap(map,filecsv);
    hashend = clock();
    cpu_time_hash = ((double) (hashend - hashstart)) / CLOCKS_PER_SEC;

    printf("\n\n\ntime loading hashmap  : %f\n", cpu_time_hash );

    /*------------Array: load static array & quickSort-------------*/
    clock_t arrayStart, arrayEnd;
    double cpu_time_array;

    Array* arraySorted = array_new(CAPACITYARR);

    arrayStart = clock();

    load_array(arraySorted, filecsv);
    quickSort(arraySorted, compareArr, 0, arraySorted->size-1);

    arrayEnd = clock();

    cpu_time_array = ((double) (arrayEnd - arrayStart)) / CLOCKS_PER_SEC;
    printf("\n\n\ntime loading & sorting array  : %f\n", cpu_time_array );


    /*------------random number-------------*/

    srand(time(0));
    Array* randomKey = array_new(RANDOMKEY);
    for(int i = 0;i<randomKey->size; i++){
        int random = rand()%RANDOMKEY;
        array_insert(randomKey, (int*)random, i);
    }

    /*--------------recovery value 10000000 key-------------*/
    clock_t startHashMap, endHashMap;
    startHashMap = clock();
    int getHashMapKey = timeGetValueRandom(map,randomKey);
    endHashMap = clock();
    printf("\n\n\ntime get value random hashMap: %f\n", ((double) (endHashMap-startHashMap)) / CLOCKS_PER_SEC );

    /*---------------recovery key-value pair using binary research-------------------*/
    clock_t startArray, endArray;

    startArray = clock();
    int getSortedArrayKey = timeGetValueSorted(arraySorted, randomKey);
    endArray = clock();
    printf("\n\n\ntime get value random array : %f\n",  ((double) (endArray-startArray)) / CLOCKS_PER_SEC );

    printf("number of key in hashmap : %d\nnumber of key in array : %d\n", getHashMapKey, getSortedArrayKey);

    destroy_hashmap(map);
    array_free(randomKey);
    for(int i = 0; i<arraySorted->size; i++){
        free(arraySorted->array[i]);
    }
    array_free(arraySorted);

    return 0;
}
