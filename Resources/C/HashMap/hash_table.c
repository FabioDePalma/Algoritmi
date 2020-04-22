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
    void* elem;
    struct _Node* next;
}Node;

/*create hashMap empty*/
HashTable* new_hashtable(int capacity){
    HashTable* alloca = (HashTable*)malloc(sizeof(HashTable));
    alloca->array = (void**)malloc(sizeof(void*) * capacity);
    alloca->capacity = capacity;
    alloca->size = 0;

    return alloca;
}

int isEmpty(HashTable* table){
    return table->size == 0;
}

int numberOfElem(HashTable* table){
    return table->size;
}

void deleteAllNode(HashTable* table){
    for(int i = 0; i<table->capacity; i++){
        if(table->array[i] != NULL){
            Node* prev = (Node*)table->array[i];
            Node* head = prev;

            while(head != NULL){
                head = head->next;
                free(prev);
                prev = head;
            }
            free(head);
        }
    }
    table->size = 0;
}

void destroy_hashmap(HashTable* table){

    deleteAllNode(table);
    free(table);
}

int isKey(HashTable* table, int key){
    if(table->array[key] == NULL){
        return 0;
    }else{
        return 1;
    }
}

Node* value(HashTable* table, int key){
    return (Node*)table->array[key];
}

static int findValue(HashTable* map, int key, void* value, int (*compare)(void* a, void* b)){
    Node* it = (Node*)map->array[key];
    while(it!=NULL){
        if(compare(value, it->elem) == 0){
            printf("element is already present in the map");
            return true;
        }else{
            if(it->next == NULL){
                return false;
            }
            it = it->next;
        }
    }
    return false;
}


void insert(HashTable* map, int key, void* value, int (*compare)(void* a, void* b)){
    int find = findValue(map, key, value, compare);
    Node* temp = (Node*)map->array[key];
    if(temp==NULL){
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->elem = value;
        new_node->next = NULL;
        map->array[key] = new_node;
        map->size++;
    }else{
        if(find==0){//se non ho trovato l'elemento
            Node* new_node = (Node*)malloc(sizeof(Node));
            new_node->elem = value;
            new_node->next = temp;

            map->array[key] = new_node;
            map->size++;
        }
    }
}

Node* getValue(HashTable* map, int key){
    return (Node*)map->array[key];
}

void removeKey(HashTable* map, int key){
    if(map->array[key] != NULL){
        Node* prev = (Node*)map->array[key];
        Node* head = prev;

        while(head != NULL){
            head = head->next;
            free(prev);
            prev = head;
            map->size--;
        }
        free(head);
    }
}

Array* allKeys(HashTable* map){
    Array* arrayDyn = newArray();
    int count = 0;
    for(int i = 0; i<map->capacity; i++){
        if(map->array[i] != NULL){
            insertarr(arrayDyn, i, count);
            count++;
        }

    }
    return arrayDyn;
}

int hashFun(HashTable* map, int value){
    return value % map->capacity;
}
int compareint(void* a, void* b) {
    int* aa = (int*)a;
    int* bb = (int*)b;
    return aa - bb;
}

int main() {
    printf("creo\n" );
    HashTable* hashmap = new_hashtable(5);
    printf("funzione\n" );
    int hash = hashFun(hashmap, 1) ;
    insert(hashmap, hash, (int*)100, compareint);
    hash = hashFun(hashmap, 2);
    insert(hashmap, hash, (int*)200, compareint);
    hash = hashFun(hashmap, 3);
    insert(hashmap, hash, (int*)300, compareint);
    hash = hashFun(hashmap, 4);
    insert(hashmap, hash, (int*)444, compareint);
    hash = hashFun(hashmap, 5);
    insert(hashmap, hash, (int*)555, compareint);
    hash = hashFun(hashmap, 6);
    insert(hashmap, hash, (int*)600, compareint);
    hash = hashFun(hashmap, 7);
    insert(hashmap, hash, (int*)700, compareint);
    hash = hashFun(hashmap, 8);
    insert(hashmap, hash, (int*)800, compareint);
    hash = hashFun(hashmap, 9);
    insert(hashmap, hash, (int*)900, compareint);
    hash = hashFun(hashmap, 10);
    insert(hashmap, hash, (int*)1000, compareint);
    hash = hashFun(hashmap, 11);
    insert(hashmap, hash, (int*)1100, compareint);
    hash = hashFun(hashmap, 12);
    insert(hashmap, hash, (int*)1200, compareint);
    hash = hashFun(hashmap, 13);
    insert(hashmap, hash, (int*)1300, compareint);
    hash = hashFun(hashmap, 14);
    insert(hashmap, hash, (int*)1400, compareint);
    hash = hashFun(hashmap, 15);
    insert(hashmap, hash, (int*)1500, compareint);

    for(int i = 0; i<hashmap->capacity; i++){
        if(hashmap->array[i] != NULL){
            printf("key: %d --->", i);
            Node * list = getValue(hashmap, i);
            Node * it = list;
            while(it != NULL){
                printf("%d------", (int*)it->elem);
                it = it->next;
            }
        }
        printf("\n" );
    }
    destroy_hashmap(hashmap);

    return 0;
}
