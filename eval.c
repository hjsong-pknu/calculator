#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "token.h"
#include "stack.h"
#include "eval.h"

int global_var=0;

char * toPostfix(char * infix, char * postfix) {
	char buffer[BUFFERSIZE];
	Stack * op_stack = create_stack(STACKSIZE);
	struct token t;
	*postfix = 0; /* Empty output buffer */
	
	while ( (infix = GetNextToken(infix, &t)) ) {
		if ( t.type == TOK_OPERAND ) {
			sprintf(buffer, "%d ", t.value);
			strcat(postfix, buffer);
		}
		else {
			if ( is_empty(op_stack) || oplist[t.value].precedence_out_stack >
				oplist[peek(op_stack)].precedence_in_stack ||
				oplist[peek(op_stack)].value == OP_LPAREN ) {
				push(op_stack, t.value);
			}
			else {
				while ( !is_empty(op_stack) &&
				(oplist[peek(op_stack)].precedence_in_stack >=
				oplist[t.value].precedence_out_stack || (t.value==OP_RPAREN &&
				oplist[peek(op_stack)].value!=OP_LPAREN)) ) {
					sprintf(buffer, "%c ", oplist[peek(op_stack)].symbol);
					strcat(postfix, buffer);
					pop(op_stack);
				}
				
				if (t.value == OP_RPAREN && oplist[peek(op_stack)].value == OP_LPAREN)
					pop(op_stack);
				else
					push(op_stack, t.value);
			}
		}
	}

	/* Output any operators still on the stack */
	while ( !is_empty(op_stack) ) {
		if ( oplist[peek(op_stack)].value != OP_LPAREN ) 
		{
			sprintf(buffer, "%c ", oplist[peek(op_stack)].symbol);
			strcat(postfix, buffer);
		}
		else 
		{
			printf("Wrong parenthesis.\n");
			exit(EXIT_FAILURE);
		}
		
		pop(op_stack);
	}
	
	printf("Postfix Experssion: %s\n", postfix);
	
	return postfix;
}

double parsePostfix(char * postfix) {
	struct token t;
	Stack * opr_stack = create_stack(STACKSIZE);
	while ( (postfix = GetNextToken(postfix, &t)) ) {
		if ( t.type == TOK_OPERAND ) 
		{
			push(opr_stack, t.value); /* Store operand on stack */
		} 
		else 
		{
			double a, b, value;
			if ( opr_stack->top < 2 ) { /* Two operands on stack? */
				puts("Stack empty!");
				exit(EXIT_FAILURE);
			}

			b = pop(opr_stack); /* Get last two operands */
			a = pop(opr_stack);
			
			switch ( t.value ) {
				case OP_PLUS: /* Perform operation */
					value = a + b;
				break;
				case OP_MINUS:
					value = a - b;
				break;
				case OP_MULTIPLY:
					value = a * b;
				break;
				case OP_DIVIDE:
					value = a / b;
				break;

				case OP_MOD:
					value = fmod(a, b);
				break;
				case OP_POWER:
					value = pow(a, b);
				break;
				default:
					printf("Bad operator: %c\n", oplist[t.value].symbol);
					exit(EXIT_FAILURE);
				break;
			}
			
			push(opr_stack, value); /* Put value back on stack */
		}
	}
	
	return peek(opr_stack);
}

double evaluate(char * infix) {
	char postfix[BUFFERSIZE];
	return parsePostfix(toPostfix(infix, postfix));
}
