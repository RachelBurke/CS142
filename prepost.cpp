#include <iostream>
using namespace std;

int main () {
	
	int a = 6;
	a = a + 4;
	a += 4;
	a += 1;
	
	a++; // short cut that does the same thing as a + 1
	a--; // short cut that does the same thing as a - 1
	
	int y = 6;
	cout << y + 1 << endl;
	cout << y << endl;
	
	cout << endl;
	
	cout << y++ << endl;
	cout << y << endl;
	
	cout << endl;
	
	cout << ++y << endl;
	cout << y << endl;
	
	return 0;
}