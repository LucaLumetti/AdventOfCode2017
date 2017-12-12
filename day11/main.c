#include <stdlib.h>
#include <stdio.h>
#include "hex_dir.h"
#include "read_input.h"
int main(void){
  int coords[3] = {0, 0, 0};

  char n[] = {0, -1, 1};
  char ne[] = {-1, 0, 1};
  char nw[] = {1, -1, 0};

  char s[] = {0, 1, -1};
  char se[] = {-1, 1, 0};
  char sw[] = {1, 0, -1};

  int max = 0;
  size_t size = 3;
  size_t dir_size = 0;
  char **input = read("./input", &dir_size);
  for(int i = 0; i < dir_size; i++){
    if(strcmp("s", input[i]))
      arr_sum(coords, s, size);
    if(strcmp("se", input[i]))
      arr_sum(coords, se, size);
    if(strcmp("sw", input[i]))
      arr_sum(coords, sw, size);
    if(strcmp("n", input[i]))
      arr_sum(coords, n, size);
    if(strcmp("ne", input[i]))
      arr_sum(coords, ne, size);
    if(strcmp("nw", input[i]))
      arr_sum(coords, nw, size);
    int arrmax = arr_max(coords, 3);
    max = arrmax > max ? arrmax : max;
  }
  printf("Part_1: %d\n", distance(coords, size));
  printf("Part_2: %d\n", max);
}
