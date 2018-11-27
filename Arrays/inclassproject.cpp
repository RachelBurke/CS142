#include <iostream>
using namespace std;

int main () {
	/*
	1) Write a program that creates an array a of length 10 and initializes it explicitly.
		Choose any numbers you want, but make sure they're not in order.
	2) Ask the user to type in 10 numbers and fill in a new array b with those numbers.
	3) Scan (or search) through the array and see if the number 11 is there.
		Print it out if it's there, but if it appears more than once, only print it out once!
	4) Let the user type in what they want to search for, and search for that.
	5) Create an array c explicitly.
	6) Compare each corresponding entry of a to c and scream out an appropriately deathly
		fake word if the numbers are the same.
	7) Count how many times a number typed by the user appears in array a.
	8) Create an array that has the first 25 Fibonacci numbers.
	9) Suppose you have an array of 100 numbers that are in no particular order. Put them in
		sorted order.
*/	
	// 1)
	int a [10] = {2, 4, 6, 8, 10, 1, 5, 3, 7, 9};
	 //2)
	int b [10];
	for (int x = 0; x < 10; x++) {
		cin >> b[x];
	} 
	// 3)
	for (int x = 0; x < 10; x++) {
		if (b[x] == 11) { // -or- if (a[x] == 11) {
			cout << b[x] << endl;  // -or- cout << "11 bro" << endl;
			break;
		}
	}
	// 4)
	int search;
	cin >> search;
	for (int x = 0; x < 10; x++) {
		if (b[x] == search) {
			cout << "found it "<< b[x] << endl;
			break;
		}
	}
	// 5)
	int c[10] = {2, 9, 4, 7, 6, 5, 8, 3, 10, 1};
	
	// 6)
	for (int x = 0; x < 10; x++) {
		if (a[x] == c[x]) {
			cout << a[x] << " is " << c[x] <<" death cock.";
			cout << endl;
		}
	}
	
	// 7)
	int input;
	cin >> input;
	int count;
	for (int x = 0; x < 10; x++) {
		if (c[x] == input) {
			count++;
		}
	}
	cout << input << "appears " << count << " times." << endl;
	
	// 8) Fibonacci Numbers -> 1,1,2,3,5,8,13,21,34,55,89,144... 
	int fib[25] = {1, 1};
	for (int x = 2; x < 25; x++) {
		fib[x] = fib[x-2] + fib[x-1];
	}
	
	// 9) **********SORTING 101***********
	int d[10] = {2, 6, 7, 4, 1, 87, 3, -3, 69, 12};
	// x = minimum variable in comparison
	// y = variable being compared to
	for (int x = 0; x < 10; x++) {
		cout << d[x];
		cout << endl;
	}
	for (int x = 0; x < 9; x++){
		for (int y = x+1; y < 10; y++) {
			if (d[x] > d[y]) {
				//swap the variables correctly
				int temp = d[x];
				d[x] = d[y];
				d[y] = temp;
			}
		}
	}
	for (int x = 0; x < 10; x++) {
		cout << d[x] << "";
		cout << endl;
	}
	return 0;
}
