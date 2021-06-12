#include "rpn.h"


void main()
{
	
	// *** Calculator - Reverse Polish Notation ***
	char* expression[] = { 
		"2*[--1+3]*-(1 + 0 * 6)+ {32   /2+ 1*(2+ -2 + [0])}"
		, "4*5 + 100/2 + 1 - 500"
		, "100 + 100 / 4 + 10*     -5"
		, "9 + 2 / 2"
		, "2 *-2 * --  1 / 2"
		, "4+1+2*10+   3+4*2/4"
		, "-3*-2"
};
	int expressionResults[] = { 8, -429, 75, 10, -2, 30, 6 };
	for (unsigned int i = 0; i < sizeof(expression) / sizeof(expression[0]); i++)
	{
		assert(calc(expression[i], strlen(expression[i])) == expressionResults[i]);
		//std::cout << calc(expression[i], strlen(expression[i])) << " =? " << expressionResults[i] << std::endl;
	}
	

	std::cin.get();

}