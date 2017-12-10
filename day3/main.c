#include "read_input.h"
#include "spiral.h"

int main(void){
  int input;
  int **spiral;
  int *center;

  center = malloc(2*sizeof(int));
  if(!read(&input))
    return -1;

  int size = ceil(sqrt(input));
  gen_spiral(size, &spiral, &center);
  /* Part 1 */
  int steps = 0;
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      if(spiral[i][j] == input){
        steps += abs(i-center[0]);
        steps += abs(j-center[1]);
      }
    }
  }

  /* Part 2 */
  int pos[2] = {center[0], center[1]};
  int new_num = 0;
  spiral[pos[0]][pos[1]] = -1;
  for(int nstep = 1; new_num < input && pos[0] >= 0 && pos[1] >= 0; nstep++){
    for(int coord = 1; coord >= 0; coord--){
      for(int s = 0; s < nstep && new_num < input; s++){
        pos[coord] += (2*coord-1)*(2*(nstep%2)-1);
        if(pos[coord] < 0){
          pos[coord]++;
          break;
        }

        /* Neighborhood */
        int neigh = 0;
        for(int k = pos[0]-1; k <= pos[0]+1; k++){
          for(int l = pos[1]-1; l <= pos[1]+1; l++){
            if(l >= 0 && k >= 0 && spiral[k][l] < 0){
              neigh += spiral[k][l];
            }
          }
        }
        spiral[pos[0]][pos[1]] = neigh;
        new_num = abs(neigh);
      }
    }
  }

  fprintf(stdout, "Part_1: %d\n", steps);
  fprintf(stdout, "Part_2: %d\n", new_num);
  del_spiral(spiral, size);
  return 0;
}
