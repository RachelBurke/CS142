#include <iostream.h>

int main () {

	int a=1,b=1,c=8,d=2;

	cout << a << " " << b << " ";
	int x = 1;
	while (x <= c) {
		d = a;
		a = b + d;
		b = d;
		cout << a << " ";
		x++;
	}
	cout << endl;

	return 0;
}
