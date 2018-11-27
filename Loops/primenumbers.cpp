#include <iostream>
using namespace std;

int main () {
	
	//ways to figure out if a number is prime: divide by all #s less than the # except 1 and the #
	
	int input;
	cin >> input;
	
	//flag variable
	// primeflag is 1 if input could still be prime, or 0 otherwise
	int primeflag = 1;
	
	int divisor = 2;
	while (divisor < input) {
		int remainder = input % divisor;
/*			if (remainder != 0) {
				cout << "Prime!!!" << endl;
			}
			else {
				cout << "Not Prime!!!" << endl;
			}
*/
			if (remainder == 0) {
				primeflag = 0;
				cout << "Failed Divisor " << divisor << endl;
			}
		
		divisor += 1; //or divisor++ or divisor = divisor + 1
	}	
	
	if (primeflag ==1) {
		cout << "Prime!" << endl;
	}
	
	else {
		cout << "Not Prime!" << endl;
	}
	return 0;
}