#include "Inp.h"



int Inp::minfinishtime(float * c,int n)
{
	float min = FLT_MAX; int min_ind;
	for (int i = 0; i < n; ++i) {
		if (c[i] < min) {
			min = c[i], min_ind = i;
		}
	}
	return min_ind;
}

void Inp::nOfMinClasses(Lecture *L,int size)
{
	for (int i = 0; i<size; ++i) {
		int min = L[i].start;
		for (int j = i + 1; j<size; ++j) {
			if (L[j].start < min) {
				min = L[j].start;
				swap(L[j], L[i]);
			}
		}
	}
	float  * ClassRFT = new float[size];//Class Room Finish Time of it's last lecture array;

	for (int i = 0; i < size; ++i)
		ClassRFT[i] = FLT_MAX;

	int numclass = 1;
	ClassRFT[0] = 0;

	for (int i = 0; i < size; ++i) {
		int mft_ind = minfinishtime(ClassRFT, size);//minimun finish time index
		if (L[i].start >= ClassRFT[mft_ind]) {
			ClassRFT[mft_ind] = L[i].finish;
		}
		else {
			++numclass;
			++mft_ind;
			while(ClassRFT[mft_ind] != FLT_MAX) {
				++mft_ind;
			}
			ClassRFT[mft_ind] = L[i].finish;
		}
	}
	cout << "The minimum number of classes would be : " << numclass;
}

Inp::Inp()
{
}


Inp::~Inp()
{
}
