#pragma once
class node
{
public:
	int dt;
	node * c;
	node(int);
	node();
	static node * newnode(int);
	~node();
};

