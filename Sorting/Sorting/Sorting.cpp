//#include <iostream>
#include "sorts.h"
//using namespace std;
int main()
{
	int r = 0;
	int a[6] = { 5,7,1,2,0,-8};
	//int a[6] = {-8,0,5,1,2,7};

	//int a[5] = { 1,3,7,6,5};
	sorts s;
	//s.bubblesort(a, 6);
	//s.selectionsort(a, 6);
	//s.insertionsort(a, 6);
	r = s.mergsortwihtinversioncount(a,0,5,r);
	cout <<"number of inversions: "<< r << endl;
	//s.quicksort(a, 0, 5);
	for (int i = 0; i < 6; i++) {
		cout << a[i] << '\t';
	}
    //cout << "Hello World!\n";
	return 0;
}

