#pragma once
#include <iostream>
#include "node.h"
using namespace std;
class Qu
{
private:
	int Size;
	int Front;
	int End;
	node ** list;
public:
	Qu(int);
	~Qu();
	bool is_full();
	bool is_empty();
	void add(node*);
	node * del();
};

