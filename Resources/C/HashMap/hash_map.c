#define  _GNU_SOURCE
#include "hash_map.h"


HashTable* hashmap_new(){
    HashTable* hashmap = (HashTable*)malloc(sizeof(HashTable));

    hashmap->capacity = 59; //numero primo sarà utile per la funzione h()
    hashmap->size = 0;
    hashmap->items = (HashItem**)calloc((size_t)hashmap->capacity, sizeof(HashItem*));//alloca capacity memoria di grandezza HashItem
    return hashmap;
}

HashItem* new_item(void* key, void* value){
    HashItem* elements = (HashItem*)malloc(sizeof(HashItem));
    elements->key = key;
    elements->value = value;
    return elements;
}

void destroy_item(HashItem* item){
    free(item->key);
    free(item->value);
    free(item);
}

void destroy_hashmap(HashTable* hashmap){
    HashItem* elem;
    for(int i = 0; i< hashmap->size; i++){
        elem = hashmap->items[i];
        if(elem != NULL){
            destroy_item(elem);
        }
    }
    free(hashmap->items);
    free(hashmap);
}
/*
int hash_function(void* k, int capacity){
    double A = (sqrt(5)-1)/2;
    return capacity*(A*k % 1);
}
*/

int main(int argc, char const *argv[]) {
    HashTable* hashmap = hashmap_new();

    void* keyp;
    void* valuep;
    int key = 5;
    int value = 10;
    keyp = &key;
    valuep = &value;
    HashItem* elements = new_item(keyp,valuep);
    printf("key: %d --> value: %d\n", elements->key, elements->value);

    destroy_hashmap(hashmap);
    return 0;
}
