#pragma once
#include <iostream>
#include <string>
using namespace std;
class stack
{
private:
	int maxsize;
	string *s;
	int top;
public:
	stack(int i);
	~stack();
	bool isempty();
	bool isfull();
	void push(char);
	string pop();
	int  stackcurser();
	string * getstackarr();
};

