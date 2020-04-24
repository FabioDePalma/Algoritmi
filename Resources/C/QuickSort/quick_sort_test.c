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
    //return (aa- bb)/FLT_EPSILON ; ///////////////////////// //FUNZIONA SOLO CON IL TEST
    if(aa - bb < 0){
        return -1;
    }else{
        return 1;
    }
}
int compare_string(void* a, void*b){
    char* aa = *(char**)a;
    char* bb = *(char**)b;
    return strcmp(aa, bb);
}


static Array* create_test_objects_int() {
    Array* array = array_new(5);
    array_insert(array, int_new(6), 0);
    array_insert(array, int_new(3), 1);
    array_insert(array, int_new(1), 2);
    array_insert(array, int_new(7), 3);
    array_insert(array, int_new(0), 4);

    return array;
}

static void remove_elem(Array* array){
    for(int i = 0; i<array_size(array)-1; i++){
        free(array_get(array, i));
    }
    array_free(array);
}
static void create_test_obj_test_int(){
    Array* array = create_test_objects_int();

    TEST_ASSERT_EQUAL(6, *(int*)array_get(array, 0));
    TEST_ASSERT_EQUAL(3, *(int*)array_get(array, 1));
    TEST_ASSERT_EQUAL(1, *(int*)array_get(array, 2));
    TEST_ASSERT_EQUAL(7, *(int*)array_get(array, 3));
    TEST_ASSERT_EQUAL(0, *(int*)array_get(array, 4));

    remove_elem(array);

}


static void quickSort_test_int(){
    Array* array = create_test_objects_int();
    quickSort(array, compare_ints,0, 4);
    TEST_ASSERT_EQUAL(0, *(int*)array_get(array, 0));
    TEST_ASSERT_EQUAL(1, *(int*)array_get(array, 1));
    TEST_ASSERT_EQUAL(3, *(int*)array_get(array, 2));
    TEST_ASSERT_EQUAL(6, *(int*)array_get(array, 3));
    TEST_ASSERT_EQUAL(7, *(int*)array_get(array, 4));


    remove_elem(array);
}








static float* float_new(float n) {
    float* result = (float*) malloc(sizeof(float));
    *result = n;

    return result;
}
static Array* create_test_objects_float() {
    Array* array = array_new(5);
    array_insert(array, float_new(10.5556), 0);
    array_insert(array, float_new(10.6858), 1);
    array_insert(array, float_new(10.5853), 2);
    array_insert(array, float_new(9.5557), 3);
    array_insert(array, float_new(10.6859), 4);

    return array;
}

static void create_test_obj_test_float(){
    Array* array = create_test_objects_float();

    TEST_ASSERT_EQUAL_FLOAT(10.5556, *(float*)array_get(array, 0));
    TEST_ASSERT_EQUAL_FLOAT(10.6858, *(float*)array_get(array, 1));
    TEST_ASSERT_EQUAL_FLOAT(10.5853, *(float*)array_get(array, 2));
    TEST_ASSERT_EQUAL_FLOAT(9.5557, *(float*)array_get(array, 3));
    TEST_ASSERT_EQUAL_FLOAT(10.6859, *(float*)array_get(array, 4));

    remove_elem(array);

}


static void quickSort_test_float(){
    Array* array = create_test_objects_float();
    quickSort(array, compare_float,0, 4);
    TEST_ASSERT_EQUAL_FLOAT(9.5557, *(float*)array_get(array, 0));
    TEST_ASSERT_EQUAL_FLOAT(10.5556, *(float*)array_get(array, 1));
    TEST_ASSERT_EQUAL_FLOAT(10.5853, *(float*)array_get(array, 2));
    TEST_ASSERT_EQUAL_FLOAT(10.6858, *(float*)array_get(array, 3));
    TEST_ASSERT_EQUAL_FLOAT(10.6859, *(float*)array_get(array, 4));

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

static void quickSort_test_string(){
    Array* array = create_test_objects_string();
    quickSort(array, compare_string,0, 4);
    TEST_ASSERT_EQUAL_STRING("ansia", *(char**)array_get(array, 0));
    TEST_ASSERT_EQUAL_STRING("c", *(char**)array_get(array, 1));
    TEST_ASSERT_EQUAL_STRING("casa", *(char**)array_get(array, 2));
    TEST_ASSERT_EQUAL_STRING("ciao", *(char**)array_get(array, 3));
    TEST_ASSERT_EQUAL_STRING("odio", *(char**)array_get(array, 4));

    remove_elem(array);

}




int main() {
    UNITY_BEGIN();

    RUN_TEST(create_test_obj_test_int);
    RUN_TEST(quickSort_test_int);
    RUN_TEST(create_test_obj_test_float);
    RUN_TEST(quickSort_test_float);
    RUN_TEST(create_test_obj_test_string);
    RUN_TEST(quickSort_test_string);
    UNITY_END();
}
