#include "element.h"

void element::setCoefficient(float coef) {
	coeficient = coef;
}
void element::setPower(int p) {
	power = p;
}
float element::getCoeficient() {
	return coeficient;
}
int element::getPower() {
	return power;
}
double element::Calculate(float x) {
	return coeficient * pow(x, power);
}
element::element() {
	power = 0; coeficient = 0;
}