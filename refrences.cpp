#include <iostream>
using namespace std;

int main () {
	
	int x = 7;
	int y = 13;
	int z = 11;
	
	//Create a reference variable (or an alias
	//A reference refers to the "address" of a variable
	
	int & w = z; //variable reference
	int & r = z;
	z = 23;
	cout << z << endl;
	cout << w << endl;
	cout << endl << endl;
	
	cout << z << endl;
	cout << &z << endl; //prints the address of z
	cout << &w << endl; //same address
	cout << &r << endl; //same
	
	
	return 0;
}