// Dumb calculator

#include "stdafx.h"
#include "std_lib_facilities.h"

using namespace std;

int main()
{
	cout << "Please eenter expression (+, -, *, /)\n";
	cout << "Terminate expression by appending x (e.g. 1+2x)\n";

	int lval = 0;
	int rval;
	cin >> lval;
	if (!cin) error("no first operand!");
	for (char op; cin >> op;) {
		if (op != 'x') cin >> rval;
		if (!cin) error("no second operand!");
		switch (op) {
		case '+':
			lval += rval;
			break;
		case '-':
			lval -= rval;
			break;
		case '*':
			lval *= rval;
			break;
		case '/':
			lval /= rval;
			break;
		default:
			cout << "Result: " << lval << '\n';
		}
	}

	keep_window_open();
	return 0;
}