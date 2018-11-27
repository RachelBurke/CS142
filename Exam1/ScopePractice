#include <iostream>
using namespace std;

int main () {
	
	int g = 43;
	int gg = 4;
	
	{
		g = 41;
		int g = 12;
		{int g = 1; g += g;}
		int gg = 2*g;
		cout << g << " " << gg << endl;
		{
			int gg = g + g;
			cout << gg << endl;
			{
				char gg = 'g';
				{
					char g = gg;
				}
				cout << g << endl;
			}
			int g = 54;
			while (g < 70) {
				g += 10;
				cout << gg << endl;
			}
			cout << gg << endl;
		}
		g = 23;
		cout << gg << endl;
		gg++;
	}
	
	cout << g << " " << gg << endl;
	
	return 0;
}
