#include "Queue.h"



Queue::Queue(int S)
{
	Front = 0; End = 0;
	Size = S;
	list = new int[Size];
}


Queue::~Queue()
{
}

bool Queue::is_full()
{ 
	if (End == Front)
		return true;
	return false;
}

bool Queue::is_empty()
{
	if (End == Front)
		return true;
	return false;
}

void Queue::add(int item)
{
	End = (End + 1) % Size;
	if (!is_full())
		list[End] = item;
	else
		cout << "isfull" << endl;
}

int Queue::del()
{
	if (!is_empty()) {
		Front = (Front + 1) % Size;
		return list[Front];
	}
	else
		return is_empty();
	
	
	
}
