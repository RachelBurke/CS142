//This was an exam question. The program needed to print out oolongtea every 5th number or
// 1
// 2 
// 3
// 4
// 5 oolongtea
// 6
// 7
// ...
// 10 oolongtea
// ...

#include <iostream>
using namespace std;

int main () {
	
	int n = 1;
	
	for (n; n <= 100; n++) {
		if (n%5 = 0) {
			cout << n << " oolongtea ";
		}
		
		cout << n << " ";
	}
	
	return 0;
}
