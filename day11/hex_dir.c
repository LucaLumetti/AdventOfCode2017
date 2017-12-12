#include "hex_dir.h"

int arr_max(int *arr, size_t size){
  if(size < 1){
    return 0;
  }

  int max = arr[0];
  for(size_t i = 0; i < size; i++){
    if(max < arr[i])
      max = arr[i];
  }
  return max;
}

int distance(int *arr, size_t size){
  for(int i = 0; i < size; i++){
    arr[i] = (arr[i] > 0) ? arr[i] : -arr[i];
  }
  return arr_max(arr, size);
}

void arr_sum(int *arr, char *tosum, size_t size){
  for(size_t i = 0; i < size; i++)
    arr[i] += tosum[i];
  return;
}
