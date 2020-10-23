#include "identifier.h"
#include "unity.h"
#include <stdio.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_payment_classe_equivalencia_1(void){
  char ident[10] = "abc123";

  char * returned = identifier(ident);

  TEST_ASSERT_EQUAL_STRING("Valido", returned);
}

void test_payment_classe_equivalencia_2(void){
  char ident[10] = "abc1234";

  char * returned = identifier(ident);

  TEST_ASSERT_EQUAL_STRING("Invalido", returned);
}

void test_payment_classe_equivalencia_3(void){
  char ident[10] = "";

  char * returned = identifier(ident);

  TEST_ASSERT_EQUAL_STRING("Invalido", returned);
}

void test_payment_classe_equivalencia_4(void){
  char ident[10] = "4abc";

  char * returned = identifier(ident);

  TEST_ASSERT_EQUAL_STRING("Invalido", returned);
}

void test_payment_classe_equivalencia_5(void){
  char ident[10] = "abc$2";

  char * returned = identifier(ident);

  TEST_ASSERT_EQUAL_STRING("Invalido", returned);
}