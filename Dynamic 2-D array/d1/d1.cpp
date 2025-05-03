#include <iostream>
#include <conio.h>
using namespace std;
class Array
{
private:
	int **p, r, c;
public:
	void setsize();
	void detsroy();

};
void Array::setsize()
{
	cin >> r >> c;
	p = new int*[r];
	for (int i = 0; i < r; i++)
		p[i] = new int[c];
}
void Array::detsroy()
{
	for (int i = 0; i < r; i++)
		delete p[i];
	delete p;
}

int main()
{
    cout << "Hello World!\n"; 
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

