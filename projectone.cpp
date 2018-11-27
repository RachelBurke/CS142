#include <iostream>
using namespace std;

int main () {
	
	cout << "Welcome! This program will tell what year anyone graduated or will graduate high school and how old they were or will be when they graduate(d), assuming that the normal school year start and end dates are in different years. (Ex./ 2014-2015 school year.)"
		<< endl;
	int birth;	
	cout << "What is the year of birth?" << endl;
	cin >> birth;
	int start;
	cout << "How old was or will the chosen person when they began or will begin school?" << endl;
	cin >> start;
	int skip;
	cout << "How many years of schooling has or will this person skip?" << endl;
	cin >> skip;
	int repeat;
	cout << "How many years of schooling did or will this person repeat?" << endl;
	cin >> repeat;
	int birthday;
	cout << "If this person had, has, or will have their birthday during the school year in which they graduated or will graduate, enter 0. If not, enter 1." << endl;
	cin >> birthday;
	int old;
	cout << "If this person started or will start kindergarten and then turned or will turn six during the same year, enter 1. If not, enter 0." << endl;
	cin >> old;
	int sixers;
	cout << "If this person was or will be six when they start kindergarten, enter 1. If not, enter 0." << endl;
	cin >> sixers;
	int summer;
	cout << "If this had started or will start kindergarten when they are four enter 1. If not, enter 0." << endl;
	cin >> summer;
	int gradyear = birth + start + (13 - skip + repeat) + summer + old;
	int gradage = start + (13 - skip + repeat) - birthday + sixers;
	cout << "The person you chose graduated or will graduate in " << gradyear << " and be " << gradage << "." << endl;
	
	return 0;
}