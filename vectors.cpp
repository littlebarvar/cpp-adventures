// Vectors

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
	// Examples of vectors
	vector<int> v = { 1,2,3,4,5,6,8 };
	vector<string> foobar = { "Foo", "Bar" };
	cout << foobar[1] << '\n';

	// Define a vector with a given size without specifying elements
	vector<int> v2(5); // vector of 5 ints initialized to 0
	vector<string> barbaz(4); // vector of 4 strings initialized to ""

	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << '\n';
	}
	//  range-for-loop
	for (string s : foobar) {
		cout << s << '\n';
	}
	// Growing a vector
	vector<double> v3;
	v3.push_back(1.1);
	v3.push_back(2.3);
	double sum = 0;
	for (double x : v3) sum += x;
	cout << sum << '\n';

	// These would produce errors
	//v2[42] = 42;
	//cout << foobar[2]; // error: vector subscript out of range!
	//v[2] = "foo"; // error: error C2440: '=': cannot convert from 'const char [4]' to 'int'

	keep_window_open();
	return 0;
}