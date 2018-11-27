#include <iostream>

using namespace std;

int main()
{

double number;
int remainder, times, i, v, x, l, c, d, m;
char yes ='y';

while (yes == 'y') {
	cout << "Enter a number: ";
	cin >> remainder;
	number = remainder;

	if (remainder >= 1000) {  
		m = remainder / 1000;
		times = 0;
		{for (times; times < m; times++)
		cout << "M";}
		remainder = remainder % 1000;
	}

	if (remainder >= 900){
		cout << "CM";
		remainder = remainder % 900;
	}
	
	else if (remainder >= 500) {
			d = remainder / 500;
			times = 0;
			{for (times; times < d; times++)
			cout << "D";}
		remainder = remainder % 500;
    }
       
	if (remainder >= 400) {
		cout << "CD";
		remainder = remainder % 400;
	}    
	
    else if (remainder >= 100) {
            c = remainder / 100;
            times = 0;
            {for (times; times < c; times++)
            cout << "C";}
		remainder = remainder % 100;
	}

	if (remainder >= 90) {
		cout << "XC";
		remainder = remainder % 90;
	}

	else if (remainder >= 50) {
            l = remainder / 50;
			times = 0;
            {for (times; times < l; times++)
            cout << "L";}
		remainder = remainder % 50;
	}
	
	if (remainder >= 40) {
		cout << "XL";
		remainder = remainder % 40;
	}
       
	else if (remainder >= 10) {
            x = remainder / 10;
            times = 0;
            {for (times; times < x; times++)
            cout << "X";}
		remainder = remainder % 10;
	}

	if (remainder >= 9) {
		cout << "IX";
		remainder = remainder % 9;
	}

	else if (remainder >= 5) {
            v = remainder / 5;
            times = 0;
            {for (times; times < v; times++)
            cout << "V";}
		remainder = remainder % 5;
	}
	
	if (remainder >= 4) {
		cout << "IV";
		remainder = remainder % 4;
	}
	
	else if (remainder >= 1) {
           i = remainder;
           times = 0;
           for (times; times < i; times++)
           cout << "I";
	}
		cout << endl;
	    cout << "Would you like to run this program again? (y/n): ";
	    cin >> yes;
        cout << endl; 
}

return 0;
}
