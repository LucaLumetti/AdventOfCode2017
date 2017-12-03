#include "read_input.h"

int main(void){
  FILE *input_file = fopen("./input", "rt");
  int *input;
  size_t size;
  int checksum[2] = {0, 0};
  for(;;){
    read_row(input_file, &input, &size);
    if(size == 0)
      break;

    int min = input[0], max = input[0];
    for(int i = 0; i < size; i++){
      min = (input[i] < min) ? input[i] : min;
      max = (input[i] > max) ? input[i] : max;
    }
    checksum[0] += max-min;

    for(int i = 0; i < size; i++){
      for(int j = 0; j < size; j++){
        if(input[i] != 0 && input[j] != 0)
          if(input[i] % input[j] == 0 && input[i] > input[j]){
            checksum[1] += input[i]/input[j];
          }
      }
    }
    free(input);
  }

  printf("Part_1: %d\n", checksum[0]);
  printf("Part_2: %d\n", checksum[1]);
  return 0;
}
