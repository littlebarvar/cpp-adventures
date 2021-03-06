// Errors

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

int area(int l, int w) {
	return l * w;
}

class Non_Positive_Area_Argument {};

int better_area(int l, int w) {
	if (l <= 0 || w <= 0) throw Non_Positive_Area_Argument{};
	return l * w;
}

void error(string s) {
	throw runtime_error(s);
}

int main()
{
	cout << "Hello, errors!\n";

	// Compile time error
	//int s1 = area(7); // error C2660: 'area': function does not take 1 arguments

	// Type error
	//int s2 = area(8, "bad"); // error C2664: 'int area(int,int)': cannot convert argument 2 from 'const char [4]' to 'int'

	// Non-errors
	//int s3 = area(10, 5.95); // warning C4244: 'argument': conversion from 'double' to 'int', possible loss of data
	//int s4 = area(1000, 99999999999); // warning C4305: 'argument': truncation from '__int64' to 'int'

	try {
		int s5 = better_area(110, -5);
	}
	catch (Non_Positive_Area_Argument) {
		cout << "better_area expects positive arguments!\n";
	}

	// Narrowing errors
	// <..> brackets are used when we need to specify a type, and are called template arguments
	// Note: narrow_cast is defined in Stroustrup's "std_lib_facilities
	//int x1 = narrow_cast<int>(2.9); // throws
	//int x2 = narrow_cast<int>(2.0); // ok

	vector<int> v(5);
	try {
		int x = v[5];
	} 
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		keep_window_open();
		return 1; // indicate failure
	}
	catch (...) {
		cerr << "unknown exception!\n";
		keep_window_open();
		return 2;
	}
	keep_window_open();
	return 0;
}