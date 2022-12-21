#include <stdio.h>
#include <stdlib.h>
#include "eval.h"
#define BUFFERSIZE (256)

//Add Comment by 201612178
int main(void) {
	char input[BUFFERSIZE];
	
	printf("Enter your expression: ");
	fflush(stdout);
	fgets(input, BUFFERSIZE, stdin);
	printf("Result is: %.2f\n", evaluate(input));
	return EXIT_SUCCESS;
}
