#pragma once
#include <iostream>
using namespace std;
class Queue
{
private:
	int Size;
	int Front;
	int End;
	int * list;
public:
	Queue(int);
	~Queue();
	bool is_full();
	bool is_empty();
	void add(int);
	int del();
};

