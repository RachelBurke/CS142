#include <iostream> //header files
#include <math.h> // ""
using namespace std;

//function declaration
int rectangle_perimeter(int, int);

int main () {
	
	int height = 7;
	int width = 22;
	
	int perm;
	//function call
	perm = rectangle_perimeter (height, width);
	cout << perm << endl;
	
	return 0;
}

// function declaration
int rectangle_perimeter (int h, int w) {
	int p = 2*h + 2*w;
	return p;
}



