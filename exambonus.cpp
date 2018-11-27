#include <iostream>
using namespace std;

int main () {
	
	cout << "Please type in a three digit number." << endl;
	int num;
	cin >> num;
	
	int h, t, o , total;
	
	if (num >= 100) {
		h = num / 100;
		num = num % 100;
	}
	
	if (num >= 10) {
		t = num / 10;
		num = num % 10;
	}
	
	if (num >= 1) {
		o = num;
	}
	
	total = h + t + o;
	
	cout << "The sum of the digits is " << total << endl;
	
	return 0;
}