#pragma once
#include <iostream>
using namespace std;
class sorts
{
	
public:
	void bubblesort(int arr[], int);
	void selectionsort(int arr[], int);
	void insertionsort(int arr[], int);
	int mergsortwihtinversioncount(int arr[], int,int,int);
	int merge(int arr[],int,int,int);
	void quicksort(int arr[], int, int);
	int partition(int arr[], int, int);
	sorts();
	~sorts();
};

