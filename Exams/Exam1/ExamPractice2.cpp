#include <iostream.h>

int main () {

	int x = 1;
	int y = 100;
	int a = 5;

	while (y - x > 0) {
		int a = (y-x++)/2;
		cout << a << " ";
		y = a;
	}
	cout << endl;

	return 0;
}
