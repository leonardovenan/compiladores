#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#define MAXRESERVED 8

typedef enum
/* book-keeping tokens */
{
	ENDFILE, ERROR,
	/* reserved words */
	IF, THEN, ELSE, END, REPEAT, UNTIL, READ, WRITE,
	/* multicharacter tokens */
	ID, NUM,
	/* special symbols */
	ASSIGN, EQ, LT, PLUS, MINUS, TIMES, OVER, LPAREN, RPAREN, SEMI
} TokenType;

extern FILE* source; /* source code text file */
extern FILE* listing; /* listing output text file */
extern FILE* code; /* code text file for TM simulator */

extern int lineno; /* source line number for listing */


/**************************************************/
/***********   Syntax tree for parsing ************/
/**************************************************/

typedef enum { StmtK, ExpK } NodeKind;
typedef enum { IfK, RepeatK, AssignK, ReadK, WriteK } StmtKind;
typedef enum { OpK, ConstK, IdK } ExpKind;

/* ExpType is used for type checking */
typedef enum { Void, Integer, Boolean } ExpType;

#define MAXCHILDREN 3

typedef struct treeNode
{
	struct treeNode * child[MAXCHILDREN];
	struct treeNode * sibling;
	int lineno;
	NodeKind nodekind;
	union { StmtKind stmt; ExpKind exp; } kind;
	union {
		TokenType op;
		int val;
		char * name;
	} attr;
	ExpType type; /* for type checking of exps */
} TreeNode;

char token; /* holds current token */
/* function prototypes for recursive calls */
static TreeNode *exp(void);
static TreeNode *term(void);
static TreeNode *factor(void);

void error(void) {
	fprintf(stderr, "Error\n");
	exit(1);
}

static void match(char expectedToken)
{
	if (token == expectedToken) token = getchar();
	else error();
}

int main()
{
	TreeNode * result;
	token = getchar(); /* carga de marca com primeiro caractere para verifica��o � frente */
	result = exp();
	if (token == '\n') /* teste final de linha */
		printf("Result = %d\n", result);
	else error();/* caracteres indevidos na linha */

	system("pause");
}

/* Function newExpNode creates a new expression
 * node for syntax tree construction
 */
TreeNode * criaNoOp(ExpKind);


TreeNode * exp(void)
{
	TreeNode * temp = term();
	while ((token == '+') || (token == '-'))
	{
		TreeNode * novotemp = criaNoOp(OpK);
		if (novotemp != NULL) {
			match(token);
			novotemp->child[0] = temp;
			novotemp->attr.op = token;
			temp = novotemp;
		}
	}
	return temp;
}

TreeNode * term(void)
{
	TreeNode * temp = factor();
	while ((token == '*') || (token == '%') || (token == '/'))
	{
		TreeNode * novotemp = criaNoOp(OpK);
		if (novotemp != NULL) {
			novotemp->child[0] = temp;
			novotemp->attr.op = token;
			temp = novotemp;
			match(token);
			novotemp->child[1] = factor();
		}
	}
	return temp;
}

TreeNode * factor(void)
{
	TreeNode * temp = NULL;
	if (token == '(') {
		match('(');
		temp = exp();
		match(')');
	}
	else if (isdigit(token)) {
		ungetc(token, stdin);
		scanf("%d", &temp);
		token = getchar();
	}
	else error();
	return temp;
}

