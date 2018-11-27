#include <iostream>
using namespace std;

int main () {

	int day1, day2, day3;
	
	cout << "You are the chosen care bear slayer! "
		<< "Go forth and kill them with fire. "
		<< endl;
	
	cout << "Worthless stuffed toy murder, how many care bears died on the first day? "
		<< endl;
	cin >> day1;
	cout << "How many did you murder on the second day?"
		<< endl;
	cin >> day2;
	cout << "Day three was a great day to slay the bears.  How many died?"
		<< endl;
	cin >> day3;

	int total_killings = day1 + day2 + day3;
	double average = (day1 + day2 + day3)/3.0;
	
	cout << "In three days you killed " << total_killings << " bears. This is an average of " << average << ". Go kill some more!, mighty slayer!" << endl;
	// you can also say cout << "In three days you killed " << day1 + day2 + day3 << ......
	
	return 0;
}