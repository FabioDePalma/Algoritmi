#include "hash_table.h"



/*create hashMap empty*/
HashTable* new_hashtable(int capacity){
    HashTable* alloca = (HashTable*)malloc(sizeof(HashTable));
    alloca->array = (void**)calloc(capacity, sizeof(void*));
    alloca->capacity = capacity;
    alloca->size = 0;

    return alloca;
}
void deleteAllNode(HashTable* table){
    for(int i = 0; i<table->capacity; i++){
        if(table->array[i] != NULL){
            Node* head = (Node*)table->array[i];
            Node* prev = head;
            table->array[i] = NULL;

            while(head != NULL){
                head = head->next;
                free(prev);
                prev = head;
                table->size--;
            }
            //free(head);
        }
    }
}

void destroy_hashmap(HashTable* table){
    deleteAllNode(table);
    if(table != NULL){
      free(table);
    }
    //table = NULL;
}

int isEmpty(HashTable* table){
    return table->size == 0;
}

int numberOfElem(HashTable* table){
    return table->size;
}


int isKey(HashTable* map, void* key, int (*compare)(void* a, void* b), int hashFunction){
    if(map->array[hashFunction] == NULL){
        return false;
    }else{
        Node* it = (Node*)map->array[hashFunction];
        while(it!=NULL){
            if(compare(key, it->key) == 0){
                return true;
            }else{
                it = it->next;
            }
        }
        return false;
    }
}


void* get_value(HashTable* map, void* key, int (*compare)(void* a, void* b), int hashFunction){
    if(map->array[hashFunction] == NULL){
        perror("there is no value for this key");
        return NULL;
    }else{
        Node* it = (Node*)map->array[hashFunction];
        while(it!=NULL){
            if(compare(key, it->key) == 0){
                return it->elem;
            }else{
                it = it->next;
            }
        }
        perror("the lookup value is not found ");
        return NULL;
    }
}

void insert(HashTable* map, void* key, void* value, int (*compare)(void* a, void* b), int hashFunction){
    Node* temp = (Node*)map->array[hashFunction];
    int find;
    if(temp == NULL){
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->key = key;
        new_node->elem = value;
        new_node->next = NULL;
        map->array[hashFunction] = new_node;
        map->size++;
    }else{
        find = isKey(map, key, compare, hashFunction);
        if(find==0){//se non ho trovato l'elemento
            Node* new_node = (Node*)malloc(sizeof(Node));
            new_node->key = key;
            new_node->elem = value;
            new_node->next = temp;

            map->array[hashFunction] = new_node;
            map->size++;
        }else{
            perror("the key is alredy present,\n pair <K,V> not inserted");
        }
    }
}

void removeKey(HashTable* map, void* key,int (*compare)(void*a, void*b) ,int hashFunction){
    if(map->array[hashFunction] == NULL){
        perror("there is no value for this key");
    }else{
        Node* head = (Node*)map->array[hashFunction];
        Node* prev = head;
        if(compare(head->key, key) == 0){ // cancellazione in testa
            if(prev->next == NULL){
                map->array[hashFunction] = NULL;
                free(prev);
                map->size--;
            }else{//ho più di 1 nodo
                head = head->next;
                free(prev);
                map->size--;
            }
        }else{ //cancellazione in mid e in coda
            head = head->next;
            while(head != NULL){
                if(compare(head->key, key) == 0){
                    prev->next = head->next;
                    free(head);
                    map->size--;
                }else{
                    head = head->next;
                    prev = prev->next;
                }
            }
        }
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
    for(int i = 0; i<arrayDyn->size;i++)
        printf("%d\n",arrayDyn->array[i] );
    return arrayDyn;
}

/*
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
    insert(hashmap, (int*)1 , (int*)100, compareint, hash);
    hash = hashFun(hashmap, 2);
    insert(hashmap, (int*)2, (int*)200, compareint, hash);
    hash = hashFun(hashmap, 3);
    insert(hashmap, (int*)3, (int*)300, compareint, hash);
    hash = hashFun(hashmap, 4);
    insert(hashmap, (int*)4, (int*)444, compareint, hash);
    hash = hashFun(hashmap, 5);
    insert(hashmap, (int*)5, (int*)555, compareint, hash);
    hash = hashFun(hashmap, 6);
    insert(hashmap, (int*)6 , (int*)600, compareint, hash);
    hash = hashFun(hashmap, 7);
    insert(hashmap, (int*)7, (int*)700, compareint, hash);
    hash = hashFun(hashmap, 8);
    insert(hashmap, (int*)8, (int*)800, compareint, hash);
    hash = hashFun(hashmap, 9);
    insert(hashmap, (int*)9, (int*)900, compareint, hash);
    hash = hashFun(hashmap, 10);
    insert(hashmap, (int*)10, (int*)1000, compareint, hash);
    hash = hashFun(hashmap, 11);
    insert(hashmap, (int*)11, (int*)1100, compareint, hash);
    hash = hashFun(hashmap, 12);
    insert(hashmap, (int*)12, (int*)1200, compareint, hash);
    hash = hashFun(hashmap, 13);
    insert(hashmap, (int*)13, (int*)1300, compareint, hash);
    hash = hashFun(hashmap, 14);
    insert(hashmap, (int*)14, (int*)1400, compareint, hash);
    hash = hashFun(hashmap, 15);
    insert(hashmap, (int*)15, (int*)1500, compareint, hash);


    for(int i = 0; i<hashmap->capacity; i++){
        if(hashmap->array[i] != NULL){
            printf("key: %d --->", i);
            Node * list = (Node*)hashmap->array[i];
            Node * it = list;
            while(it != NULL){
                printf("%d------", (int*)it->elem);
                it = it->next;
            }
        }
        printf("\n" );
    }
    printf("size prima della disruzione: %d\n", hashmap->size);

    destroy_hashmap(hashmap);

    printf("size dopo : %d\n", hashmap->size);



    return 0;
}
*/
