#ifndef RPN_H
#define RPN_H

#include <assert.h>
#include <map>
#include "stack.h"

int calc(char*, unsigned int);

enum Operator { op_operand, op_plus, op_minus, op_mulOrDiv, op_bracketOpening, op_none };

Operator opDecision(const char, std::map<char, char>);
const bool isOperand(const char);
const int simpleCalc(const char, const int, const  int);
const unsigned int getNum(const char*, unsigned int*, const unsigned int);
const bool isSign(const char*, unsigned int);
const unsigned int getBracketsLength(char*, const unsigned int, const unsigned int, std::map<char, char>);

#endif RPN_H