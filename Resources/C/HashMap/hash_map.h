#include <stdio.h>
#include <stdlib.h>
#include "arrayDyn.h"


#define true 1
#define false 0


typedef struct _hashmap{
    void ** array;
    int size;
    int capacity;
}HashMap;

typedef struct _Node{
    void* key;
    void* elem;
    struct _Node* next;
}Node;

/**
 * Create a new HashTable
 * Parameter: capacity of the table
 */
HashMap* new_HashMap(int capacity);

/**
 * Delete all pair <key,value> and frees the memory allocated
 * Note: it does not free the memory of the object in the Node
 */
void deleteAllNode(HashMap* hashmap);

/** Destroy table*/
void destroy_hashmap(HashMap* hashmap);

/** Return
 * 1 if hashMap is empty
 * 0    else
 */
int isEmpty(HashMap* hashmap);

/** Return:
 * number of pair <key,value>
 */
int numberOfElem(HashMap* hashmap);

/** Return:
 * 1 if the key is present in the hashMap
 * 0  else
 * Parameter: hashmap, key, *compare Funcion,Hash Function
 */
int isKey(HashMap* map, void* key, int (*compare)(void* a, void* b), int hashFunction);

/** Returns the value associated with the key
 * Paramenter: hashmap, key, *compare Funcion,Hash Function
 * Note: must cast of own type because the function return void*
 */
void* get_value(HashMap* map, void* key, int (*compare)(void* a, void* b), int hashFunction);

/**
 * insert a new pair <key,value>
 */
void insert(HashMap* map, void* key, void* value, int (*compare)(void* a, void* b), int hashFunction);

/*remove a key associated */
void removeKey(HashMap* map, void* key,int (*compare)(void*a, void*b) ,int hashFunction);

/** Return: new ArrayDyn of key
 *
 */
ArrayDyn* allKeys(HashMap* map);
