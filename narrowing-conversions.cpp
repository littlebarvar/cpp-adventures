// Example of narrowing conversions


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

int main()
{
	double d = 0;
	while (cin >> d) {
		int i = d; // squeeze double into int
		char c = i; // squeeze int into char
		int i2 = c; // get the integer value of the char
		cout << "d is " << d
			<< " i is " << i
			<< " i2 is " << i2
			<< " char is " << c
			<< '\n';
	}
	keep_window_open();
}

// it is better to write "universal and uniform initialization"
// int i { d };