#include "tree.h"


void tree::Insert(int par, int wch, int x) {
	if (par == 0) {
		if (arr[1] == -842150451){
			arr[1] = x;
			cout << arr[1]<< endl;

		}
		else
			cout <<"first member is already given" << endl;
	}
	else {
		if (wch > maxchild)
			cout << "The maxchild is set to" << maxchild << endl;
		else if (arr[par*maxchild + wch - 1]==-842150451) {
			arr[par*maxchild + wch - 1] = x;
			cout << arr[par*maxchild + wch - 1] << endl;
		}
		else
			cout << wch << "rd child of" << par << "rd parent is already given" << endl;
	}
	

}

void tree::LInsert(int par, int wch, int x)
{
	node * n = new node(maxchild);
	n->dt = x;
}

tree::tree(int n, int m)
{
	arr = new int[n];
	maxchild = m;
	//ind = 0;

}

tree::tree(int m)
{
	maxchild = m;
}


tree::~tree()
{
}
