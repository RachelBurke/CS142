#include <iostream>
#include <iomanip>
using namespace std;

//function declarations
double thatwhatshesaid(int [], int); // the second int will keep track of the size of the array
void print(int [][6], int);

int main () {
	
	int a[10] = {2, 3, 5, 7, 1, 16, 2, 3, 2, 69};
	
	//average of array a
	double avg = 0;
	for (int x = 0; x < 10; x++) {
		avg += a[x];
	}
	avg /= 10;
	cout << avg << endl;
	
	//------------------------------
	
	//Function Call
	cout << thatwhatshesaid(a, 10) << endl;
	
	int b [4][6] ={0};
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 6; y++)
		b[x][y] = x * 10 + y;
	}
	
	// Must explicitly send the number of rows
	print (b, 4);
	
	return 0;
}
//Function Definition
double thatwhatshesaid(int b[], int size ) {
	// All arrays are pass by reference and not pass by value
	//b is an alias of the array a
		double avg = 0;
	for (int x = 0; x < 10; x++) {
		avg += b[x];
	}
	avg /= 10;
	return avg;
}

void print(int c[][6], int rows) {
	for (int x = 0; x < rows; x++){
		for (int y = 0; y < 6; y++) {
			cout << setw(2) << c[x][y] << " ";
		}
		cout << endl;
	}
}