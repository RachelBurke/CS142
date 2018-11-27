#include <iostream>
using namespace std;

int main () {

	int x = 12;
	int y = 25;
	{x += y - 6;}
	{
		int y = 65;
		--y;
		int z = 43+x++-y; //do variables first, any ++ or -- does change the variable value for the entire problem!
		{
			{y += x;
				cout << y << endl;
			}
		{int p = z;}
			int x = 12;
			cout << x - 65 << endl;
		}
		int x = 54-y++;
		x=45+z-12;
		cout << z << endl;
	}
	x = 54-y++;

	cout << x << " " << y << endl;

	return 0;
}
