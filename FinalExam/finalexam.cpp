#include <iostream>
using namespace std;

int main () {

	int a[5] = {2, 7, 13, 25, 39};
	int b[5] = {14, 15, 16, 29, 42};
	int c[10];

	int i = 0, j = 0;
	for (int x = 0; x < 10; x++)
		if (a[i] < b[j])
			c[x] = a[i++];
		else {
			c[x] = b[j++];
		}
	if (a[4] > b[4])
		c[9] = a[4];
	else 
		c[9] = b[4];

	for (int x = 0; x < 10; x++) {
		cout << c[x] << " ";
	}
	 cout << endl;

	return 0;
}
