#include <iostream>
using namespace std;

int main () {
	
	int beers = 99;
	
	while (beers > 0) {
		if (beers == 1) {
			cout << beers << " bottle of beer on the wall," << endl;
			cout << beers << " bottle of  BBEEERR!!!" << endl;
			cout << "Take one down, pass it around... " << endl;
		}
			
		else {
			cout << beers << " bottles of beer on the wall," << endl;
			cout << beers << " bottles of  BBEEERR!!!" << endl;
			cout << "Take one down, pass it around... " << endl;
		}
		
		
		beers = beers - 1;
		if (beers == 1) {
			cout << beers << " bottle of beer on the wall!" << endl << endl;
		}
		else {
			cout << beers << " bottles of beer on the wall!" << endl << endl;	
		}
		
	} // end while
	
	
	return 0;
}
