#include <iostream>
#include "node.h"
#include "Qu.h"
#include "stack.h"
using namespace std;
void preorder(node * p) {
	if (p != NULL) {
		cout << p->dt;
		preorder(p->left);
		preorder(p->right);
	}
}
void Inorder(node * p) {
	if (p != NULL) {
		Inorder(p->left);
		cout << p->dt;
		Inorder(p->right);
	}
}
void postorder(node * p) {
	if (p != NULL) {
		postorder(p->left);
		postorder(p->right);
		cout << p->dt;
	}
}
void BFS(node *root) {
	Qu bq(100);
	bq.add(root);
	while (!bq.is_empty())
	{
		node *n = bq.del();
		if(n != nullptr){
			cout << n->dt;
			bq.add(n->left);
			bq.add(n->right);
		}
		
	}
}
void DFS(node *root) {
	stack ds(100);
	ds.push(root);
	while (!ds.isempty()) {
		node *n = ds.pop();
		if (n != nullptr) {
			cout << n->dt;
			ds.push(n->right);
			ds.push(n->left);

		}
	}
}
int main()
{
	node *n0 = new node;
	node *n1 = new node;
	node *n2 = new node;
	node *n3 = new node;
	node *n4 = new node;

	n0->dt = 0;
	n1->dt = 1; n2->dt = 2; n3->dt = 3; n4->dt = 4;
	n0->left = n1; n0->right = n2;
	n1->left = n3; n1->right = n4;
	
	cout << "BFS" << endl; BFS(n0); cout << endl;
	cout << "DFS"<<endl; DFS(n0);
    //cout << "Hello World!\n"; 
}
