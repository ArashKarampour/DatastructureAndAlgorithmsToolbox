#pragma once
#include <iostream>
#include "node.h"
using namespace std;

class tree
{
private:
	int * arr;
	int maxchild;
	//int ind;
public:
	void Insert(int,int,int);
	void LInsert(int, int, int);
	tree(int,int);
	tree(int);
	~tree();
};

