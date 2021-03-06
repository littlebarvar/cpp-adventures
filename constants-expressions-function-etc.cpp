// Constants, operators, expressions etc

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

inline void keep_window_open()
{
	char ch;
	cin >> ch;
}

// write a function
int square(int x) {
	return x * x;
}

int main()
{
	constexpr int max = 20;  // a constexpr symbolic constant is a value that is known at compile time
	int foo = max;
	foo++;
	cout << foo << '\n';
	if (foo >= 21) {
		cout << "foo is greater than or eq 21!\n";
	}
	cout << "enter some char: ";
	char input = 'a';
	cin >> input;

	// Note: switch can operate on int, char or enum
	// We cannot use string as a type for input
	// The case labels must be constants
	switch (input) {
	case 'i': 
		cout << "Magic!\n";
		break;
	case 'r':
		cout << "Next...\n";
	case 'x':
		cout << "Brilliant!\n";
		break;
	default:
		cout << "Meh. \n";
		break;
	}
	
	int bar = 0;
	while (bar < 10) {
		cout << bar << '\t' << square(bar) << '\n';
		++bar;
	}

	keep_window_open();
	return 0;
}