#include "read_input.h"

char **read(const char* filename, size_t *s){
  FILE *f = fopen(filename, "rt");
  if(f == NULL)
    return NULL;
  fseek(f, 0, SEEK_END);
  long fsize = ftell(f);
  fseek(f, 0, SEEK_SET);

  char **res = malloc(sizeof(char*));
  *s = 0;

  char *string = malloc(fsize + 1);
  fread(string, fsize, 1, f);

  for(char *split = strtok(string, ","); split != NULL; split = strtok(NULL, ",\n")){
    (*s)++;
    res = realloc(res, sizeof(char*)*(*s));
    res[(*s)-1] = malloc(sizeof(char)*strlen(split));
    strcpy(res[(*s)-1], split);
  }
  return res;
}
