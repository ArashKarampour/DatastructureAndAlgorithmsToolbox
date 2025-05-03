#pragma once
#include "treenode.h"
class bst
{
private:
	//treenode * root;
public:
	//treenode * root;
	treenode * Insert(treenode *,int);
	treenode * Delete(treenode *,int);
	treenode * search(treenode *r,int key);
	void Inorder(treenode *);
	bst();
	~bst();
};

