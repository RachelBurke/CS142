#include <iostream>
#include <fstream>
using namespace std;

// This program is written by Ankur Gupta.
// This program is a template for the Connect Four game.
// Compile and run this program so that you can see what
// will be printed out.

// This function draws the board.
void drawboard(ostream &, char [][7], int, int);
void drawcolorboard(ostream &, char [][7], int, int);

int main () {

	ofstream outfile;
	outfile.open("gamelog01.txt");
	
	char board [6][7] = {0};
	
	// Uncomment these lines to try out the
	// code for the first time.
	// Remove lines 19-25 (this block of code)
	// when you finally write your program.
	//for (int x = 0; x < 6; x++)
	//	for (int y = 0; y < 7; y++)
	//		board[x][y] = 'X';
	board[0][0] = 'O';
	board[2][4] = 'X';
	
	// WRITE YOUR MENU PART HERE!!!
	
	
	// This is a sample use of the drawboard function.
	// It prints out the board to the screen.
   // The second drawboard command prints the game board
   // to the output file called gamelog01.txt
	drawcolorboard(cout, board, 6, 7);
	drawboard(outfile, board, 6, 7);

	outfile.close();
	return 0;
} // end main

// Ankur Gupta

// This function prints the board to the indicated ostream object.
// This function is intended to print to a file or it prints without color.
// The values in the board are 'X' for player 1, 'O' (the letter) for
// player 2, and the ASCII value of 0 (zero) for an empty space.
void drawboard(ostream & out, char b[][7], int r, int c) {
	out << endl;
	for (int x = r-1; x >= 0; x--) {
		out << "|";
		for (int y = 0; y < c-1; y++)
			out << "----";
		out << "---|" << endl << "|";
		for (int y = 0; y < c-1; y++)
			if (b[x][y] == 0)
				out << "   |";
			else
				out << " " << b[x][y] << " |";
		if (b[x][c-1] == 0)
			out << "   | " << x << endl;
		else
			out << " " << b[x][c-1] << " | " << x << endl;
	}
	
	out << "|";
	for (int y = 0; y < c-1; y++)
		out << "----";
	out << "---|" << endl;
	
	out << " ";
	for (int y = 0; y < c; y++)
		out << " " << y << "  ";
	out << endl << endl;

} // end drawboard function

// This function prints the board to the indicated ostream object.
// This function is intended to look pretty on a terminal with colors.
// The values in the board are 'X' for player 1, 'O' (the letter) for
// player 2, and the ASCII value of 0 (zero) for an empty space.
void drawcolorboard(ostream & out, char b[][7], int r, int c) {
	// Use this to bold the whole board
	out << "\033[1;37m"; 
	out << endl;
	for (int x = r-1; x >= 0; x--) {
		out << "|";
		for (int y = 0; y < c-1; y++)
			out << "----";
		out << "---|" << endl << "|";
		for (int y = 0; y < c-1; y++)
			if (b[x][y] == 0)
				out << "   |";
			else if (b[x][y] == 'X')
				out << " \033[1;31m" << b[x][y] << "\033[1;37m |";
			else
				out << " \033[1;34m" << b[x][y] << "\033[1;37m |";				
		if (b[x][c-1] == 0)
			out << "   | " << x << endl;
		else if (b[x][c-1] == 'X')
			out << " \033[1;31m" << b[x][c-1] << "\033[1;37m |" << x << endl;
		else
			out << " \033[1;34m" << b[x][c-1] << "\033[1;37m |" << x << endl;
	}
	
	out << "|";
	for (int y = 0; y < c-1; y++)
		out << "----";
	out << "---|" << endl;
	
	out << " ";
	for (int y = 0; y < c; y++)
		out << " " << y << "  ";
	// Use this to bold the whole board
	out << "\033[0m";
	out << endl << endl;

} // end drawboard function
