#include "read_input.h"

int read(int *input){
  FILE *f = fopen("input", "rt");
  if(f == NULL)
    return 0;
  fscanf(f,"%d",input);
  return 1;
}
