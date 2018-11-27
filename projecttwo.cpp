#include <iostream>
using namespace std;

int main () {
	
	double minutes;
	cout << "Hello Silly Rabbit, tricks are for kids! If you would stop playing tricks, you would not be late. How many minutes are you late today?" << endl;
	cin >> minutes;
	
	int hours;
	double seconds;
	double rmin;
	
	int spm = 60;
	int mph = 60;
	int sph = 3600;
	
	int chopmin = minutes;
	rmin = chopmin % mph;
	seconds = minutes * spm;
	hours = minutes / mph;
	double hs = hours * sph;
	double ms = rmin * spm;
	double os = hs + ms;
	double rsec = seconds - os;
	
	cout << "You are " << hours << " hour(s), " << rmin << " minute(s), " << rsec << " and second(s) late." << endl;
	cout << "I will call your client. 'RING RING'" << endl;
	
	if (hours < 1 ) {
		cout << "Mr. Rabbit is on is way. Deal." << endl;
	}
	
	if (hours >= 1 && hours < 2) {
		cout << "Mr. Rabbit had a personal problem involving pants; he will arrive shortly." << endl;
	}
	
	if (hours >= 2 && hours < 5) {
		cout << "Mr. Rabbit is not the rabbit you are looking for." << endl;
	}
	
	if (hours >= 5 && hours < 10) {
		cout << "Dude, you've been totally stood up. Loser." << endl;
	}
	
	if (hours >= 10 && hours <20) {
		cout << "He's sick, man. He's like totally sick. Droopy ears and everything." << endl;
	}
	
	if (hours >=20) {
		cout << "You've waited that long? Hahahahaha." << endl;
	}
	return 0;
}