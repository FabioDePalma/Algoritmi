#include <stdio.h>
#include <stdlib.h>
#include "../sort.h"
#include "../Unity/unity.h"
#include <string.h>

static int* int_new(int n) {
    int* result = (int*) malloc(sizeof(int));
    *result = n;

    return result;
}

static int compare_ints(void* a, void* b) {
    int int1 = *(int*) a;
    int int2 = *(int*) b;
    return int1 - int2;
}

static int compare_float(void* a, void* b) {
    float aa = *(float*)a;
    float bb = *(float*)b;
    if(aa- bb< 0){
        return -1;
    }else if(aa - bb> 0 ){
        return 1;
    }else{
        return 0;
    }
}

static int compare_string(void* a, void*b){
    char* aa = *(char**)a;
    char* bb = *(char**)b;
    return strcmp(aa, bb);
}


static Array* create_test_objects() {
    Array* array = array_new(5);
    array_insert(array, int_new(6), 0);
    array_insert(array, int_new(3), 1);
    array_insert(array, int_new(1), 2);
    array_insert(array, int_new(7), 3);
    array_insert(array, int_new(0), 4);

    return array;
}

static void remove_elem(Array* array){
    for(int i = 0; i<array_size(array); i++){
        free(array_get(array, i));
    }
    array_free(array);
}
static void create_test_obj_test(){
    Array* array = create_test_objects();

    TEST_ASSERT_EQUAL(6, *(int*)array_get(array, 0));
    TEST_ASSERT_EQUAL(3, *(int*)array_get(array, 1));
    TEST_ASSERT_EQUAL(1, *(int*)array_get(array, 2));
    TEST_ASSERT_EQUAL(7, *(int*)array_get(array, 3));
    TEST_ASSERT_EQUAL(0, *(int*)array_get(array, 4));



    remove_elem(array);

}


static void insertionSort_test_ascending(){
    Array* array = create_test_objects();
    insertionSort(array, compare_ints, 1);
    TEST_ASSERT_EQUAL(0, *(int*)array_get(array, 0));
    TEST_ASSERT_EQUAL(1, *(int*)array_get(array, 1));
    TEST_ASSERT_EQUAL(3, *(int*)array_get(array, 2));
    TEST_ASSERT_EQUAL(6, *(int*)array_get(array, 3));
    TEST_ASSERT_EQUAL(7, *(int*)array_get(array, 4));

    remove_elem(array);
}

static void insertionSort_test_descending(){
    Array* array = create_test_objects();
    insertionSort(array, compare_ints, -1);
    TEST_ASSERT_EQUAL_INT(7, *(int*)array_get(array, 0));
    TEST_ASSERT_EQUAL_INT(6, *(int*)array_get(array, 1));
    TEST_ASSERT_EQUAL_INT(3, *(int*)array_get(array, 2));
    TEST_ASSERT_EQUAL_INT(1, *(int*)array_get(array, 3));
    TEST_ASSERT_EQUAL_INT(0, *(int*)array_get(array, 4));

    remove_elem(array);
}











static float* float_new(float n) {
    float* result = (float*) malloc(sizeof(float));
    *result = n;

    return result;
}
static Array* create_test_objects_float() {
    Array* array = array_new(5);
    array_insert(array, float_new(1.555), 0);
    array_insert(array, float_new(0.6858), 1);
    array_insert(array, float_new(0.5853), 2);
    array_insert(array, float_new(1.666), 3);
    array_insert(array, float_new(0.6811), 4);

    return array;
}

static void create_test_obj_test_float(){
    Array* array = create_test_objects_float();

    TEST_ASSERT_EQUAL(1.555, *(float*)array_get(array, 0));
    TEST_ASSERT_EQUAL(0.6858, *(float*)array_get(array, 1));
    TEST_ASSERT_EQUAL(0.5853, *(float*)array_get(array, 2));
    TEST_ASSERT_EQUAL(1.666, *(float*)array_get(array, 3));
    TEST_ASSERT_EQUAL(0.6811, *(float*)array_get(array, 4));

    remove_elem(array);

}


static void insertionSort_test_float(){
    Array* array = create_test_objects_float();
    insertionSort(array, compare_float,1);
    TEST_ASSERT_EQUAL(0.5853, *(float*)array_get(array, 0));
    TEST_ASSERT_EQUAL(0.6811, *(float*)array_get(array, 1));
    TEST_ASSERT_EQUAL(0.6858, *(float*)array_get(array, 2));
    TEST_ASSERT_EQUAL(1.555, *(float*)array_get(array, 3));
    TEST_ASSERT_EQUAL(1.666, *(float*)array_get(array, 4));

    remove_elem(array);

}



static char** string_new(char* n) {
    char** result = (char**) malloc(sizeof(char)*10);
    *result = n;

    return result;
}
static Array* create_test_objects_string() {
    Array* array = array_new(5);
    array_insert(array, string_new("ciao"), 0);
    array_insert(array, string_new("casa"), 1);
    array_insert(array, string_new("ansia"), 2);
    array_insert(array, string_new("odio"), 3);
    array_insert(array, string_new("c"), 4);
    return array;
}

static void create_test_obj_test_string(){
    Array* array = create_test_objects_string();

    TEST_ASSERT_EQUAL_STRING("ciao", *(char**)array_get(array, 0));
    TEST_ASSERT_EQUAL_STRING("casa", *(char**)array_get(array, 1));
    TEST_ASSERT_EQUAL_STRING("ansia", *(char**)array_get(array, 2));
    TEST_ASSERT_EQUAL_STRING("odio", *(char**)array_get(array, 3));
    TEST_ASSERT_EQUAL_STRING("c", *(char**)array_get(array, 4));

    remove_elem(array);

}

static void insertionSort_test_string(){
    Array* array = create_test_objects_string();
    insertionSort(array, compare_string,1);
    TEST_ASSERT_EQUAL_STRING("ansia", *(char**)array_get(array, 0));
    TEST_ASSERT_EQUAL_STRING("c", *(char**)array_get(array, 1));
    TEST_ASSERT_EQUAL_STRING("casa", *(char**)array_get(array, 2));
    TEST_ASSERT_EQUAL_STRING("ciao", *(char**)array_get(array, 3));
    TEST_ASSERT_EQUAL_STRING("odio", *(char**)array_get(array, 4));

    remove_elem(array);

}

int main() {
    UNITY_BEGIN();

    RUN_TEST(create_test_obj_test);
    RUN_TEST(insertionSort_test_descending);
    RUN_TEST(insertionSort_test_ascending);
    RUN_TEST(create_test_obj_test_float);
    RUN_TEST(insertionSort_test_float);
    RUN_TEST(create_test_obj_test_string);
    RUN_TEST(insertionSort_test_string);
    UNITY_END();
}
