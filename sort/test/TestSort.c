#include "sort.h"
#include "unity.h"
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

#define SIZE_OF_ARRAY 1000

void setUp(void)
{
}

void tearDown(void)
{
}

// void randomizeArray(int * v, int size){
//   // This is a random key, trust me.
//   srand(89465848948);
//   int id;
//   for(id=0;id<size;id++)
//     v[id] = rand()%size;
// }

const char * get_sort_type(int i){
	switch(i){
        case SELECTION:
            return "Selection";

        case INSERTION:
            return "Insertion";

        case SHELL:
            return "Shell";

        case QUICK:
            return "Quick";

        case HEAP:
            return "Heap";

        case MERGE:
            return "Merge";

        default:
        	return "Undefined";

    }
    return "Undefined";
}

// test with repeated elements
void test_sort2(void){
  int v_original[] = {10,10,10,3,3,1};
  int size = 6;
  int expected[] = {1,3,3,10,10,10};

  for(int i=0; i<6; ++i){
    int * v = (int*)malloc(sizeof(int)*sizeof(v_original));

    memcpy(v, v_original, sizeof(v_original));

    sort_array(v, size, i);
    char error_message[50];
    sprintf(error_message,"Error in Sort %s\n", get_sort_type(i));
    TEST_ASSERT_EQUAL_HEX32_ARRAY_MESSAGE(expected, v, size, error_message);
    free(v);
  }
  sort_array(v_original, size, 7); //code coverage 100%
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
    char error_message[50];
    sprintf(error_message,"Error in Sort %s\n", get_sort_type(i));
    TEST_ASSERT_EQUAL_HEX32_ARRAY_MESSAGE(expected, v, size, error_message);
    free(v);
  }

}

//test with repeated numbers
void test_sort4(void){
  int v_original[] = {5,5,5,5,5,5,5,5};
  int size = 8;
  int expected[] = {5,5,5,5,5,5,5,5};

  for(int i=0; i<6; ++i){
    int * v = (int*)malloc(sizeof(int)*sizeof(v_original));

    memcpy(v, v_original, sizeof(v_original));
    
    sort_array(v, size, i);    
    char error_message[50];
    sprintf(error_message,"Error in Sort %s\n", get_sort_type(i));
    TEST_ASSERT_EQUAL_HEX32_ARRAY_MESSAGE(expected, v, size, error_message);
    free(v);
  }

}

//test with one number
void test_sort5(void){
  int v_original[] = {1};
  int size = 1;
  int expected[] = {1};

  for(int i=0; i<6; ++i){
    int * v = (int*)malloc(sizeof(int)*sizeof(v_original));

    memcpy(v, v_original, sizeof(v_original));
    
    sort_array(v, size, i);    
    char error_message[50];
    sprintf(error_message,"Error in Sort %s\n", get_sort_type(i));
    TEST_ASSERT_EQUAL_HEX32_ARRAY_MESSAGE(expected, v, size, error_message);
    free(v);
  }

}

//test with repeated negative numbers
void test_sort6(void){
  int v_original[] = {-1,-1,-1,-1,-1,-1};
  int size = 6;
  int expected[] = {-1,-1,-1,-1,-1,-1};

  for(int i=0; i<6; ++i){
    int * v = (int*)malloc(sizeof(int)*sizeof(v_original));

    memcpy(v, v_original, sizeof(v_original));
    
    sort_array(v, size, i);
    char error_message[50];
    sprintf(error_message,"Error in Sort %s\n", get_sort_type(i));
    TEST_ASSERT_EQUAL_HEX32_ARRAY_MESSAGE(expected, v, size, error_message);
    free(v);
  }
}

