#pragma once
#include <iostream>
#include <string>
#include "node.h"
using namespace std;
class stack
{
private:
	int maxsize;
	node **s;
	int top;
public:
	stack(int i);
	~stack();
	bool isempty();
	bool isfull();
	void push(node*);
	node * pop();
	int  stackcurser();
	node ** getstackarr();
};

