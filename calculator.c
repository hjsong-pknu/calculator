#include <stdio.h>
#include <stdlib.h>
#include "eval.h"
#define BUFFERSIZE (256)


int main(void) {
	char input[BUFFERSIZE];
	printf("oss was the best lecture ever");	
	printf("Enter your expression: ");
	fflush(stdout);
	fgets(input, BUFFERSIZE, stdin);
	printf("Result is: %.2f\n", evaluate(input));
	return EXIT_SUCCESS;
}
