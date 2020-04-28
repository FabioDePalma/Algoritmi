#include <stdio.h>
#include <stdlib.h>
#include "arrayDyn.h"


#define true 1
#define false 0


typedef struct _table{
    void ** array;
    int size;
    int capacity;
}HashTable;

typedef struct _Node{
    void* key;
    void* elem;
    struct _Node* next;
}Node;

HashTable* new_hashtable(int capacity);

void deleteAllNode(HashTable* table);

void destroy_hashmap(HashTable* table);

int isEmpty(HashTable* table);

int numberOfElem(HashTable* table);

int isKey(HashTable* map, void* key, int (*compare)(void* a, void* b), int hashFunction);

void* get_value(HashTable* map, void* key, int (*compare)(void* a, void* b), int hashFunction);

void insert(HashTable* map, void* key, void* value, int (*compare)(void* a, void* b), int hashFunction);

void removeKey(HashTable* map, void* key,int (*compare)(void*a, void*b) ,int hashFunction);

Array* allKeys(HashTable* map);
/*
int hashFun(HashTable* map, int value);

int compareint(void* a, void* b);
*/
