#pragma once
#include <iostream>
#include "Node.h"
using namespace std;
class Qu
{
private:
	int Size;
	int Front;
	int End;
	Node ** list;
public:
	Qu(int);
	~Qu();
	bool is_full();
	bool is_empty();
	void add(Node*);
	Node * del();
};
