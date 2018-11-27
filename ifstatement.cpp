#include <iostream>
using namespace std;

int main () {
	
	// rain will have the value 'y' if it is raining and 'n' otherwise
	char rain;
	cout << "Is it raining, holmes? ";
	cin >> rain;

	/* comment in
	// template for an if statement
	if (boolean condition) {
		// do this stuff in the condition
		// dpo this stuff also
	}
	comment out */ 
	
	if (rain == 'y') {
		cout << "Basement. Minecraft. #Sad." << endl;
	}
	
	if (rain == 'n') {
		cout << "Frolic in a meadow full of shards of glass." << endl;
	}
	
	double grade;
	cout << "What is your numeric grade? ";
	cin >> grade;
	
	if (grade >= 90) {
		cout << "A-team, bro." << endl;
	}
	
	// nested if statement
	if (grade >= 80) {
		if (grade < 90) {
		cout << "Bees. Everywhere!"	<< endl;
		}
	}
	
	if (grade >= 70) {
		if (grade < 80) {
			cout << "C deez nuts." << endl;	
		}
	}
	
	if (grade >= 60) {
		if (grade < 70) {
			cout << "Doge." << endl;	
		}
	}
	
	if (grade < 60) {
		cout << "Epic Fail." << endl;
	}
	
	return 0;
}