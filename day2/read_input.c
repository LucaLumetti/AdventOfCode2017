#include "read_input.h"

void read_row(FILE *input, int **arr, size_t *size){
  int num = 0;
  *size = 0;
  *arr = malloc(*size);

  for(;;){
    char c = fgetc(input);
    if(c == EOF)
      break;
    if(c != '\t' && c != '\n'){
      num *= 10;
      num += c - '0';
    }else{
      (*size)++;
      *arr = realloc(*arr, *size * sizeof(int));
      (*arr)[(*size)-1] = num;
      num = 0;
      if(c == '\n')
        return;
    }
  }
  return;
}
