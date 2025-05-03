#include "stack.h"

stack::stack(int i)
{
	maxsize = i;
	s = new string[maxsize];
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

void stack::push(char x)
{
	if (!isfull())
		s[++top] = x;


}

string stack::pop()
{
	if (!isempty()) {
		string ss = s[top--];
		s[top + 1] = "";
		return ss;
	}
}

int  stack::stackcurser() {
	return top;
}

string * stack::getstackarr()
{
	return s;
}