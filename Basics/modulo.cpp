#include <iostream>
using namespace std;

int main () {
	
	int r = 23;
	int answer = 23/5; //4
	int remainder = 23 % 5; //3
	
	int a = 37 % 4; //1
	int b = 45 % 7; //3
	int c = 40 % 10; //0
	int d = 4 % 9; //4
	
	// Modulo (or mod) has the same order of operations as division
	
	int e = 40 + 5 % 3 + 7; //49
	
	/* // Template of while loop
	
	while (condition is true) {
		//do this stuff
		//do this stuff also
	}
	*/
	
	int times = 1;
	// infinite loop 
	
	while (times <= 10) {
		cout << "banana" << endl;
	}
	
	
	
	return 0;
}
