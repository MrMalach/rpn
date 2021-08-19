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
			std::invalid_argument inv_arg("allocation error");
			throw(inv_arg);
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
			std::invalid_argument inv_arg("error - bad expression");
			throw(inv_arg);
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
			std::invalid_argument inv_arg("error - bad expression");
			throw(inv_arg);
		}
		return head->data;
	}
	int Stack::empty() const	{ return NULL == head; }

	
