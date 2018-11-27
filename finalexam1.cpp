#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int f1(int [], int);

int main () {

	int a[10] = {0};
	for (int x = 0; x < 10; x++)
		a[x] = 0 + rand() % 9;

	for (int x = 0; x < 10; x++)
		cout << a[x] << " ";

	cout << endl; 

	f1(a, 10);

	for (int x = 0; x < 10; x++)
		cout << a[x] << " ";

	cout << endl;

	return 0;
}

int f1(int a[], int p) {
	for (int x = 0; x < p; x++)
		a[x] = (a[a[x]] + 2*a[x]) % 9;
	return 1;
}

