#pragma once
#include "stack.h"

class postfix
{
private:
	int snsize;
	string infix;
	string output;
public:
	postfix();
	~postfix();
	int getsnsize();
	void setinfix();
	void setoutput();
	void checkpriority(char, stack &, int);
	void getoutput();
};

