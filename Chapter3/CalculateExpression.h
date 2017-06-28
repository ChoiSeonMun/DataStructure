#pragma once

#ifndef __CALCULATEEXPRESSION_H__
#define __CALCULATEEXPRESSION_H__

#include "OperandStack.h"

//Feature : to calculate the expression
//Return : last value
double calcPostfixExpr(FILE* fp = stdin)
{
	char		 ch;
	OperandStack stack;

	while ((ch = getc(fp)) != '\n')
	{
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			double right = stack.pop();
			double left = stack.pop();
			switch (ch) {
			case '+':
				stack.push(left + right);
				break;
			case '-':
				stack.push(left - right);
				break;
			case '*':
				stack.push(left * right);
				break;
			case '/':
				stack.push(left / right);
				break;
			}
		}
		else if ('0' <= ch && ch <= '9')
		{
			ungetc(ch, fp);
			double val;
			fscanf_s(fp, "%lf", &val);
			stack.push(val);
		}
	}

	return stack.pop();
}
#endif