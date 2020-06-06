#include "hash_map.h"
#include "../Unity/unity.h"
//#include "arrayDyn.h"


int hashFun(HashMap* map, int value){
    return value % map->capacity;
}
int compareint(void* a, void* b) {
    int* aa = (int*)a;
    int* bb = (int*)b;
    return aa - bb;
}
static HashMap* create_new_objects_empty(){
    HashMap* hashmap = new_HashMap(5);
    return hashmap;
}
static HashMap* create_new_objects(){
    HashMap* hashmap = new_HashMap(5);

    int hash;
    hash = hashFun(hashmap, 1) ;
    insert(hashmap, (int*)1 , (int*)100, compareint, hash);
    hash = hashFun(hashmap, 2);
    insert(hashmap, (int*)2, (int*)200, compareint, hash);
    hash = hashFun(hashmap, 3);
    insert(hashmap, (int*)3, (int*)300, compareint, hash);
    hash = hashFun(hashmap, 4);
    insert(hashmap, (int*)4, (int*)400, compareint, hash);
    hash = hashFun(hashmap, 5);
    insert(hashmap, (int*)5, (int*)500, compareint, hash);
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

    return hashmap;
}

static void create_new_objects_test(){
    HashMap* hashmap = create_new_objects();
    TEST_ASSERT_EQUAL(100, (int*)get_value(hashmap, (int*)1, compareint, hashFun(hashmap,1)));
    TEST_ASSERT_EQUAL(200, (int*)get_value(hashmap, (int*)2, compareint, hashFun(hashmap,2)));
    TEST_ASSERT_EQUAL(300, (int*)get_value(hashmap, (int*)3, compareint, hashFun(hashmap,3)));
    TEST_ASSERT_EQUAL(400, (int*)get_value(hashmap, (int*)4, compareint, hashFun(hashmap,4)));
    TEST_ASSERT_EQUAL(500, (int*)get_value(hashmap, (int*)5, compareint, hashFun(hashmap,5)));
    TEST_ASSERT_EQUAL(600, (int*)get_value(hashmap, (int*)6, compareint, hashFun(hashmap,6)));
    TEST_ASSERT_EQUAL(700, (int*)get_value(hashmap, (int*)7, compareint, hashFun(hashmap,7)));
    TEST_ASSERT_EQUAL(800, (int*)get_value(hashmap, (int*)8, compareint, hashFun(hashmap,8)));
    TEST_ASSERT_EQUAL(900, (int*)get_value(hashmap, (int*)9, compareint, hashFun(hashmap,9)));
    TEST_ASSERT_EQUAL(1000,(int*)get_value(hashmap, (int*)10,compareint, hashFun(hashmap,10)));

    destroy_hashmap(hashmap);

}

static void test_empty(){
    HashMap* hashmap = create_new_objects_empty();
    TEST_ASSERT_EQUAL(true, isEmpty(hashmap));
    destroy_hashmap(hashmap);

}

static void test_numberOfElem(){
    HashMap* hashmap = create_new_objects();
    TEST_ASSERT_EQUAL(10, numberOfElem(hashmap));
    destroy_hashmap(hashmap);

}
static void test_removeKey(){
    HashMap* hashmap = create_new_objects();
    removeKey(hashmap, (int*)4, compareint, hashFun(hashmap,4));
    removeKey(hashmap, (int*)9, compareint, hashFun(hashmap,9));
    TEST_ASSERT_EQUAL(100, (int*)get_value(hashmap, (int*)1, compareint, hashFun(hashmap,1)));
    TEST_ASSERT_EQUAL(200, (int*)get_value(hashmap, (int*)2, compareint, hashFun(hashmap,2)));
    TEST_ASSERT_EQUAL(300, (int*)get_value(hashmap, (int*)3, compareint, hashFun(hashmap,3)));
    TEST_ASSERT_EQUAL(NULL, hashmap->array[hashFun(hashmap,4)]);
    TEST_ASSERT_EQUAL(500, (int*)get_value(hashmap, (int*)5, compareint, hashFun(hashmap,5)));
    TEST_ASSERT_EQUAL(600, (int*)get_value(hashmap, (int*)6, compareint, hashFun(hashmap,6)));
    TEST_ASSERT_EQUAL(700, (int*)get_value(hashmap, (int*)7, compareint, hashFun(hashmap,7)));
    TEST_ASSERT_EQUAL(800, (int*)get_value(hashmap, (int*)8, compareint, hashFun(hashmap,8)));
    TEST_ASSERT_EQUAL(1000, (int*)get_value(hashmap, (int*)10, compareint, hashFun(hashmap,10)));
    TEST_ASSERT_EQUAL(8, hashmap->size);


    destroy_hashmap(hashmap);
}
static void test_deleteAllNodes(){
    HashMap* hashmap = create_new_objects();
    deleteAllNode(hashmap);
    TEST_ASSERT_EQUAL(0, hashmap->size);

    destroy_hashmap(hashmap);
}
static void test_allKeys(){
    HashMap* hashmap = create_new_objects();

    removeKey(hashmap, (int*)1, compareint, hashFun(hashmap,1));
    removeKey(hashmap, (int*)6, compareint, hashFun(hashmap,6));

    ArrayDyn* array = allKeys(hashmap);
    TEST_ASSERT_EQUAL(10, arrayDyn_get(array,0));
    TEST_ASSERT_EQUAL(5, arrayDyn_get(array,1));
    TEST_ASSERT_EQUAL(7, arrayDyn_get(array,2));
    TEST_ASSERT_EQUAL(2, arrayDyn_get(array,3));

}


int main() {
    UNITY_BEGIN();

    RUN_TEST(create_new_objects_test);
    RUN_TEST(test_empty);
    RUN_TEST(test_numberOfElem);
    RUN_TEST(test_removeKey);
    RUN_TEST(test_deleteAllNodes);
    RUN_TEST(test_allKeys);


    UNITY_END();


}

//gcc hash_map_test.c hash_map.c arrayDyn.c ../Unity/unity.c
