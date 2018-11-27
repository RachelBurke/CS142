#include <iostream>
using namespace std;

int main () {
	
	int a [6][7];
	
	a[2][3] = 13;
	
	//Jared Fogle error. Bad touches. Don't do this.
	//cout << a[6][7] << endl;
	
	// Print out the 2-dim array
	for (int row = 0; row < 6; row ++) {
		for (int col = 0; col < 7; col++) {
			cout << a[row][col] << " ";
		}
		cout << endl;
	}
	
	return 0;
}