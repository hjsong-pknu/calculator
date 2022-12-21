#include <stdio.h>
#include <stdlib.h>
#include "eval.h"
#define BUFFERSIZE (256)

int main(void) {  //Edited text here
	char input[BUFFERSIZE];
	
	printf("Enter your expression: ");
	fflush(stdout);
	fgets(input, BUFFERSIZE, stdin);
	printf("Result is: %.2f\n", evaluate(input));
	printf("Done");
	return EXIT_SUCCESS;
} 