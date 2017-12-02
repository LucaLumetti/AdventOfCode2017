#include "read_input.h"

void read(char **arr, size_t *size){
	FILE *input = fopen("input", "rt");
	*size = 0;
	*arr = malloc(*size);

	for(;;){
		char c = fgetc(input);
		if(c == EOF)
			break;
		c -= '0';
		if(c >= 0){
			(*size)++;
			*arr = realloc(*arr, *size);
			(*arr)[(*size)-1] = c;
		}	
	}
	return;
}
