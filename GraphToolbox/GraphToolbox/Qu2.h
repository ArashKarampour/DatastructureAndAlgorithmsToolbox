#pragma once
#include <iostream>
using namespace std;
class Qu2
{
private:
	int Size;
	int Front;
	int End;
	int * list;
public:
	Qu2(int);
	~Qu2();
	bool is_full();
	bool is_empty();
	void add(int);
	int del();
};