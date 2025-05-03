#include "polynomial.h"
#include "element.h"

void polynomial::Write() {
	for (int i = 0; i < size; i++) {
		if (el[i].getCoeficient() > 0 && i != 0 && el[i].getCoeficient() != 0)
			cout << "+";
		if (el[i].getCoeficient() != 0)
			cout << el[i].getCoeficient() << "X^" << el[i].getPower();

	}
	cout << endl;
}




void polynomial::Read() {
	cout << "enter your phrase: " << "example: 2x^3-2" << endl;
	char str[30];
	cin >> str;
	double tmpzarib, tmptavan;
	int i = 0, count = 0; bool firstsign = true;
	while (str[i - 1] != '\0') {
		int coefsign = 1;
		//Read Zarib
		tmpzarib = 0, tmptavan = 0;
		if (str[i] == 'X' || str[i] == 'x')
			tmpzarib = 1;
		while (str[i] != 'x' && str[i] != 'X' && str[i] != '\0') {
			
			if (str[i - 1] == '-')
				coefsign *= -1;
			if (str[0] == '-' && firstsign) {
				coefsign *= -1;
				firstsign = false;
				i++;
			}
			
			tmpzarib = (tmpzarib * 10 + coefsign*(str[i] - 48));
			i++;
			
		}

		//Read Tavan
		if (str[i] != 'x' && str[i] != 'X')
			tmptavan = 0;
		else {
			i += 2;
			int powsign = 1;
			if (str[i] == '-') {
				powsign *= -1;
				i++;
			}
			

			while (str[i] != '+' && str[i] != '-' && str[i] != '\0') {
				tmptavan = (tmptavan * 10 + powsign*(str[i] - 48));
				i++;
			}
		}
		el[count].setPower(tmptavan);
		el[count].setCoefficient(tmpzarib);
		count++;
		i++;
	}
}



double polynomial::Calculate(float x) {
	double result = 0;
	for (int i = 0; i < size; i++)
		result += el[i].Calculate(x);
	return result;
}

polynomial polynomial::operator+(polynomial p1)
{
	polynomial p3(size + p1.size);
	
		int k = 0 ,i = 0,j = 0;
		
		while (i + j < p1.size + size - 1) {
			if (el[i].getPower() == p1.el[j].getPower()) {
				p3.el[k].setCoefficient(el[i].getCoeficient() + p1.el[j].getCoeficient());
				p3.el[k].setPower(el[i].getPower());
				k++; i++; j++;
			}
			else if (el[i].getPower() > p1.el[j].getPower()) {
				p3.el[k].setCoefficient(el[i].getCoeficient());
				p3.el[k].setPower(el[i].getPower());
				i++; k++;
			}
			else {
				p3.el[k].setCoefficient(p1.el[j].getCoeficient());
				p3.el[k].setPower(p1.el[j].getPower());
				j++; k++;
			}
		}
	
	return p3;
}

polynomial polynomial::operator-(polynomial p1)
{
	polynomial p3(size + p1.size);

	int k = 0, i = 0, j = 0;

	while (i + j < p1.size + size - 1) {
		if (el[i].getPower() == p1.el[j].getPower()) {
			p3.el[k].setCoefficient(el[i].getCoeficient() - p1.el[j].getCoeficient());
			p3.el[k].setPower(el[i].getPower());
			k++; i++; j++;
		}
		else if (el[i].getPower() > p1.el[j].getPower()) {
			p3.el[k].setCoefficient(el[i].getCoeficient());
			p3.el[k].setPower(el[i].getPower());
			i++; k++;
		}
		else {
			p3.el[k].setCoefficient(-p1.el[j].getCoeficient());
			p3.el[k].setPower(p1.el[j].getPower());
			j++; k++;
		}
	}

	return p3;
}


polynomial::polynomial() {
	size = 50;
	el = new element[50];
}
polynomial::polynomial(int num) {
	size = num;
	el = new element[num];
}

