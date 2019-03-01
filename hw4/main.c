/*
 * main.c
 *
 * reverse polish calculator
 */
/*
Daniel Werminghausen 3/19/17
cs240
Hw4
*/
#include <stdio.h>
#include "calc.h" /* header file */
#include <math.h>
#include <stdlib.h>

#define MAXOP 100

int main()
{
	int type;
	int op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
		case NUMBER:
			push(atoi(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '^':
			// push(pow(pop(), pop()));
			push(pop() ^ pop());
			break;
		case '%':
			// push(pop() % pop());
			op2 = pop();
			if (op2 != 0)
				push(pop() % op2);
			else
			{
				printf("error : zero divisor\n");
				exit(1);
			}
			// op2 = pop();
			// if (op2 = pop() != 0)
			// 	op1 = pop();
			// 	push(op1 - op2 * ((int) (op1 / op2)));
			// // else
			// // {
			// // 	printf("error : zero divisor\n");
			// // 	exit(1);
			// // }
			break;
		case '~':
			push( ~ pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0)
				push(pop() / op2);
			else
			{
				printf("error : zero divisor\n");
				exit(1);
			}
			break;
		case '\n':
			printf("The answer is %d.\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			exit(1);
		}
	}
}
