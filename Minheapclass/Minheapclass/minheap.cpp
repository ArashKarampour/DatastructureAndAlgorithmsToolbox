#include "minheap.h"
#include <iostream>
using namespace std;


minheap::minheap(int m)
{
	ind = 0;
	maxsize = m;
	arr = new int[maxsize+1];
}


minheap::~minheap()
{
}

void minheap::Insert()
{
	int x;
	if (!Isfull()) {
		cin >> x;
		arr[++ind] = x;
		int i = ind;
		
		while (arr[i / 2] > arr[i] && i != 1) {
			int temp;
			temp = arr[i];
			arr[i] = arr[i / 2];
			arr[i / 2] = temp;
			i = i / 2;
		}
		
	}
	else
		cout << "Is full" << endl;
}

int minheap::Delete()
{
	if (!Isempty()) {
		int ret = arr[1];
		arr[1] = arr[ind--];
		int i = 1;
		while ((arr[i] >= arr[2 * i] || arr[i] >= arr[2 * i + 1]) && (2 * i <= ind)) {
			if (arr[2 * i] < arr[2 * i + 1]) {
				int temp = arr[i];
				arr[i] = arr[2 * i];
				arr[2 * i] = temp;
				i = 2 * i;
			}
			else {
				int temp = arr[i];
				arr[i] = arr[2 * i + 1];
				arr[2 * i + 1] = temp;
				i = 2 * i + 1;
			}
		}
		return ret;
	}
	else
		return NULL;
}

bool minheap::Isempty()
{
	if (ind == 0)
		return true;
	
	return false;
}

bool minheap::Isfull()
{
	if (ind == maxsize)
		return true;

	return false;
}
