#include <iostream>
using namespace std;
// This program tests your understanding of pass by value and pass by reference

int a(int, int);
int b(int &);

int main () {

	int n = 7;
	cout << a(n, b(n)) << endl;
	cout << n << endl;
	
	return 0;
}

int a(int x, int y) {
	cout << x << " " << y << endl;
	return x/y + x * y;
}

int b(int & z) {
	cout << z << endl;
	z /= 2;
	cout << z << endl;
	return (z+6)*3;
}
