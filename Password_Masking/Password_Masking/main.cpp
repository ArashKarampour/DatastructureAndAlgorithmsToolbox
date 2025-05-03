#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

int main()
{
	//CodeTopic:Password_Masking_With_Asterisk(PMWA)
	string pass = "";
	char ch;
	cout << "Enter pass\n";
	ch = _getch();
	while (ch != '\r') {
		if (((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || (ch >= '0'&& ch <= '9')) && ch != '\0' && ch != '\b')
		{
			pass.push_back(ch);
			cout << '*';
		}

		ch = _getch();
		if (ch == '\b'&& pass.length() != 0)
		{
			cout << "\b \b";
			pass.resize(pass.length() - 1);
			ch = '\0';
		}

	}
	cout << endl << pass << endl;


	_getch();

	return 0;
}