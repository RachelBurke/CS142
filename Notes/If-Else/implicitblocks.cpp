#include <iostream>
using namespace std;

int main () {
	// Implicit blocks are blocks that are included 
	//in if/while/for statements (things with braces)
	//that do not actually have braces. Implicit before
	// can only ever enclose a single statement.
	
	int x = 3;
	
	if (x==1)
		cout << "Simple" << endl;
	
	if (x==2)
		cout << "s1" << endl;
		cout << "s2" << endl; //only thing printed
		
	return 0;
}
