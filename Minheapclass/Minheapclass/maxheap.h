#pragma once
class maxheap
{
private:
	int * arr;
	int maxsize;
	int ind;
public:
	maxheap(int);
	~maxheap();
	void Insert();
	int Delete();
	bool Isempty();
	bool Isfull();

};

