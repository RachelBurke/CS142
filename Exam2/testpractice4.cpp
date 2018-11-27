#include <iostream>
using namespace std;
// This tests your knowledge of loops, nested loops, and scope

int main () {

	int x = 3, y = 4, z = 3;
	
	while (z < x + y) {
		cout << x + y << endl;
		for (int x = 1; x < 4; x++)
			y -= 1;
	}


	return 0;
}
