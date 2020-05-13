#include "hash_map.h"



/*create hashMap empty*/
HashMap* new_HashMap(int capacity){
    HashMap* alloca = (HashMap*)malloc(sizeof(HashMap));
    alloca->array = (void**)calloc(capacity, sizeof(void*));
    alloca->capacity = capacity;
    alloca->size = 0;

    return alloca;
}
void deleteAllNode(HashMap* hashmap){
    for(int i = 0; i<hashmap->capacity; i++){
        if(hashmap->array[i] != NULL){
            Node* head = (Node*)hashmap->array[i];
            Node* prev = head;
            hashmap->array[i] = NULL;

            while(head != NULL){
                head = head->next;
                free(prev);
                prev = head;
                hashmap->size--;
            }
            //free(head);
        }
    }
}

void destroy_hashmap(HashMap* hashmap){
    deleteAllNode(hashmap);
    if(hashmap != NULL){
      free(hashmap);
    }
    //hashmap = NULL;
}

int isEmpty(HashMap* hashmap){
    return hashmap->size == 0;
}

int numberOfElem(HashMap* hashmap){
    return hashmap->size;
}


int isKey(HashMap* map, void* key, int (*compare)(void* a, void* b), int hashFunction){
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


void* get_value(HashMap* map, void* key, int (*compare)(void* a, void* b), int hashFunction){
    if(map->array[hashFunction] == NULL){
        //perror("there is no value for this key");
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
        //perror("the lookup value is not found ");
        return NULL;
    }
}

void insert(HashMap* map, void* key, void* value, int (*compare)(void* a, void* b), int hashFunction){
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

void removeKey(HashMap* map, void* key,int (*compare)(void*a, void*b) ,int hashFunction){
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

ArrayDyn* allKeys(HashMap* map){
    ArrayDyn* arrayDyn = newarrayDyn();
    int count = 0;
    for(int i = 0; i<map->capacity; i++){
        if(map->array[i] != NULL){
            Node* head = (Node*)map->array[i];
            while(head != NULL){
                insertarr(arrayDyn, (long)head->key, count);
                head = head->next;
                count++;
            }
        }
    }
    //for(int i = 0; i<arrayDyn->size;i++)
        //printf("%d\n",arrayDyn->array[i] );
    return arrayDyn;
}
