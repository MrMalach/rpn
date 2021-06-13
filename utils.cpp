#include "rpn.h"


Operator opDecision(const char c, std::map<char, char> mp)
{
	switch(c)
	{
		case '+':
			return op_plus;
		case '-':
			return op_minus;
		case '*':
			return op_mulOrDiv;
		case '/':
			return op_mulOrDiv;
		default:
			if (mp.count(c))
				return op_bracketOpening;
			return (c >= '0' && c <= '9') ? op_operand : op_none;
	}

}

const bool isOperand(const char c)
{
	return c >= '0' && c <= '9';
}

const int simpleCalc(const char op, const int a, const  int b)
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		if (b == 0)
		{
			std::invalid_argument e("error - divided by 0");
			throw(e);
		}
		return a / b;
	}
}

const unsigned int getNum(const char* str, unsigned int *i, const unsigned int strLen)
{
	// return unsigned integer.
	// start reading from index i @ string expression
	// stop reading if next char is not a digit
	// advance index i (calling function should pass i by reference)

	unsigned int out = 0;

	do		out = out * 10 + str[*i] - '0';
	while (isOperand(str[*i + 1]) && (*i)++ < strLen);

	return out;
}

const bool isSign(const char* str, unsigned int i)
{
	// Returns true is the minus is for sign
	// Flase is the minus is the operator

	// this function is called when a '-' char is read
	// checks previous operator or operand in the 
	// expression and returns true if the index is 0 or
	// if the previous is an operator
	// if the previous is an operand returs false
	// 
	if (i == 0)
		return true;
	while (str[--i] == ' ')
	if (i == 0)
		return true;
	return !isOperand(str[i]);
}

const unsigned int getBracketsLength(char* str, const unsigned int strLen, const unsigned int i, std::map<char, char> mp)
{
	Stack brackets; // Case there are brackets inside brackets, use a stack.
	for (unsigned int j = i; j < strLen; j++)
	{
		if (mp.count(str[j]))
		{
			brackets.push(str[j]);
		}
		else if ((str[j]) == mp[brackets.top()])
			// str[j] - check for the closing brackets, compare to the value of the hash map running
			// the top of the stack char value.
			// so if its the same value - the brackets got closed properly
		{
			brackets.pop();
			// if the stack is empty - the expression is found.
			if (brackets.empty())
				return j - i + 1;
		}
	} 
	// Got here? thats an error
	std::invalid_argument e("error - Bad brackets");
	throw(e);
}
