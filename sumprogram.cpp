#include <iostream>
using namespace std;

int main () {
	
	int num = 1;
	int runsum = 0;
	
	while (num <= 10) {
		runsum  = runsum + num;
		num += 1;
		cout << runsum << endl;
	}
	
	
	return 0;
}