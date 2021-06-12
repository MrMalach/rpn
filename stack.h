#ifndef _STACK_H
#define _STACK_H

#include <iostream>


struct Node

{
	Node(const int);
	int data;
	Node* next;
};


class Stack
{
	Node* head;
public:
	Stack();
	~Stack();
	void push(const int);
	int pop();
	int top() const;
	int empty() const;
};

#endif // _STACK_H
