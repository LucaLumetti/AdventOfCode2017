#include "read_input.h"

int main(void){
	size_t size;
	char *input;
	unsigned int chapta[2] = {0,0}; // [part1, part2]
	read(&input, &size);

	/* Solution for part 1 */
	for(int i = 0; i < size; i++){
		int next = (i+1)%size;
		if(input[i] == input[next])
			chapta[0] += input[i];
	}

	/* Solution for part 2 */
	for(int i = 0; i < size; i++){
		int next = (i+size/2)%size;
		if(input[i] == input[next])
			chapta[1] += input[i];
	}

	free(input);
	printf("Part_1: %d\n", chapta[0]);
	printf("Part_2: %d\n", chapta[1]);
	return 0;
}
