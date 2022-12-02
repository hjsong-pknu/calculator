
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "token.h"

/* Array of operators */
struct operator oplist[] = { {'+', OP_PLUS, 1, 1},
{'-', OP_MINUS, 1, 1},
{'*', OP_MULTIPLY, 2, 2},
{'/', OP_DIVIDE, 2, 2},
{'^', OP_POWER, 3, 3},
{'%', OP_MOD, 2, 2},
{')', OP_RPAREN, 0, 0},
{'(', OP_LPAREN, -1, 4},
{0, 0, 0, 0} };

char * GetNextToken(char * input, struct token * t) {
	while ( *input && isspace(*input) ) /* Skip leading whitespace */
	++input;
	if ( *input == 0 ) /* Check for end of input */
		return NULL;
	if ( isdigit(*input) ) { /* Token is an operand */
		t->type = TOK_OPERAND;
		t->value = strtol(input, &input, 0);
	}
	else { /* Token is an operator */
		int n = 0, found = 0;
		t->type = TOK_OPERATOR;
		while ( !found && oplist[n].symbol ) {
			if ( oplist[n].symbol == *input ) {
				t->value = oplist[n].value;
				found = 1;
			}
			++n;
		}
		
		if ( !found ) {
			printf("Bad operator: %c\n", *input);
			exit(EXIT_FAILURE);
		}
		++input;
	}
	
	return input;
}

