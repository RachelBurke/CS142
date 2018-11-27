#include <iostream>
#include <fstream>
// object - type of storage for data and functions associated with it
// iostream contains things called 'streams'
// stream objects - store data and moves the data from one place to another place
   // input/output stream object (iostream object) - ex cout (output); cin (input)
        // cout comes from CRT cathode ray tube
		// cout knows setw(#) - set width to # of spaces
	// file stream object - move data to and from files
		// ofstream -> memory to file (like saving a file) : output file stream object
		// ifstream -> file to memory (like opening a file) : input file stream object

using namespace std;

int main () {
	
	ofstream nuggets; // nuggets is the variable that sends information
	nuggets.open ("times.txt");
	
	cout << "Beat them with a heroine pan" << endl;
	int x = 5;
	
	nuggets << x << " times!" << endl;
	
	nuggets.close ();
	
	

	
	return 0;
}
