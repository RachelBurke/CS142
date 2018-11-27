#include <iostream>
using namespace std;

int main () {
	
	double grade;
	cout << "What is your numeric grade? ";
	cin >> grade;
	
	if (grade >= 90) {
		cout << "A-team, bro." << endl;
	}
	
	if ((grade >= 80) && (grade < 90)) {
		cout << "Bees. Everywhere." << endl;
	}
	
	if ((grade >= 70) && (grade < 80)) {
		cout << "C spot run." << endl;
	}
	
	if ((grade >= 60) && (grade < 70)) {
		cout << "Deez nuts." << endl;
	}
	
	if ((grade < 60)) {
		cout << "Failbot." << endl;
	}
	
	// Fresh Start, sort of 
	
	if (grade >= 90) {
		cout << "A" << endl;
	}
	else if (grade >= 80) {
		cout << "B" << endl;
	}
	else if (grade >= 70) {
		cout << "C" << endl;
	}
	else if (grade >= 60) {
		cout << "D" << endl;
	}
	else {
		cout << "F" << endl;
	}
	
	
	return 0;
}