//test with INT_MAX and INT_MIN
void test_sort7(void){
  int v_original[] = {INT_MAX,INT_MIN};
  int size = 2;
  int expected[] = {INT_MIN,INT_MAX};

  for(int i=0; i<6; ++i){
    int * v = (int*)malloc(sizeof(int)*sizeof(v_original));

    memcpy(v, v_original, sizeof(v_original));
    
    sort_array(v, size, i);
    char error_message[50];
    sprintf(error_message,"Error in Sort %s\n", get_sort_type(i));
    TEST_ASSERT_EQUAL_HEX32_ARRAY_MESSAGE(expected, v, size, error_message);
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
void test_sort9(void){
  int v_original[] = {-1,-1,-1,0,-1};
  int expected[] = {-1,-1,-1,0};
  int size = 4;

  for(int i=0; i<6; ++i){
    int * v = (int*)malloc(sizeof(int)*sizeof(v_original));

    memcpy(v, v_original, sizeof(v_original));
    
    sort_array(v, size, i);
    char error_message[50];
    sprintf(error_message,"Error in Sort %s\n", get_sort_type(i));
    TEST_ASSERT_EQUAL_HEX32_ARRAY_MESSAGE(expected, v, size, error_message);
    free(v);
  }
}

//test if subset is untouched
void test_sort10(void){
  int v_original[10] = {3, 2, 1, 0, -1, 1, 0, -1, 1, 0};
  int expected[] = {1, 2, 3, 0, -1, 1, 0, -1, 1, 0};
  int size = 3;

  for(int i=0; i<6; ++i){
    int * v = (int*)malloc(sizeof(int)*sizeof(v_original));

    memcpy(v, v_original, sizeof(v_original));
    
    sort_array(v, size, i);
    char error_message[50];
    sprintf(error_message,"Error in Sort %s\n", get_sort_type(i));
    TEST_ASSERT_EQUAL_HEX32_ARRAY_MESSAGE(expected, v, 10, error_message);
    free(v);
  }
}

//test array of unsigned int
void test_sort11(void){
  unsigned int v_original[] = {3, 2, 1};
  unsigned int expected[] = {1, 2, 3};
  int size = 3;

  for(int i=0; i<6; ++i){
    unsigned int * v = (unsigned int*)malloc(sizeof(int)*sizeof(v_original));

    memcpy(v, v_original, sizeof(v_original));
    sort_array((int*)v, size, i);
    char error_message[50];
    sprintf(error_message,"Error in Sort %s\n", get_sort_type(i));
    TEST_ASSERT_EQUAL_HEX32_ARRAY_MESSAGE(expected, v, size, error_message);
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
    TEST_ASSERT_EQUAL_HEX32_ARRAY_MESSAGE(expected, v, size, ("Error in Sort %s\n", get_sort_type(i)));
    free(v);
  }
}*/

//test sort in the boudaries
void test_sort14(void){
  int v_original[] = {INT_MAX-2, INT_MAX-1, INT_MAX, INT_MIN+2, INT_MIN+1, INT_MIN};
  int expected[] = {INT_MIN, INT_MIN+1, INT_MIN+2, INT_MAX-2, INT_MAX-1, INT_MAX};
  int size = 6; 

  for(int i=0; i<6; ++i){
    int * v = (int*)malloc(sizeof(int)*sizeof(v_original));

    memcpy(v, v_original, sizeof(v_original));
    
    sort_array(v, size, i);
    char error_message[50];
    sprintf(error_message,"Error in Sort %s\n", get_sort_type(i));
    TEST_ASSERT_EQUAL_HEX32_ARRAY_MESSAGE(expected, v, size, error_message);
    free(v);
  }
}

//test sorting only a subset of the array using the boundaries
void test_sort15(void){
  int v_original[] = {INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MIN};
  int expected[] = {INT_MIN, INT_MAX};
  int expected2[] = {INT_MAX, INT_MIN, INT_MIN};
  int size = 2; 

  for(int i=0; i<6; ++i){
    int * v = (int*)malloc(sizeof(int)*sizeof(v_original));

    memcpy(v, v_original, sizeof(v_original));
    
    sort_array(v, size, i);
    char error_message[50];
    sprintf(error_message,"Error in Sort %s\n", get_sort_type(i));
    TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(expected, v, size,error_message);
    TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(expected2, &v[2], 3,error_message);
    free(v);
  }
}
