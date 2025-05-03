#include <iostream>
#include "bst.h"
using namespace std;
int main()
{
	treenode *t = new treenode;
	t = NULL;
	bst a;
	/*
	t = a.Insert(t,10);
	t = a.Insert(t,5);
	t = a.Insert(t, 12);
	t = a.Insert(t, 11);
	t = a.Insert(t, 6);
	t = a.Insert(t, 13);
	//cout << t->left->dt;
	//a.Inorder(t);
	t = a.Delete(t, 10);
	t = a.Delete(t, 6);
	t = a.Delete(t, 11);
	t = a.Delete(t, 12);
	//t = a.Delete(t, 13);
	//t = a.Delete(t, 5);
	*/
	t = a.Insert(t, 8);
	t = a.Insert(t, 3);
	t = a.Insert(t, 10);
	t = a.Insert(t, 1);
	t = a.Insert(t, 6);
	t = a.Insert(t, 14);
	t = a.Insert(t, 4);
	t = a.Insert(t, 7);
	t = a.Insert(t, 13);

	t = a.Delete(t, 10);
	t = a.Delete(t, 6);
	t = a.Delete(t, 8);
	t = a.Delete(t, 14);
	t = a.Delete(t, 13);
	
	cout << t ->dt<<endl;
	a.Inorder(t);
}

