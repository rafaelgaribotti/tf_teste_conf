#include "sort.h"
#include "unity.h"
#include <stdio.h>
#include <limits.h>

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

void test_selection_sort(void){

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

}
