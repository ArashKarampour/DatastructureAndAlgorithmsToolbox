#include "bst.h"
#include <iostream>
using namespace std;


treenode *bst::Insert(treenode * root,int x)
{
	
	
	treenode *p = new treenode;
	p->dt = x; p->left = p->right = NULL;

	if (root == NULL)
		root = p;
	else if ((!search(root,x))&& root != NULL) {
		treenode *q1 = root;
		treenode *q2 = NULL;
		while (q1 != NULL)
		{
			q2 = q1;
			if (q1->dt > x)
				q1 = (q1->left);
			else
				q1 = q1->right;
		}
		if (q2->dt > x)
			q2->left = p;
		else
			q2->right = p;
	
	}
	
	return root;

}
treenode * bst::Delete(treenode *root, int x)
{
	treenode *p = search(root, x);
	if (p && root) {
		treenode *n = new treenode;
		if (p->left == NULL && p->right == NULL) {
			//int re = p->dt;
			p->dt = NULL; p->left = NULL; p->right = NULL;
			delete [] search(root, p->dt);
			return root;
		}
		else if (p->left == NULL && p->right != NULL) {
			n = p;
			if (n->right->dt != NULL) {
				n = n->right;
				while (n->left != NULL && n->left->dt != NULL) {
					n = n->left;
				}

				//int re = p->dt;
				int re = n->dt;
				root = Delete(root, n->dt);
				p->dt = re;
			}
			else 
				n->dt = NULL; delete(search(root, n->dt));
				
			
		}
		else if (p->left != NULL && p->right == NULL) {
			n = p;
			if (n->left->dt != NULL) {
				n = n->left;
				while (n->right != NULL && n->right->dt != NULL) {
					n = n->right;
				}

				//int re = p->dt;
				//treenode *q = search(root, n->dt);
				int re = n->dt;
				root = Delete(root, n->dt);
				p->dt = re;
			}
			else
				n->dt = NULL; delete(search(root, n->dt));
				

		}
		else {
			n = p;
			if (n->left->dt != NULL) {
				n = n->left;
				while (n->right != NULL && n->right->dt != NULL) {
					n = n->right;
				}

				//int re = p->dt;
				int re = n->dt;
				root = Delete(root, n->dt);
				p->dt = re;
				//return re;
			}
			else if (n->right->dt != NULL) {
				n = n->right;
				while (n->left != NULL && n->left->dt != NULL) {
					n = n->left;
				}
				int re = n->dt;
				root = Delete(root, n->dt);
				p->dt = re;

			}
			else
				n->dt = NULL; delete(search(root, n->dt));
		}
		
	}

	return root;
}
treenode * bst::search(treenode *r,int key)
{
	if ((r == NULL) || key == r->dt)
		return r;
	if (key < r->dt)
		return search((r->left), key);
	else
		return search(r->right, key);
	
}
void bst::Inorder(treenode *p)
{
	if (p) {
		Inorder(p->left);
		if (p->dt != NULL)
			cout << p->dt << "\t";
		Inorder(p->right);
	}
}


bst::bst()
{
	//root = NULL;
}


bst::~bst()
{
}
