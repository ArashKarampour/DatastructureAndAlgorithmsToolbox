
#include <iostream>
#include "SparseMat.h"

int main()
{
	SparseMat s ,b;
	s.printnonsp();
	b.printnonsp();
	s.Sum(b);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


SparseMat:: SparseMat()
{
	cout << "enter number of rows : "; cin >> row;
	cout << "enter number of columnss : "; cin >> col;
	sparr = new int *[row];
	for (int i = 0; i < row; i++)
		sparr[i] = new int[col];

	for(int i = 0;i < row;i++)
		for (int j = 0; j < col; j++)
		{
			cout << "enter element [" << i << "]" << "[" << j << "]" << endl;
			cin >> sparr[i][j];
			if (sparr[i][j] != 0)
				nonzero++;
		}
	nonsp = new int *[3];
	for (int i = 0; i < 3; i++)
		nonsp[i] = new int[nonzero+1];

	nonsp[0][0] = row; nonsp[1][0] = col; nonsp[2][0] = nonzero;
	int nonspcol = 1;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			if (sparr[i][j] != 0) {
				nonsp[0][nonspcol] = i; nonsp[1][nonspcol] = j; nonsp[2][nonspcol] = sparr[i][j];
				nonspcol++;
			}
		}





}


SparseMat::~SparseMat()
{
	/*for (int i = 0; i < row; i++)
		delete sparr[i];
	delete sparr;*/

}

int ** SparseMat::getnonsp()
{
	return nonsp;
}

void SparseMat::printnonsp()
{
	cout << "["<<endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < nonzero + 1; j++)
			cout <<" "<< nonsp[i][j]<<" ";
		cout << endl;
	}
	cout << "]";
}

void SparseMat::Sum(SparseMat b)
{
	int i = 1, j = 1, k = 1;
	int **nsp;
	nsp = new int *[3];
	for (int i = 0; i < 3; i++)
		nsp[i] = new int[nonzero + b.nonzero];

	nsp[0][0] = row; nsp[1][0] = col; //nsp[2][0] = nonzero + b.nonzero;
	int nonspcol = 0;
	/*for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			if (sparr[i][j] != 0) {
				nonsp[0][nonspcol] = i; nonsp[1][nonspcol] = j; nonsp[2][nonspcol] = sparr[i][j];
				nonspcol++;
			}
		}*/
	while (i <= nonzero || j <= b.nonzero) {
		if (i > nonzero) {
			nsp[0][k] = b.nonsp[0][j];
			nsp[1][k] = b.nonsp[1][j];
			nsp[2][k] = b.nonsp[2][j];
			j++; k++; nonspcol++;
		}
		else if (j > b.nonzero) {
			nsp[0][k] = nonsp[0][i];
			nsp[1][k] = nonsp[1][i];
			nsp[2][k] = nonsp[2][i];
			i++; k++; nonspcol++;
		}
		else if (nonsp[0][i] == b.nonsp[0][j]) {
			if (nonsp[1][i] == b.nonsp[1][j]) {
				nsp[0][k] = nonsp[0][i];
				nsp[1][k] = nonsp[1][i];
				nsp[2][k] = nonsp[2][i] + b.nonsp[2][j];
				i++; j++; k++; nonspcol++;
			}
			else if (nonsp[1][i] > b.nonsp[1][j]) {

				nsp[0][k] = b.nonsp[0][j];
				nsp[1][k] = b.nonsp[1][j];
				nsp[2][k] = b.nonsp[2][j];
				j++; k++; nonspcol++;

			}
			else if (nonsp[1][i] < b.nonsp[1][j]) {

				nsp[0][k] = nonsp[0][i];
				nsp[1][k] = nonsp[1][i];
				nsp[2][k] = nonsp[2][i];
				i++; k++; nonspcol++;

			}
		}
		else if (nonsp[0][i] > b.nonsp[0][j]) {
			 
			nsp[0][k] = b.nonsp[0][j];
			nsp[1][k] = b.nonsp[1][j];
			nsp[2][k] = b.nonsp[2][j];
			j++; k++; nonspcol++;
			
		}
		else if (nonsp[0][i] < b.nonsp[0][j]) {

			nsp[0][k] = nonsp[0][i];
			nsp[1][k] = nonsp[1][i];
			nsp[2][k] = nonsp[2][i];
			i++; k++; nonspcol++;

		}

	}
	nsp[2][0] = nonspcol;
	cout << "[" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < nonspcol + 1; j++)
			cout << " " << nsp[i][j] << " ";
		cout << endl;
	}
	cout << "]";
	
}
