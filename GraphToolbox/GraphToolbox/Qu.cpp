#include "Qu.h"



Qu::Qu(int S)
{
	Front = 0; End = 0;
	Size = S;
	list = new Node*[Size];
}


Qu::~Qu()
{
}

bool Qu::is_full()
{
	if (End == Front)
		return true;
	return false;
}

bool Qu::is_empty()
{
	if (End == Front)
		return true;
	return false;
}

void Qu::add(Node *item)
{
	End = (End + 1) % Size;
	if (!is_full())
		list[End] = item;
	else
		cout << "isfull" << endl;
}

Node * Qu::del()
{
	if (!is_empty()) {
		Front = (Front + 1) % Size;
		return list[Front];
	}
	else {
		cout << "isEmpty";
		Node *p = new Node;
		p = nullptr;
		return (p);
	}


}
