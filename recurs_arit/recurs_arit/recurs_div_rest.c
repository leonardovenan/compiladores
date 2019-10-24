#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/* Calculadora para aritmética de
inteiros simples segundo a EBNF:
<exp> -> <termo> { <soma> <termo> }
<soma> -> + | —
<termo> -> <fator> { <mult> <fator> }
<mult> -> *
<fator> -> ( <exp> ) | Número

Linhas de texto fornecidas como entrada de stdin
Imprime o resultado ou então "Error".

*/

char token; /* variável de marca global */
/* protótipos de funções para ativações recursivas */
int exp(void);
int term(void);
int factor(void);

void error(void) {
	fprintf(stderr, "Error\n");
	exit(1);
}

void match(char expectedToken)
{
	if (token == expectedToken) token = getchar();
	else error();
}

int main()
{
	int result;
	token = getchar(); /* carga de marca com primeiro caractere para verificação à frente */
	result = exp();
	if (token=='\n') /* teste final de linha */
		printf("Result = %d\n", result);
	else error();/* caracteres indevidos na linha */
	
	system("pause");
	getch();
}

int exp(void)
{
	int temp = term();
	while ((token == '+')||(token == '-'))
		switch (token) {
		case '+': match('+');
			temp += term();
			break;
		case '-': match('-');
			temp -= term();
			break;
		}
	return temp;
}

int term(void)
{
	int temp = factor();
	while ((token=='*')||(token=='%')||(token=='/'))
		switch (token){
		case '*': match('*');
			temp *= factor();
			break;
		case '%': match('%');
			temp %= factor();
			break;
		case '/': match('/');
			temp /= factor();
			break;
		}
	return temp;
}


int factor(void)
{
	int temp;
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
