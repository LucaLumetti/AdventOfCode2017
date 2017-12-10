#include "spiral.h"

int gen_spiral(int size, int ***arr, int **c){
  int **matrix = malloc(size*sizeof(int *));
  for(int i = 0; i < size; i++){
    matrix[i] = malloc(size*sizeof(int*));
  }

  int center[2] = {floor(size/2.), ceil(size/2.)-1};
  int pos[2] = {center[0], center[1]};
  int n = 1;
  for(int step = 1; step <= size; step++){
    for(int step_count = 0; step_count < step; step_count++){
      if(pos[0] < 0 || pos[0] > size-1 || pos[1] < 0 || pos[1] > size-1)
        goto end;
      matrix[pos[0]][pos[1]] = n++;
      pos[1] += 2*(step%2)-1;
    }
    for(int step_count = 0; step_count < step; step_count++){
      if(pos[0] < 0 || pos[0] > size-1 || pos[1] < 0 || pos[1] > size-1)
        goto end;
      matrix[pos[0]][pos[1]] = n++;
      pos[0] += -(2*(step%2)-1);
    }
  }
  end:
  *arr = matrix;
  (*c)[0] = center[0];
  (*c)[1] = center[1];
  return 0;
}

int del_spiral(int **spiral, int size){
  for(int i = 0; i < size; i++){
    free(spiral[i]);
  }
  free(spiral);
  return 0;
}
