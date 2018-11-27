#include <iostream>
using namespace std;

int main () {

	int x = 32;
	{
		int x = 55;
	{
		int x = 27;
		x = 14;
		{cout << x << endl;}
	}
	cout << x << endl;
	{x=22;}
	cout << x << endl;
	}
	
	x = 50;
	cout << x << endl;
	
	return 0;
}
