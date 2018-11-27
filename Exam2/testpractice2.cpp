#include <iostream>
using namespace std;
// This program tests your understanding of nested functions
// and pass by value/reference

int c(int);
int d(int);
int f(int & n);

int main () {
	
	int n = 5;
	cout << f(n) << endl;

	return 0;
}

int f(int & n) {
	n += c(n*2) + d(c(n/2));
	return n* d(4);
}

int c(int x) {
	return d(x+2);
}

int d(int y) {
	return y - 4;
}
