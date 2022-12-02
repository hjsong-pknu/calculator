#ifndef PG_TOKEN_H
#define PG_TOKEN_H

#define BUFFERSIZE (256)
#define STACKSIZE (256)
#define TOK_OPERAND (0)
#define TOK_OPERATOR (1)
#define OP_PLUS (0)
#define OP_MINUS (1)
#define OP_MULTIPLY (2)
#define OP_DIVIDE (3)
#define OP_POWER (4)
#define OP_MOD (5)
#define OP_RPAREN (6)
#define OP_LPAREN (7)
#define OP_BAD (99)

struct token {
int type;
int value;
};

struct operator {
char symbol;
int value;
int precedence_in_stack;
int precedence_out_stack;
};

/* Array of operator descriptions */
extern struct operator oplist[];
char * GetNextToken(char * input, struct token * t);

#endif /* PG_TOKEN_H */
