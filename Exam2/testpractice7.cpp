#include <iostream>
using namespace std;

void foobar (int [], int);
int toodimforwords(int [][5], int);

int main () {

	int a[5] = {2, 7, 13, 25, 39};
	int b[5] = {14, 15, 16, 29, 42};
	int c[10];
	int d [6][5] = {0};

	for (int x = 0; x < 5; x++)
		cout << a[x] << " ";
	cout << endl;
	
	for (int x = 0; x < 6; x++) {
		for (int y = 0; y < 5; y++)
			cout << d[x][y] << " ";
		cout << endl;
	}
	
	foobar(a, 5);
	toodimforwords(d, 6);
	
	for (int x = 0; x < 5; x++)
		cout << a[x] << " ";
	cout << endl;

	for (int x = 0; x < 6; x++) {
		for (int y = 0; y < 5; y++)
			cout << d[x][y] << " ";
		cout << endl;
	}
	
	return 0;
}

void foobar(int b[], int size) {
	
	b[3] = 7;
	b[4] = b[2] * 3;
	
	for (int x = 0; x < size; x++)
		b[x]++;

	return;
}

int toodimforwords (int c[][5], int rows) {
	
	for (int x = 0; x < rows; x++)
		for (int y = 0; y < 5; y++)
			c[x][y]++;

	return 45;
}
