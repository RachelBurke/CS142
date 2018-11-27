#include <iostream>
using namespace std;
//arrays create many variables at the same time
int main () {

	/*int sat1;
	int sat2;
	int sat3;
	int sat4;
	int sat5;
	int sat6;
	
	cin >> sat1;
	cin >> sat2;
	cin >> sat3;
	cin >> sat4;
	cin >> sat5;
	cin >> sat6;
	
	int sum = sat1 + sat2 + sat3 + sat4 + sat6;
	cout << sum/5.0 << endl; */
	
	int x = 9;
	int a[100]; //initializes an array of size 100
	a[4] = 9;
	a[5] = x + 3;
	x = a[4] + a[5];
	cout << a[4] + x << endl;
	
	int y = 0;
	int b[10] = {4,3,2,1,1,6,8,-3}; //initializing the array explicitly
	// same as ...
	//b[0] = 4;
	//b[1] = 3;
	//b[2] = 2;
	//b[3] = 1;
	//...
	//b might have "holes" if we don't specify enough
	//values in the explicit initialization
	
	//Special shortcut to set all the entries in an array to zero
	//This does not work for any other number than zero
	int c[100] = {0};
	
		x = 5;
		a[4] = x + 7;
		a[6-4] = x +7;
		a[x + 32%2 + 17/3 +90] = 9;
		
		//SAT for the win
		int sat[4000];
		for (int x = 0; x < 4000; x++) {
			cin >> sat[x];
		}
		
	
		double average = 0;
		for (int x = 0; x < 4000; x++) {
			average += sat[x];
		}
		
		average /= 4000.0;
		cout << average << endl;
		
	return 0;
} 