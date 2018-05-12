//Less dumb calculator

#include "stdafx.h"
#include "std_lib_facilities.h" // Stroustrup's header file

using namespace std;

class Token {
public:
	char kind;
	double value;
	Token(char ch) // make a Token from char
		:kind(ch), value(0) {}
	Token(char ch, double val)
		:kind(ch), value(val) {
	}
};


class Token_stream {
public:
	Token_stream();
	Token get(); // get a Token
	void putback(Token t); // put a Token back
private:
	bool full{ false }; // is there a Token in the buffer
	Token buffer; // where we store a Token to put back using putback()
};

Token_stream::Token_stream()
	:full(false), buffer(0) {}

void Token_stream::putback(Token t) {
	if (full) error("putback() into a full buffer");
	buffer = t;
	full = true;
}

Token Token_stream::get()
{
	if (full) {
		full = false;
		return buffer;
	}
	char ch;
	cin >> ch;
	switch (ch) {
	case ';':
	case 'q':
	case '(': case ')': case '+': case '-': case '*': case '/':
		return Token{ ch };
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token{ '8', val }; // let '8' represent a number
	}
	default:
		error("Bad token");
	}
}

Token_stream ts;

double expression(); // declaration so that primary can call expression 

double primary() {
	Token t = ts.get();
	switch (t.kind) {
	case '(': {
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d;
		}
	case '8': // we use '8' to represent a number
		return t.value;
	default: 
		error("primary expected");
	}
}

double term() {
	double left = primary();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '*':
			left *= primary();
			t = ts.get();
			break;
		case '/': {
			double d = primary();
			if (d == 0) error("division by zero");
			left /= d;
			t = ts.get();
			break;
			}
		default:
			ts.putback(t);
			return left;
		}
	}
}

double expression() {
	double left = term(); // read and evaluate a Term
	Token t = ts.get(); // get the next token
	while (true) {
		switch (t.kind) {
		case '+':
			left += term(); // evaluate Term and add
			t = ts.get();
			break;
		case '-':
			left -= term();
			t = ts.get();		
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

int main()
{
	double val = 0;
	try {
		while (cin) {
			Token t = ts.get();
			if (t.kind == 'q') break; // 'q' for quit
			if (t.kind == ';') // ';' for print now
				cout << "=" << val << '\n';
			else
				ts.putback(t);
			val = expression();
		}
	}
	catch (exception& e) {
		cerr << e.what() << '\n';
	}
	catch (...) {
		cerr << "exception\n";
	}
	keep_window_open();
	return 0;
}