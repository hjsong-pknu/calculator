#include <stdio.h>
#include <stdlib.h>
#include "eval.h"
#define BUFFERSIZE (256)

int main(void) {
    char input[BUFFERSIZE];
    char studentID[BUFFERSIZE];
    char name[BUFFERSIZE];
    
    // Get expression input
    printf("Enter your expression: ");
    fflush(stdout);
    fgets(input, BUFFERSIZE, stdin);
    
    // Get student ID
    printf("Enter your student ID: ");
    fflush(stdout);
    fgets(studentID, BUFFERSIZE, stdin);
    
    // Get name
    printf("Enter your name: ");
    fflush(stdout);
    fgets(name, BUFFERSIZE, stdin);

    // Output the result of the expression
    printf("Result is: %.2f\n", evaluate(input));

    // Print commit message (this would typically be used externally)
    printf("\nCommit message:\n");
    printf("Student ID: %s", studentID);
    printf("Name: %s", name);
    printf("Evaluated expression: %s", input);
    
    return EXIT_SUCCESS;
}
