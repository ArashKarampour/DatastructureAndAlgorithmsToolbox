#include "stack.h"

stack::stack(int i)
{
	maxsize = i;
	s = new node*[maxsize];
	top = -1;
}

stack::~stack()
{
}

bool stack::isempty()
{
	if (top == -1)
		return true;
	else
		return false;
}

bool stack::isfull()
{
	if (top == maxsize - 1)
		return true;
	else
		return false;
}

void stack::push(node * x)
{
	if (!isfull())
		s[++top] = x;


}

node * stack::pop()
{
	if (!isempty()) {
		node *ss = s[top--];
		return ss;
	}
}

int  stack::stackcurser() {
	return top;
}

node ** stack::getstackarr()
{
	return s;
}