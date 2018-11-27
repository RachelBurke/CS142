#include <iostream>
//ASCII - American Standard Code for Information Interchange
// 2^7 (128) entries in ASCII
// Thomas is in the basement of Holcomb
using namespace std;

int main () {
	
	char p = 'x';
	p += 1;
	
	cout << p << endl;
	cout << (int) p << endl;  // typecasting - treat p like an integer
	cout << (char) 121 << endl;

	for (int x = 0; x < 128; x++) 
		cout << x << " " << char (x) << endl;
	
	return 0;
}

// byte = 8 bits = 0 or 1
