#include "sort.h"
#include "unity.h"
#include <stdio.h>
#include <limits.h>
#include <string.h>

#define SIZE_OF_ARRAY 1000

void setUp(void)
{
}

void tearDown(void)
{
}

void randomizeArray(int * v, int size){
  // This is a random key, trust me.
  srand(89465848948);
  int id;
  for(id=0;id<size;id++)
    v[id] = rand()%size;
}

// test with empty array, simply should not break the code
/*void test_sort1(void){
  int v_original[] = {};
  int size = 0;
  int expected[] = {};

  for(int i=0; i<6; ++i){
    int * v = (int*)malloc(sizeof(int)*size);

    memcpy(v, v_original, size);
    
    v = sort_array(v, size, i);
    //TEST_ASSERT_EQUAL_HEX32_ARRAY(expected, v, size);
    free(v);
  }

}*/

// test with repeated elements
void test_sort2(void){
  int v_original[] = {10,10,10,3,3,1};
  int size = 6;
  int expected[] = {1,3,3,10,10,10};

  for(int i=0; i<6; ++i){
    int * v = (int*)malloc(sizeof(int)*sizeof(v_original));

    memcpy(v, v_original, sizeof(v_original));

    sort_array(v, size, i);

    TEST_ASSERT_EQUAL_HEX32_ARRAY(expected, v, size);
    free(v);
  }

}

// regular test
void test_sort3(void){
  int v_original[] = {10,9,8,7,6,5,4,3,2,-10};
  int size = 10;
  int expected[] = {-10,2,3,4,5,6,7,8,9,10};

  for(int i=0; i<6; ++i){
    int * v = (int*)malloc(sizeof(int)*sizeof(v_original));

    memcpy(v, v_original, sizeof(v_original));
    
    sort_array(v, size, i);
    TEST_ASSERT_EQUAL_HEX32_ARRAY(expected, v, size);
    free(v);
  }

}

//test with repeated numbers
void test_sort4(){
  int v_original[] = {5,5,5,5,5,5,5,5};
  int size = 8;
  int expected[] = {5,5,5,5,5,5,5,5};

  for(int i=0; i<6; ++i){
    int * v = (int*)malloc(sizeof(int)*sizeof(v_original));

    memcpy(v, v_original, sizeof(v_original));
    
    sort_array(v, size, i);
    TEST_ASSERT_EQUAL_HEX32_ARRAY(expected, v, size);
    free(v);
  }

}

//test with one number
void test_sort5(){
  int v_original[] = {1};
  int size = 1;
  int expected[] = {1};

  for(int i=0; i<6; ++i){
    int * v = (int*)malloc(sizeof(int)*sizeof(v_original));

    memcpy(v, v_original, sizeof(v_original));
    
    sort_array(v, size, i);
    TEST_ASSERT_EQUAL_HEX32_ARRAY(expected, v, size);
    free(v);
  }

}

//test with repeated negative numbers
void test_sort6(){
  int v_original[] = {-1,-1,-1,-1,-1,-1};
  int size = 6;
  int expected[] = {-1,-1,-1,-1,-1,-1};

  for(int i=0; i<6; ++i){
    int * v = (int*)malloc(sizeof(int)*sizeof(v_original));

    memcpy(v, v_original, sizeof(v_original));
    
    sort_array(v, size, i);
    TEST_ASSERT_EQUAL_HEX32_ARRAY(expected, v, size);
    free(v);
  }
}

//test with INT_MAX and INT_MIN
void test_sort7(){
  int v_original[] = {INT_MAX,INT_MIN};
  int size = 2;
  int expected[] = {INT_MIN,INT_MAX};

  for(int i=0; i<6; ++i){
    int * v = (int*)malloc(sizeof(int)*sizeof(v_original));

    memcpy(v, v_original, sizeof(v_original));
    
    sort_array(v, size, i);
    TEST_ASSERT_EQUAL_HEX32_ARRAY(expected, v, size);
    free(v);
  }

}

//test BIG_ARRAY rand elements with LOG_n checking
/*void test_sort8(){

  int v[BIG_ARRAY]; 
  int size = BIG_ARRAY;
  int id;
  // This is a random key, trust me.
  srand(89465848948);
  for(id=0;id<BIG_ARRAY;id++)
    v[id] = rand()%BIG_ARRAY;

  sort(v,size);

  // for 10K elements ->
  // 4999     9999
  // 2499     4999
  // ...
  // 2        4
  // 1        2

  for(id=size-1; ; ){
    if(v[id] != v[id/2])
      TEST_ASSERT_LESS_THAN(v[id], v[id/2]);
    id = (int)id/2;
    if(id/2==0) break;
  }

}*/

//test subset with negative numbers
void test_sort9(){
  int v_original[] = {-1,-1,-1,0,-1};
  int expected[] = {-1,-1,-1,0};
  int size = 4;

  for(int i=0; i<6; ++i){
    int * v = (int*)malloc(sizeof(int)*sizeof(v_original));

    memcpy(v, v_original, sizeof(v_original));
    
    sort_array(v, size, i);
    TEST_ASSERT_EQUAL_HEX32_ARRAY(expected, v, size);
    free(v);
  }
}

