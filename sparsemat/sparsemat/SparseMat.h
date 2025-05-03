#pragma once
#include <iostream>
using namespace std;
class SparseMat
{
private:
	int nonzero = 0;
	int row, col;
	int **sparr;
	int **nonsp;
public:
	SparseMat();
	~SparseMat();
	int ** getnonsp();
	void printnonsp();
	void Sum(SparseMat);
};

