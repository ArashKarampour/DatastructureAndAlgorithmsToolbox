#pragma once
#include "element.h"
#include <iostream>
#include <string>
using namespace std;
class polynomial
{
private:
	element *el;
	int size;
public:
	polynomial();
	polynomial(int);
	double Calculate(float);
	void Read();
	void Write();
	polynomial operator+(polynomial);
	polynomial operator-(polynomial);

};

