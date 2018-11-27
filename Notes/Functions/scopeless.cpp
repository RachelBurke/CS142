#include <iostream>
using namespace std;

int scopeless (int&);

int main () {
	
	int n = 7;
	cout << n << endl;
	cout << scopeless(n) << endl;
	cout << n << endl;
	
	return 0;
}

int scopeless (int & y) {
	y = 0;
	return 213;
}