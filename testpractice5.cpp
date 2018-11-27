#include <iostream>
using namespace std;
// This is another test of your knowledge of pass by value/reference
// It also includes recursion.

// For this question, assume that the inputs are given in the following order, when asked:
// 1) alphabetical
// 2) reverse alphabetical
// 3) c, d, u, m, p, a, r
// Play computer for each of these input cases.

int q(char, int);
int m(int &);

int main () {

	int p = 6;
	char y;
	cin >> y;
	
	cout << q(y, m(p)) << endl;

	return 0;
}

int m(int & v) {
	v *= v + v;
	return v;
}

int q(char y, int t) {
	cout << y << " " << t << endl;
	if (y <= 'g')
		return t;
	else {
		cin >> y;
		return q(y, t-1);
	}
}

