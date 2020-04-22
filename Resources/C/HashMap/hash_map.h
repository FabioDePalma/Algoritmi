#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _item{
    void* key;
    void* value;
}HashItem;

typedef struct _Hashtable{
    int capacity; //size
    int size;//count
    HashItem** items;
}HashTable;

HashTable* hashmap_new();

HashItem* new_item(void* key, void* value);

void destroy_item(HashItem* item);

void destroy_hashmap(HashTable* hashmap);
