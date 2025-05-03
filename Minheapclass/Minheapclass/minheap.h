#pragma once
class minheap
{
private:
	int * arr;
	int maxsize;
	int ind;
public:
	minheap(int);
	~minheap();
	void Insert();
	int Delete();
	bool Isempty();
	bool Isfull();

};

