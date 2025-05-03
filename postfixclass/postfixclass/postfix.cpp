#include "postfix.h"

postfix::postfix()
{
	snsize = 0;
}


postfix::~postfix()
{
}

int postfix::getsnsize()
{
	for (int i = 0; infix[i] != '\0'; i++) {
		if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '(' || infix[i] == '^')
			snsize++;
	}
	return snsize;
}

void postfix::setinfix()
{
	cout << "Enter your infix phrase :";
	cin >> infix;
	setoutput();
}

void postfix::setoutput()
{
	stack s1(getsnsize());
	for (int i = 0; infix[i] != '\0'; i++) {
		if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '(' || infix[i] == '^' || infix[i] == ')')
			checkpriority(infix[i], s1, s1.stackcurser());
		else
			output.append(infix.substr(i, 1));
	}
	while (!s1.isempty()) {
		output.append(s1.pop());
	}
}

void postfix::checkpriority(char in, stack &s1, int sc)
{
	string *S = s1.getstackarr();

	if (!s1.isempty()) {
		if (in == '(')
			s1.push(in);
		else if (in == ')') {
			for (int i = sc; S[i] != "("; i--)
				output.append(s1.pop());
			s1.pop();
		}
		else if (in == '^') {
			for (int i = sc; S[i] == "^"; i--)
				output.append(s1.pop());
			s1.push(in);
		}
		else if (in == '*' || in == '/') {
			for (int i = sc; (S[i] == "^" || S[i] == "*" || S[i] == "/"); i--)
				output.append(s1.pop());
			s1.push(in);
		}
		else {
			for (int i = sc; (S[i] == "+" || S[i] == "-" || S[i] == "^" || S[i] == "*" || S[i] == "/"); i--)
				output.append(s1.pop());
			s1.push(in);
		}
	}
	else if (s1.isempty())
		s1.push(in);

}



void postfix::getoutput()
{
	cout << output;
}