#include <stdio.h>
#include <stdlib.h>
#include "eval.h"
#define BUFFERSIZE (256)

int main(void) {
	char input[BUFFERSIZE];
<<<<<<< HEAD
	printf("Welcome to mycalculator.");
=======
	printf("Welcome to My Calculator");
>>>>>>> e66aa1c8ee9403acedf470b65f5467b01f1e11cb
	printf("Enter your expression: ");
	fflush(stdout);
	fgets(input, BUFFERSIZE, stdin);
	printf("Result is: %.2f\n", evaluate(input));
	return EXIT_SUCCESS;
}
