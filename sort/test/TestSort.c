#include "sort.h"
#include "unity.h"
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

#define SIZE_OF_ARRAY 1000
#define BIG_ARRAY 10000

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

void test_init(void){
  sort_array(NULL, 0, -1); // 100% coverage
}

// test with already ordered
/*void test_already_ordered(void){
  int v_original[] = {0,1,2,3,4,5,6,7,8,9};
  int size = 10;
  int expected[] = {0,1,2,3,4,5,6,7,8,9};

  for(int i=0; i<6; ++i){
    int * v = (int*)malloc(sizeof(int)*sizeof(v_original));

    memcpy(v, v_original, sizeof(v_original));

    sort_array(v, size, i);
    char error_message[50];
    sprintf(error_message,"Error in Sort %s\n", get_sort_type(i));
    TEST_ASSERT_EQUAL_HEX32_ARRAY_MESSAGE(expected, v, size, error_message);
    free(v);
  }
}*/

// test with repeated elements
void test_repeated_elements(void){
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
}

// regular test
void test_regular(void){
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

//test with same numbers
void test_same_elements(void){
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

//test with one element
void test_one_element(void){
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
void test_repeated_negative(void){
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

//test BIG_ARRAY rand elements with LOG_n checking
void test_big_array(void){

  int v_original[BIG_ARRAY]; 
  int size = BIG_ARRAY;
  int id;
  // This is a random key, trust me.
  srand(894658488);
  for(id=0;id<BIG_ARRAY;id++)
    v_original[id] = rand()%BIG_ARRAY;

  for(int i=0; i<6; ++i){
    int * v = (int*)malloc(sizeof(int)*sizeof(v_original));

    memcpy(v, v_original, sizeof(v_original));
    
    sort_array(v, size, i);
    char error_message[50];
    sprintf(error_message,"Error in Sort %s\n", get_sort_type(i));
    // for 10K elements ->
    // 4999     9999
    // 2499     4999
    // ...
    // 2        4
    // 1        2
    for(id=size-1; ; ){
      if(v[id] != v[id/2])
        TEST_ASSERT_LESS_THAN_MESSAGE(v[id], v[id/2], error_message);
      id = (int)id/2;
      if(id/2==0) break;
    }
    free(v);
  }
}

//test subset with negative numbers
void test_subset_negative(void){
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
void test_subset_untouched(void){
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
void test_unsigned_int(void){
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

//test sort in the boudaries
void test_boundaries(void){
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
void test_subset_boundaries(void){
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
