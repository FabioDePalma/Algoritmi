#include <stdio.h>
#include "../sort.h"
#include "../Unity/unity.h"

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


static void print_array(Array* array) {

    for(int i = 0; i<array_size(array);i++){
        printf("%d ", (int)array_get(array, i));
    }
    printf("\n");
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


int main() {
    UNITY_BEGIN();

    RUN_TEST(create_test_obj_test);
    RUN_TEST(insertionSort_test_descending);
    RUN_TEST(insertionSort_test_ascending);

    UNITY_END();
}
