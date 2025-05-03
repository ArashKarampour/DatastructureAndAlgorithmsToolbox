#include "Qu2.h"



Qu2::Qu2(int S)
{
	Front = 0; End = 0;
	Size = S;
	list = new int[Size];
}


Qu2::~Qu2()
{
}

bool Qu2::is_full()
{
	if (End == Size-1)
		return true;
	return false;
}

bool Qu2::is_empty()
{
	if (End == Front)
		return true;
	return false;
}

void Qu2::add(int item)
{
	
	if (!is_full())
		list[End] = item;
	else
		cout << "isfull" << endl;
	End = (End + 1) % Size;
	
}

int Qu2::del()
{
	if (!is_empty()) {
		int ret = list[Front];
		Front = (Front + 1) % Size;
		return ret;
	}
	else {
		cout << "isEmpty";
		return NULL;
	}


}