//test if subset is untouched
void test_sort10(){
  int v_original[10] = {3, 2, 1, 0, -1, 1, 0, -1, 1, 0};
  int expected[] = {1, 2, 3, 0, -1, 1, 0, -1, 1, 0};
  int size = 3;

  for(int i=0; i<6; ++i){
    int * v = (int*)malloc(sizeof(int)*sizeof(v_original));

    memcpy(v, v_original, sizeof(v_original));
    
    sort_array(v, size, i);
    TEST_ASSERT_EQUAL_HEX32_ARRAY(expected, v, 10);
    free(v);
  }
}

//test array of unsigned int
void test_sort11(){
  unsigned int v_original[] = {3, 2, 1};
  unsigned int expected[] = {1, 2, 3};
  int size = 3;

  for(int i=0; i<6; ++i){
    unsigned int * v = (unsigned int*)malloc(sizeof(int)*sizeof(v_original));

    memcpy(v, v_original, sizeof(v_original));
    
    sort_array(v, size, i);
    TEST_ASSERT_EQUAL_HEX32_ARRAY(expected, v, size);
    free(v);
  }
}

//test sizeof vector before and after
/*void test_sort12(){
  int v[BIG_ARRAY]; 
  int size = BIG_ARRAY;
  int id;
  // This is a random key, trust me.
  srand(89465848948);
  for(id=0;id<BIG_ARRAY;id++)
    v[id] = rand()%BIG_ARRAY;

  int array_size_init = sizeof(v);

  sort(v,size);

  int array_size_end = sizeof(v);


  TEST_ASSERT_EQUAL_INT(array_size_init, array_size_end);
}*/

//test wrong size
/*void test_sort13(){
  int v_original = 1;
  int expected = 1;
  int size = 3; 

  for(int i=0; i<6; ++i){
    int * v = (int*)malloc(sizeof(int)*size);

    memcpy(v, v_original, sizeof(v_original));
    
    sort_array(v, size-1, i);
    TEST_ASSERT_EQUAL_HEX32_ARRAY(expected, v, size);
    free(v);
  }
}*/

//test sort in the boudaries
void test_sort14(){
  int v_original[] = {INT_MAX-2, INT_MAX-1, INT_MAX, INT_MIN+2, INT_MIN+1, INT_MIN};
  int expected[] = {INT_MIN, INT_MIN+1, INT_MIN+2, INT_MAX-2, INT_MAX-1, INT_MAX};
  int size = 6; 

  for(int i=0; i<6; ++i){
    int * v = (int*)malloc(sizeof(int)*sizeof(v_original));

    memcpy(v, v_original, sizeof(v_original));
    
    sort_array(v, size, i);
    TEST_ASSERT_EQUAL_HEX32_ARRAY(expected, v, size);
    free(v);
  }
}

//test sorting only a subset of the array using the boundaries
void test_sort15(){
  int v_original[] = {INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MIN};
  int expected[] = {INT_MIN, INT_MAX};
  int expected2[] = {INT_MAX, INT_MIN, INT_MIN};
  int size = 2; 

  for(int i=0; i<6; ++i){
    int * v = (int*)malloc(sizeof(int)*sizeof(v_original));

    memcpy(v, v_original, sizeof(v_original));
    
    sort_array(v, size, i);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, v, size);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected2, &v[2], 3);
    free(v);
  }
}

/*void test_selection_sort(void){

  int size = SIZE_OF_ARRAY;
  int *vet = (int*)malloc(sizeof(int)*size);
  randomizeArray(vet,size);

  // Aqui vamos fazer todas classes do selection sort
  selection_sort(vet,size);

  free(vet);

}

void test_insertion_sort(void){

  int size = SIZE_OF_ARRAY;
  int *vet = (int*)malloc(sizeof(int)*size);
  randomizeArray(vet,size);

  // Aqui vamos fazer todas classes do insertion sort
  insertion_sort(vet,size);

  free(vet);

}

void test_shell_sort(void){

  int size = SIZE_OF_ARRAY;
  int *vet = (int*)malloc(sizeof(int)*size);
  randomizeArray(vet,size);

  // Aqui vamos fazer todas classes do shell sort
  shell_sort(vet,size);

  free(vet);

}

void test_quick_sort(void){

  int size = SIZE_OF_ARRAY;
  int *vet = (int*)malloc(sizeof(int)*size);
  randomizeArray(vet,size);

  // Aqui vamos fazer todas classes do quick sort
  // quick_sort(vet,0,size);

  free(vet);

}

void test_heap_sort(void){

  int size = SIZE_OF_ARRAY;
  int *vet = (int*)malloc(sizeof(int)*size);
  randomizeArray(vet,size);

  // Aqui vamos fazer todas classes do heap sort
  heap_sort(vet,size);

  free(vet);

}

void test_merge_sort(void){

  int size = SIZE_OF_ARRAY;
  int *vet = (int*)malloc(sizeof(int)*size);
  randomizeArray(vet,size);

  // Aqui vamos fazer todas classes do merge sort
  merge_sort(vet,size);

  free(vet);

}*/
