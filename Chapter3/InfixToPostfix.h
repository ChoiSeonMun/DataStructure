#pragma once

#ifndef __INFIXTOPOSTFIX_H__
#define __INFIXTOPOSTFIX_H__

#include "OperandStack.h"

//Feature : to judge the precedence of 'op'
//Return : if op is valid, return precedence. or, return -1
inline static int precedence(char op)
{
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

//Feature : to convert infix expression to postfix
//Return : void
void infixToPostfix(FILE* fp = stdin)
{
	char		 c, op;
	double		 val;
	OperandStack stack;

	while ((c = getc(fp)) != '\n')
	{
		if ('0' <= c && c <= '9')
		{
			ungetc(c, fp);
			fscanf_s(fp, "%lf", &val);
			printf("%4.1f ", val);
		}
		else if (c == '(')
			stack.push(c);
		else if (c == ')')
		{
			while (!stack.isEmpty())
			{
				op = stack.pop();
				if (op == '(') break;
				else
					printf("%c ", op);
			}
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			while (!stack.isEmpty())
			{
				op = stack.peek();
				if (precedence(c) <= precedence(op))
				{
					printf("%c ", op);
					stack.pop();
				}
				else break;
			}
			stack.push(c);
		}
	}
	while (!stack.isEmpty())
		printf("%c ", stack.pop());
	printf("\n");
}
#endif