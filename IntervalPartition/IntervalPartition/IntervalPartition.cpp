//#include <iostream>
//#include "Lecture.h"
#include "Inp.h"
//using namespace std;
int main()
{
	//All the numbers below are based on the 04GreedyAlgorithmsI.pdf page 21
	Inp p;
	Lecture *l = new Lecture[10];
	l[0].start = 9;
	l[0].finish = 10.30;
	l[1].start = 11;
	l[1].finish = 12.30;
	l[2].start = 13;
	l[2].finish = 14.30;
	l[3].start = 15;
	l[3].finish = 16.30;
	l[4].start = 9;
	l[4].finish = 12.30;
	l[5].start = 13;
	l[5].finish = 14.30;
	l[6].start = 15;
	l[6].finish = 16.30;
	l[7].start = 9;
	l[7].finish = 10.30;
	l[8].start = 11;
	l[8].finish = 14;
	l[9].start = 14.15;
	l[9].finish = 16.30;
	p.nOfMinClasses(l, 10);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
