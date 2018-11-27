#include <iostream>
using namespace std;

//function declaration
int pyramidscheme(int);

int main () {
	
	// I want 10 million dollars
	int n = 10;
	cout << pyramidscheme(n) << endl;
	
	return 0;
}

//function definition

int pyramidscheme (int n) {
	cout << n << endl;
	
	if (n == 1) {//If I am Paco
		return 1;	
	}
	return 1 + pyramidscheme (n-1); //Calling same function in the function with different parameter
}

//not responsible for writing on main exam but can be put on bonus
//may be asked to trace this
