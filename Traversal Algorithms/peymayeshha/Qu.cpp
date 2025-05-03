#include "Qu.h"



Qu::Qu(int S)
{
	Front = 0; End = 0;
	Size = S;
	list = new node*[Size];
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

void Qu::add(node *item)
{
	End = (End + 1) % Size;
	if (!is_full()) {
		list[End] = item;
	}
	else
		cout << "isfull" << endl;
}

node * Qu::del()
{
	if (!is_empty()) {
		Front = (Front + 1) % Size;
		return list[Front];
	}
	else {
		node *p = new node;
		p = nullptr;
		return (p);
	}


}
