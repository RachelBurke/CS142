#include <iostream> //header files
#include <math.h> // ""
using namespace std;

//function declaration
void beerverse (int);

int main () {
	
	// function callout
	int beers = 99;
	for (int b = beers; b>0; b--) {
		beerverse (b);
	}
	
	
	return 0;
}

//function definition
void beerverse (int bottles) {
	if (bottles == 1) {
		cout << bottles << " bottle of beer on the wall," << endl;
		cout << bottles << " bottle of  BBEEERR!!!" << endl;
		cout << "Take one down, pass it around... " << endl;
	}
			
	else {
		cout << bottles << " bottles of beer on the wall," << endl;
		cout << bottles << " bottles of  BBEEERR!!!" << endl;
		cout << "Take one down, pass it around... " << endl;
	}
		bottles = bottles - 1;
	if (bottles == 1) {
		cout << bottles << " bottle of beer on the wall!" << endl << endl;
	}
	else {
		cout << bottles << " bottles of beer on the wall!" << endl << endl;	
		}
		//void functions don't need return statements
}