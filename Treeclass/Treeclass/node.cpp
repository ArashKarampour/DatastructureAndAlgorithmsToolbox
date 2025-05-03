#include "node.h"

node::node()
{
}



node::node(int n)
{
	c = new node[n];
}

node *node:: newnode(int key)
{
	node *temp = new node;
	temp->dt = key;
	return temp;
}

node::~node()
{
}
