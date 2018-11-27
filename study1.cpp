#include <iostream>
using namespace std;

int main () {
	
	double number;
	cout << "Please type in the human number of the number of links in the chain";
	cout <<	"Mr. Rabbit needs to make: ";
	cin >> number;
	cout << "Mr. Rabbit, on the next line will be the Roman number of links in the chain you need to make:  " << endl;
	
	int m, d, c, l, x, v, i, remainder, numlet;
	remainder = number;
	
	while (remainder != 0){
		if (remainder >= 1000) {
			m = remainder / 1000;
			numlet = 0;
			for (numlet; numlet < m; numlet++) {
			cout << "M";
			}
			remainder %= 1000;
		}
		
		if (remainder >= 900) {
			cout << "CM";
			remainder %= 900;
		}
		
		if (remainder >= 500) {
			cout << "D";
			remainder %= 500;
		}
		
		if (remainder >= 400) {
			cout << "CD";
			remainder %= 400;
		}
		
		if (remainder >= 100) {
			c = remainder / 100;
			numlet = 0;
			for (numlet; numlet < c; numlet++) {
				cout << "C";
			}
				remainder %= 100;
		}
		
		if (remainder >= 90) {
			cout << "XC";
			remainder %= 90;
		}
		
		if (remainder >= 50) {
			cout << "L";
			remainder %= 50;
		}
		
		if (remainder >= 40) {
			cout << "XL";
			remainder %= 40;
		}
		
		if (remainder >= 10) {
			x = remainder / 10;
			numlet = 0;
			for (numlet; numlet < x; numlet++) {
				cout << "X";
			}
				remainder %= 10;
		}
		
		if (remainder >= 9) {
			cout << "IX";
			remainder %= 9;
		}
		
		if (remainder >= 5) {
			cout << "V";
			remainder %= 5;
		}
		
		if (remainder >= 4) {
			cout << "IV";
			remainder %= 4;			
		}
		
		if (remainder >= 1) {
			i = remainder;
			numlet = 0;
			for (numlet; numlet < i; numlet++) {
				cout << "I";
			remainder -= 1;	
			}
		}
	}
	cout << endl;
	
	return 0;
}
