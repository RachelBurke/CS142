#include <iostream>
using namespace std;

int main () {
	
	cout << "Tay Sway!" << " Nuggets!" << endl;

	cout <<" Cool points are cool!!!"
		 <<" bananas"
		 <<" I want food."
		 <<endl;
	 
	 // The next thing is a variable declaration.
	 int a;
	 
	 // Use variables.
	 a = 8;
	 cout << a << endl;
	 a = 12;
	 cout << a << endl;
	 cout << "a" << endl;
	 
	 // Multiple Variables
	 int b, c;
	 b = 6;
	 
	 // #math
	 c = b + 5;
	 c = a + b + 22;
	 cout << c << endl;
	 
	 // Other Basic Math Operations
	 c = a - b + 4;
	 c = a * b; 
	 c = a/b;
	 c = 4;
	 b = a + c * 2;
	 b = (a + c) * 2;
	 
	 // Exciting Question
	 int q = 5; 
	 q = q + 4;
	 q = q - 4;
	 q = q * 4;
	 q = q / 5;
	 cout << q << endl;
	 
	 q += 4; // identical to line 42
	 q -= 4; // identical to line 43
	 q *= 5; // identical to line 44
	 q /= 5; // identical to line 45
	 
	 // User input
	 int age;
	 cout << "Type in your age ";
	 cin >> age;
	 int dateable = age/2 + 7;
	 cout << "You can't tap that unless they're at least " << dateable << endl;
	 
	 
	 
	return 0;
}