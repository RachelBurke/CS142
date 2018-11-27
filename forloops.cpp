#include <iostream>
using namespace std;

int main () {
	
	double yearly_salary;
	int years;
	double total_salary = 0;
	
	cout << "Type in your yearly salary: ";
	cin >> yearly_salary;
	cout << "Type in the number of years you worked: ";
	cin >> years;
	
	/*cout << "Years    Cur. Salary     Cum. Salary" << endl; 
	int y = 1;
	while (y <= years) { 
		total_salary += yearly_salary;
		cout << y << "            " << yearly_salary << "    " << total_salary << endl;
		y++;
	} */
	
	// for loop
	
	total_salary = 0;  //only done to reset the variable for the example
	cout << endl;
	cout << "Years    Cur. Salary     Cum. Salary" << endl; // for loops have the start, end, and next info in it
	for (int y = 1; y <= years; y++) { 
		if (y== 4) {
			continue; //skips the current iteration of the loop
		}
		if (y == 8) {
			break; // stops loop immediately and moves on to what comes next after the loop 
		}
		total_salary += yearly_salary;
		cout << y << "         " << yearly_salary << "                      " << total_salary << endl; 
		//You Raise Me Up
		yearly_salary *= .9;
	}
	
	
	
	
	
	return 0;
}