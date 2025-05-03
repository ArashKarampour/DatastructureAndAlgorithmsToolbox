#pragma once
#include<math.h>
class element {
private:
	int power;
	float coeficient;
public:
	element();
	double Calculate(float);
	int getPower();
	float getCoeficient();
	void setPower(int);
	void setCoefficient(float);
};

