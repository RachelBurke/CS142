#include <iostream>
using namespace std;
// This program tests your understanding of recursive functions

int f(int n);

int main () {
	
	int n = 4;
	cout << f(n) << endl;

	return 0;
}

int f(int n) {
	if (n < 2)
		return 7*n;
	return f(n-1) * f(n/2);
}
