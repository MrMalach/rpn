#include "stack.h"

	Node::Node(const int data)
	{
		this->data = data;
		this->next = nullptr;
	}


	Stack::Stack(){ head = nullptr; }
	Stack::~Stack(){ while (!empty()) pop(); }
	void Stack::push(const int data)
	{
		Node *n = new (std::nothrow) Node(data);
		if (NULL == n)
		{
			throw(std::invalid_argument("allocation error"));
		}
		if (NULL == head)
			head = n;
		else
		{
			n->next = head;
			head = n;
		}
	}
	int Stack::pop()
	{
		if (empty())
		{
			throw(std::invalid_argument("error - bad expression"));
		}
		Node* temp = head;
		int out = temp->data;
		head = head->next;
		delete temp;
		return out;
	}
	int Stack::top() const
	{
		if (empty())
		{
			throw(std::invalid_argument("error - bad expression"));

		}
		return head->data;
	}
	int Stack::empty() const	{ return NULL == head; }

	
