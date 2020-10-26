// ----------------------------------------------------------------
// ESPECIFICAÇÃO: O programa deve determinar se um identificador
// é ou não válido. Um identificador válido deve começar com uma
// letra e conter apenas letras ou dígitos. Além disto, deve ter
// no mínimo 1 caractere e no máximo 6 caracteres de comprimento
// ----------------------------------------------------------------

#include <stdio.h>

int valid_s(char ch) {
  if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')))
    return 1;
  else
    return 0;
}

int valid_f(char ch) {
  if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')) || ((ch >= '0') && (ch <= '9')))
    return 1;
  else
    return 0;
}

const char * identifier(char * ident){
  char achar;
  int  length, valid_id;
  length = 0;
  //printf("Identificador: ");
  //achar = fgetc(ident);
  achar = ident[length];
  valid_id = valid_s(achar);
  if(valid_id) {
    length = 1;
  }
  //achar = fgetc(ident);
  achar = ident[length];
  //while(achar != '\n') {
  while(achar != '\0') {
    if(!(valid_f(achar))) {
      valid_id = 0;
    }
    length++;
    //achar = fgetc(ident);
    achar = ident[length];
  }
  if (valid_id && (length >= 1) && (length < 6)) {
  //if (valid_id && (length >= 1) && (length <= 6)) {
    //printf("Valido\n");
    return "Valido";
  }
  else {
    //printf("Invalido\n");
    return "Invalido";
  }
}