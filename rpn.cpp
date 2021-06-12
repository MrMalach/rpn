#include "rpn.h"

int calc(char* str, const unsigned int strLen)
{
	try
	{
		// Two operand to be sent to a simple calculator...
		int operandA = 0, operandB = 0;
		// An operand can have a minus sign after multipication for instance (3*-2=-6)
		int sign = 1;
		// When brackets are open i'll recursively run calc() in order calculate the expression in brackets
		// So... this is for the in brackets string length
		unsigned int subStrLen = 0;
		// Just to decide when to skip to the next for loop iteration
		bool continueFlag = 0;
		// This RPN method is made for stacks! 		
		Stack operators, operands;
		// op variable is for deciding wich group to include the char to
		Operator op;

		std::invalid_argument e("error - illegal char");

		// Map the brackets 
		std::map<char, char> mp;
		mp['['] = ']';
		mp['('] = ')';
		mp['{'] = '}';


		for (unsigned int i = 0; i < strLen; i++)
		{
			if (str[i] == ' ') 
					continue;  // skip spaces

			op = opDecision(str[i], mp);
			switch (op)
			{
			case op_operand:
				// Stack the operand - getNum() will convert the string to int
				// Multiply sign for the case of 1 * -2 for instance.
				// ( check isSign() function )
				operands.push(sign * getNum(str, &i, strLen));
				sign = 1;
				continueFlag = 1;
				break;
			case op_minus:
				// deal with cases such as: "1*-12" or "-1+  2"
				if (isSign(str, i))
				{
					sign *= -1;
					continueFlag = 1;
				}
				break;
			case op_bracketOpening:
				// case a bracket was spotted, get its expression's length
				subStrLen = getBracketsLength(str, strLen, i, mp);
				// Recursively run the calculator for the in brackets expression.
				// Push it as an operand (after correcting it for sign (-)
				// send the expression recursively without the brackets [i + 1],[N1 - 2]
				// advance the index i beyond the brackets
				// Stack the result as an operand
				operands.push(sign * calc(&str[i + 1], subStrLen - 2));
				sign = 1;
				i += subStrLen - 1;
				continueFlag = 1;
				break;

			case op_none:
				throw(e);
			default:
				break;
			} // end switch case op


			if (continueFlag)
			{
				continueFlag = 0;
				continue; // jump to the next for loop iteration
			}
				
			if (!operators.empty() &&
				(operators.top() == '*' || operators.top() == '/'))
			{
				// when reaching an operator,
				// check the previous operator to follow order of operations
						operandB = operands.pop();		     operandA = operands.pop();
						operands.push(simpleCalc(operators.pop(), operandA, operandB));
			} 
			operators.push(str[i]); // stack the operator 
		} // end of : [for (unsigned int i = 0; i < N; i++)]
		while (!operators.empty())
		{
		// empty both stacks
		// return top of stack for result
					operandB = operands.pop();			 operandA = operands.pop();
					operands.push(simpleCalc(operators.pop(), operandA, operandB));
		} 
		return operands.pop();
	}
	catch (std::invalid_argument e)
	{
			std::cout << e.what() << std::endl;
	}
}