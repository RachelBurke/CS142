#include <iostream>
using namespace std;

int a(int, int);
int b(int, int);
int c (int &, int);

int main () {

	int s = 2, r = 4;
	cout << a(s, b(r, c(s,r+s))) << endl;
	cout << s << endl;
	cout << r << endl;

	return 0;
}

int a(int d, int h) {
	d = h + h;
	return b(h,d) + c(h, d+h);
}

int b (int t, int y) {
	y++;
	return t - y;
}

int c (int & w, int q) {
	w++;
	return w + q;
}
