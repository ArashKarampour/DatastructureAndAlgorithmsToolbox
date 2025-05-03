#include "sorts.h"



void sorts::bubblesort(int arr[], int n)
{
	bool swapped;
	for (int i = 0; i < n; i++) {
		swapped = false;
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				swap(arr[i], arr[j]);
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
}

void sorts::selectionsort(int arr[], int n)
{
	int k;
	for (int i = 0; i < n; i++) {
		k = i;
		for (int j = i + 1; j < n; j++) 
			if (arr[j] < arr[k]) 
				k = j;
		swap(arr[i], arr[k]);
			
	}

}

void sorts::insertionsort(int arr[], int n)
{
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j -= 1;
		}
		arr[j + 1] = key;
	}
}
int sorts::mergsortwihtinversioncount(int arr[], int f, int l,int r)
{
	
	if (f < l) {
		int m = (f + l) / 2;
		r = mergsortwihtinversioncount(arr, f, m,r);
		r = mergsortwihtinversioncount(arr, m + 1, l,r);
		r += merge(arr, f, m, l);
	}
	return r;
}

int sorts::merge(int arr[], int f, int m, int l)
{
	int i, j, k;
	int x = m-f+1, inversion=0; //this line is for inversion counting
	int * b = new int[l + 1];
	i = f; j = m + 1; k = f;
	
	while (i <= m && j <= l ) {
		if (arr[i] < arr[j]) {
			b[k++] = arr[i++];
			x--;
		}
		else {
			b[k++] = arr[j++];
			inversion += x;
		}
	}
	while(i <= m)
		b[k++] = arr[i++];

	while(j <= l)
		b[k++] = arr[j++];

	for (i = f; i <= l; i++)
		arr[i] = b[i];
	return inversion;
}

void sorts::quicksort(int arr[], int f, int l)
{
	if (f < l) {
		int p = partition(arr, f, l);
		quicksort(arr, f, p - 1);
		quicksort(arr, p + 1, l);

	}
}

int sorts::partition(int arr[], int f, int l)
{
	int pivot = arr[l];
	int i = f - 1;
	for (int j = f; j < l; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}

	}
	swap(arr[i + 1], arr[l]);

	return (i+1);
}


sorts::sorts()
{
}


sorts::~sorts()
{
}
