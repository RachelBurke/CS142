#include <iostream> //header files
#include <math.h> // ""
using namespace std;

//function declaration
int factorial(int);

int main () {
	
	int n;
	cin >> n;
	
	//function call
	cout << factorial(n) << endl;
	
	
	return 0;
}
	//function definition
	int factorial(int y) {
		int fac = 1;
		for (int x = 1; x <= y; x++) {
			fac = fac * x;
			
		}
		return fac;	
	}