#pragma once

#ifndef __CHECKMATCHING_H__
#define __CHECKMATCHING_H__

#include "ArrayStack.h"

//Feature : to examine whether left-bracket and right-bracket are same or not
//Return : if same, return true. or, return false
static bool checkBracket(char left, char right);

//Feature : to examine whether the pair of brackets is correct or not
//Return : if correct, return true. or, return false
bool checkMatching(char* file)
{
	FILE* fp;
	fopen_s(&fp, file, "r");
	if (fp == NULL)
		error("There is no file");

	bool result = false;
	//Problem 1, 3
	bool bisInSingleQuotationMark = false, bisInDoubleQuotationMark = false;
	int lineNo = 1;
	OperandStack stack;
	char ch;

 	while ((ch = getc(fp)) != EOF)
	{
		//Problem 4
		if (ch == '/')
		{
			// '//' comment case
			if ((ch = getc(fp)) == '/')
			{
				while ((ch = getc(fp)) != '\n')
					/*NULL STATEMENT*/;
			}
			// '/**/' comment case
			else if (ch == '*')
			{
				char prev = getc(fp);
				//iterate, while */ found
				while (prev != '*' && ((ch = getc(fp)) != '/'))
					prev = ch;
			}
			ungetc(ch, fp);
		}
		//Problem 3
		if (ch == '\"' && !bisInDoubleQuotationMark)
			bisInDoubleQuotationMark = true;
		else if (ch == '\"' && bisInDoubleQuotationMark)
			bisInDoubleQuotationMark = false;
		//Problem 1
		if (ch == '\'' && !bisInSingleQuotationMark)
			bisInSingleQuotationMark = true;
		else if (ch == '\'' && bisInSingleQuotationMark)
			bisInSingleQuotationMark = false;
		//Problem 2
		if (ch == '\\')
		{
			ch = getc(fp);
			ch = getc(fp);
		}
		
		if (ch == '\n')
			++lineNo;
		if ((ch == '(' || ch == '{' || ch == '[') && !bisInSingleQuotationMark && !bisInDoubleQuotationMark)
			stack.push(ch);
		else if ((ch == ')' || ch == '}' || ch == ']') && !bisInSingleQuotationMark && !bisInDoubleQuotationMark)
		{
			int temp = stack.pop();
			if (!checkBracket(temp, ch))
				break;
		}
	}
	fclose(fp);
	printf("[%s]Examination Result :\n", file);
	if (!stack.isEmpty())
		printf("Error: the problem is found(Line: %d)\n\n", lineNo);
	else
	{
		printf("OK: there is no problem\n\n");
		result = true;
	}

	return result;
}

inline static bool checkBracket(char left, char right)
{
	if (left == '(' && right == ')')
		return true;
	else if (left == '{' && right == '}')
		return true;
	else if (left == '[' && right == ']')
		return true;
	else
		return false;
}
#endif