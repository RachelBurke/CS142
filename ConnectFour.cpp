#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// This function draws the board.
void drawboard (ostream &, char [][7], int, int);
// This function draws the board in color.
void drawcolorboard (ostream &, char [][7], int, int);
// This function makes the human moves.
int humanmove (int, char [][7], int);
// This function checks for vertical wins.
int verticalwin (char [][7], int, int, int);
// This function checks for horizontal wins.
int horizontalwin (char [][7], int, int, int);
// This function checks for right diagonal wins.
int rdiagonalwin (char [][7], int, int, int);
// This function checks for left diagonal wins.
int ldiagonalwin (char [][7], int, int, int);
// This function calls the computer function.
int compmove (int, char [][7], int, char);
// This function is for a game played completely by computers.
int compgame (int, char [][7], int);

int main () {
	srand (time(0));
	ofstream outfile;
	outfile.open("gamelog01.txt");
	
	char board [6][7] = {0};
	
	int players;
	int rows;
	int columns;
	int w = 0;
	
	drawboard (cout, board, 6, 7);
	
	cout << "How many human players are playing connect four?" << endl;
	cin >> players;
	if (players > 2) {
		cout  << "That is too many players. How many human players are playing the game?" << endl;
		cin >> players;
	}
	while (players == 2) {
		w = humanmove(players, board, 6);
		if (w == 1) 
			break;
		if (w == 0)
			break;
	}
	while (players == 1){
		w = humanmove (players, board, 6);
		if (w == 1) 
			break;
		if (w == 0)
			break;
	}
	while (players == 0) {
		int players = 2;
		w = compgame (players, board, 6);
		if (w == 1) 
			break;
		if (w == 0)
			break;
	}
	
	outfile.close();
	return 0;
}

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

}

void drawcolorboard(ostream & out, char b[][7], int r, int c) {
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
	out << "\033[0m";
	out << endl << endl;

}

int humanmove(int players, char board[][7], int rows){
	
	ofstream outfile;
	outfile.open("gamelog01.txt");
	
	while (players ==2) {
		int player1 = 1;
		int player2 = 2;
		int column;
		int row;
		char token;
		int vw = 0;
		int hw = 0;
		int rdw = 0;
		int ldw = 0;
		
		while (player1 = 1) {
			token = 'X';
			cout << "What column would Player 1 like to play in?" << endl;
			cin >> column;
			if (column == -1) {
				cout << "Game end." << endl;
				return 0;
			}
			
			while ((column < 0) || (column >= 7)) {
				cout << "Invalid column number. There are not that many columns.  Please enter a different column number." << endl;
				cin >> column;
			}
			
			if (row == 5 && (token == 'X' || token == 'O')) {
				cout << "This column is full." << endl;
				continue;
			}
			
			else {
				for (row = 5; row >= 0; row--) {
					if (board [row][column] != 0) {
						break;
					}
				}
				outfile << "Player 2 plays in column " << column << endl; 
				board [row+1][column] = token;
				drawcolorboard(cout, board, 6, 7);
				drawboard(outfile, board, 6, 7);
				int moverow = row+1;
				int movecolumn = 0;
				vw = verticalwin (board, 6, moverow, movecolumn);
				hw = horizontalwin (board, 6, moverow, movecolumn);
				rdw = rdiagonalwin (board, 6, moverow, movecolumn);
				ldw = ldiagonalwin (board, 6, moverow, movecolumn);
				if ((vw == 1) || (hw == 1) || (rdw == 1) || (ldw == 1))				
					return 1;
				break;
			}
		}			
		
		while (player2 = 2) {
			token = 'O';
			cout << "What column would Player 2 like to play in?" << endl;
			cin >> column;
			if (column == -1) {
				cout << "Game end." << endl;
				return 0;
			}
			
			while ((column < 0) || (column >= 7)) {
				cout << "Invalid column number. There are not that many columns.  Please enter a different column number." << endl;
				cin >> column;
			}
						
			if (board [5][column] != 0) {
				cout << "This column is full." << endl;
				continue;
			}
			
			else {
				for (row = 5; row >= 0; row--) {
					if (board [row][column] != 0) {
						break;
					}
				}
				outfile << "Player 2 plays in column " << column << endl; 
				board [row+1][column] = token;
				drawcolorboard(cout, board, 6, 7);
				drawboard(outfile, board, 6, 7);
				int moverow = row+1;
				int movecolumn = 0;
				vw = verticalwin (board, 6, moverow, movecolumn);
				hw = horizontalwin (board, 6, moverow, movecolumn);
				rdw = rdiagonalwin (board, 6, moverow, movecolumn);
				ldw = ldiagonalwin (board, 6, moverow, movecolumn);
				if ((vw == 1) || (hw == 1) || (rdw == 1) || (ldw == 1))				
					return 1;
				
				break;
			}
		}	
	}
	
	while (players == 1) {
		char computer = 'c';
		char human = 'h';
		char player1;
		char player2;

		cout << "Who is playing first?  Enter c for computer or h for human." << endl;
			cin >> player1;
		
		if (player1 == 'h')
			player2 = 'c';
			
		if (player1 == 'c')
			player2 = 'h';
		
		while (player1 == 'h' && player2 == 'c'){
			while (player1 == 'h') {
				int column;
				int row;
				char token;
				int vw = 0;
				int hw = 0;
				int rdw = 0;
				int ldw = 0;
				token = 'X';
			
				cout << "What column would Player 1 like to play in?" << endl;
				cin >> column;
			
				if (column == -1) {
					cout << "Game end." << endl;
					return 0;
				}
				
				while ((column < 0) || (column >= 7)) {
					cout << "Invalid column number. There are not that many columns.  Please enter a different column number." << endl;
					cin >> column;
				}
						
				for (row = 5; row >= 0; row--) {
					if (board [row][column] != 0) {
						break;
					}
				}
			
				if (row == 5 && (token == 'X' || token == 'O')) {
					cout << "This column is full." << endl;
					continue;
				}
			
				else	{
					outfile << "Player 1 plays in column " << column << endl;
					board [row+1][column] = token;
					drawcolorboard(cout, board, 6, 7);
					drawboard(outfile, board, 6, 7);
					int moverow = row+1;
					int movecolumn = 0;
					vw = verticalwin (board, 6, moverow, movecolumn);
					hw = horizontalwin (board, 6, moverow, movecolumn);
					rdw = rdiagonalwin (board, 6, moverow, movecolumn);
					ldw = ldiagonalwin (board, 6, moverow, movecolumn);
					if ((vw == 1) || (hw == 1) || (rdw == 1) || (ldw == 1))				
						return 1;
					break;
				}
			}
			
			while (player2 == 'c') {
				char token = 'O';
				int column;
				int row;
				int vw = 0;
				int hw = 0;
				int rdw = 0;
				int ldw = 0;
			
				column = compmove(players, board, 6, token);
						
				if (board [5][column] != 0)
					continue;
			
				else {
					for (row = 5; row >= 0; row--) {
						if (board [row][column] != 0)
							break;
					
					}
					outfile << "Computer 1 plays in column " << column << endl; 
					board [row+1][column] = token;
					cout << "Computer 1 plays in column " << column << endl;
					drawcolorboard(cout, board, 6, 7);
					drawboard(outfile, board, 6, 7);
					int moverow = row+1;
					int movecolumn = 0;
					vw = verticalwin (board, 6, moverow, movecolumn);
					hw = horizontalwin (board, 6, moverow, movecolumn);
					rdw = rdiagonalwin (board, 6, moverow, movecolumn);
					ldw = ldiagonalwin (board, 6, moverow, movecolumn);
					if ((vw == 1) || (hw == 1) || (rdw == 1) || (ldw == 1))				
						return 1;
					break;
				}	
			}
		}	
	
		while (player1 == 'c' && player2 == 'h'){
			while (player1 == 'c') {
				char token = 'X';
				int column;
				int row;
				int vw = 0;
				int hw = 0;
				int rdw = 0;
				int ldw = 0;
			
				column = compmove(players, board, 6, token);
						
				if (board [5][column] != 0)
					continue;
			
				else {
					for (row = 5; row >= 0; row--) {
						if (board [row][column] != 0)
							break;
					
					}
					outfile << "Computer 1 plays in column " << column << endl; 
					board [row+1][column] = token;
					cout << "Computer 1 plays in column " << column << endl;
					drawcolorboard(cout, board, 6, 7);
					drawboard(outfile, board, 6, 7);
					int moverow = row+1;
					int movecolumn = 0;
					vw = verticalwin (board, 6, moverow, movecolumn);
					hw = horizontalwin (board, 6, moverow, movecolumn);
					rdw = rdiagonalwin (board, 6, moverow, movecolumn);
					ldw = ldiagonalwin (board, 6, moverow, movecolumn);
					if ((vw == 1) || (hw == 1) || (rdw == 1) || (ldw == 1))				
						return 1;
					break;
				}	
			}
		
			while (player2 == 'h') {
				int column;
				int row;
				char token;
				int vw = 0;
				int hw = 0;
				int rdw = 0;
				int ldw = 0;
				token = 'O';
		
				cout << "What column would Player 2 like to play in?" << endl;
				cin >> column;
			
				if (column == -1) {
					cout << "Game end." << endl;
					return 0;
				}
				
				while ((column < 0) || (column >= 7)) {
					cout << "Invalid column number. There are not that many columns.  Please enter a different column number." << endl;
					cin >> column;
				}
			
				for (row = 5; row >= 0; row--) {
					if (board [row][column] != 0) {
						break;
					}	
				} 
	
				if (row == 5 && (token == 'X' || token == 'O')) {
					cout << "This column is full." << endl;
					continue;
				}
		
				else	 {
					board [row+1][column] = token;
					outfile << "Player 2 plays in column " << column << endl;
					drawcolorboard(cout, board, 6, 7);
					drawboard(outfile, board, 6, 7);
					int moverow = row+1;
					int movecolumn = 0;
					vw = verticalwin (board, 6, moverow, movecolumn);
					hw = horizontalwin (board, 6, moverow, movecolumn);
					rdw = rdiagonalwin (board, 6, moverow, movecolumn);
					ldw = ldiagonalwin (board, 6, moverow, movecolumn);
					if ((vw == 1) || (hw == 1) || (rdw == 1) || (ldw == 1))				
						return 1;
					break;
				}
			
			}
		}
	}
}

int verticalwin (char board [][7], int rows, int moverow, int movecolumn) {
	int w = 0;
	for (int x = 0; x < 7; x++) {
		for (int y = 0; y < 3; y++) {
			if (board [y][x] == board [y+1][x] && board [y][x] == board [y+2][x] && board [y][x] == board [y+3][x] && board [y][x] != 0) {
				cout << "There has been a vertical win!" << endl;
				w = 1;
				return w;
			}
		}
	}
	return w;
}

int horizontalwin (char board [][7], int rows, int moverow, int movecolumn) {
	int w = 0;
	for (int x = 0; x < 6; x++) {
		for (int y = 0; y < 4; y++) {
			if (board [x][y] == board [x][y+1] && board [x][y+1] == board [x][y+2] && board [x][y+2] == board [x][y+3] && board [x][y] != 0) {
						cout << "There has been a horizontal win!" << endl;
						w = 1;
						return w;
			
			}
		}
	}
	return w;
}

int rdiagonalwin (char board [][7], int rows, int moverow, int movecolumn) {
	int w = 0;
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 7; y++) {
		if ((board [x][y] == board [x+1][y+1]) && (board [x+1][y+1] == board [x+2][y+2]) && (board [x+2][y+2] == board [x+3][y+3]) && board [x][y] != 0 && board [x+3][y+3] != 0) {
				if (x >=0 && y >= 0 && (x+3) <= 5 && (y+3) <= 6) {
					cout << "There has been a right diagonal win!" << endl;
					w = 1;
					return w;
				}
			}
		}
	}
	return w;
}

int ldiagonalwin (char board [][7], int rows, int moverow, int movecolumn) {
	int w = 0;
	for (int x = 0; x < 3 ; x++) {
		for (int y = 0; y < 7; y++) {
		if (board [x+3][y] == board [x+2][y+1] && board [x+2][y+1] == board [x+1][y+2] && board [x+1][y+2] == board [x][y+3] && board [x+3][y] != 0 && board [x][y+3] != 0) {
				if (x >=0 && y >= 0 && (x+3) <= 5 && (y+3) <= 6) {
					cout << "There has been a left diagonal win!" << endl;
					w = 1;
					return w;
				}
			}
		}
	}
	return w;
}

int compmove (int cplayer, char board [][7], int rows, char token) {
	int column;
	char otoken;
	if (token == 'X')
		otoken = 'O';
	if (token == 'O')
		otoken = 'X';
	
	//CHECK FOR PERSONAL WIN IN 1 MOVE
	
	//vertical check
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 7; y++) {
			if (board [x][y] == board [x+1][y] && board [x+1][y] == board [x+2][y] && board [x][y] == token && board [x][y] != 0 && board [x+3][y] == 0) {
				column = y;
				return column;
			}
		}
	}
	
	//horizontal check
	for (int x = 0; x < 6; x++) {
		for (int y = 0; y < 4; y++) {
			if (board [x][y] == board [x][y+1] && board [x][y+1] == board [x][y+2] && board [x][y] == token  && board [x][y] != 0 && board [x][y+3] == 0) {
				if (x == 0 || (x == 1 && board [x-1][y+3] != 0) || (x == 2 && board [x-1][y+3] != 0 && board [x-2][y+3] != 0) || (x == 3 && board [x-1][y+3] != 0 && board [x-2][y+3] != 0 && board [x-3][y+3] != 0) || (x == 4 && board [x-1][y+3] != 0 && board [x-2][y+3] != 0 && board [x-3][y+3] != 0 && board [x-4][y+3] != 0) || (x == 5 && board [x-1][y+3] != 0 && board [x-2][y+3] != 0 && board [x-3][y+3] != 0 && board [x-4][y+3] != 0 && board [x-5][y+3] != 0)) {
					column = (y+3);
					return column;
				}
			}
			if (board [x][y+1] == board [x][y+2] && board [x][y+2] == board [x][y+3] && board [x][y+1] == token && board [x][y] != 0 && board [x][y] == 0) {
				if (x == 0 || (x == 1 && board [x-1][y] != 0) || (x == 2 && board [x-1][y] != 0 && board [x-2][y] != 0) || (x == 3 && board [x-1][y] != 0 && board [x-2][y] != 0 && board [x-3][y] != 0) || (x == 4 && board [x-1][y] != 0 && board [x-2][y] != 0 && board [x-3][y] != 0 && board [x-4][y] != 0) || (x == 5 && board [x-1][y] != 0 && board [x-2][y] != 0 && board [x-3][y] != 0 && board [x-4][y] != 0 && board [x-5][y] != 0)) {
					column = y;
					return column;
				}
			}
			if (board [x][y] == board [x][y+1] && board [x][y+1] == board [x][y+3] && board [x][y] == token && board [x][y] != 0 && board [x][y+2] == 0) {
				if (x == 0 || (x == 1 && board [x-1][y+2] != 0) || (x == 2 && board [x-1][y+2] != 0 && board [x-2][y+2] != 0) || (x == 3 && board [x-1][y+2] != 0 && board [x-2][y+2] != 0 && board [x-3][y+2] != 0) || (x == 4 && board [x-1][y+2] != 0 && board [x-2][y+2] != 0 && board [x-3][y+2] != 0 && board [x-4][y+2] != 0) || (x == 5 && board [x-1][y+2] != 0 && board [x-2][y+2] != 0 && board [x-3][y+2] != 0 && board [x-4][y+2] != 0 && board [x-5][y+2] != 0)) {
					column = (y+2);
					return column;
				}
			}
			if (board [x][y] == board [x][y+2] && board [x][y+2] == board [x][y+3] && board [x][y] == token  && board [x][y] != 0 && board [x][y+1] == 0) {
				if (x == 0 || (x == 1 && board [x-1][y+1] != 0) || (x == 2 && board [x-1][y+1] != 0 && board [x-2][y+1] != 0) || (x == 3 && board [x-1][y+1] != 0 && board [x-2][y+1] != 0 && board [x-3][y+1] != 0) || (x == 4 && board [x-1][y+1] != 0 && board [x-2][y+1] != 0 && board [x-3][y+1] != 0 && board [x-4][y+1] != 0) || (x == 5 && board [x-1][y+1] != 0 && board [x-2][y+1] != 0 && board [x-3][y+1] != 0 && board [x-4][y+1] != 0 && board [x-5][y+1] != 0)) {
					column = (y+1);
					return column;
				}
			}
		}
	}
	
	//rdiagonal check
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 4; y++) {
			if (board [x][y] == board [x+1][y+1] && board [x+1][y+1] == board [x+2][y+2] && board [x][y] == token && board [x+3][y+3] == 0) {
				if (board [x+2][y+3] != 0) {
					column = (y+3);
					return column;
				}
			}
			if (board [x][y] == board [x+1][y+1] && board [x+1][y+1] == board [x+3][y+3] && board [x][y] == token && board [x+2][y+2] == 0) {
				if ((board [x][y+2] != 0 && board [x+1][y+2] != 0) || (board [x+1][y+2] != 0)) {
					column = (y+2);
					return column;
				}
			}
			if (board [x+1][y+1] == board [x+2][y+2] && board [x+2][y+2] == board [x+3][y+3] && board [x+1][y+1] == token && board [x][y] == 0) {
					column = y;
					return column;
			}
			if (board [x][y] == board [x+2][y+2] && board [x+2][y+2] == board [x+3][y+3] && board [x][y] == token && board [x+1][y+1] == 0) {
				if (board [x][y+1] != 0) {
					column = (y+1);
					return column;
				}
			}
		}
	}
	
	//ldiagonal check
	for (int x = 0; x < 3 ; x++) {
		for (int y = 0; y < 4; y++) {
			if (board [x+1][y+2] == board [x+2][y+1] && board [x+2][y+1] == board [x+3][y]  && board [x+1][y+2] == token && board [x][y] != 0 && board [x][y+3] == 0) {
				column = (y+3);
				return column;
			}
			if (board [x][y+3] == board [x+1][y+2] && board [x+1][y+2] == board [x+3][y]  && board [x][y+3] == token  && board [x][y] != 0 && board [x+2][y+1] == 0) {
				if ((board [x][y+1] != 0 && board [x+1][y+1] != 0) || (board [x+1][y+1] != 0)) {
					column = (y+1);
					return column;
				}
			}
			if (board [x][y+3] == board [x+2][y+1] && board [x+2][y+1] == board [x+3][y]  && board [x][y+3] == token  && board [x][y] != 0 && board [x+1][y+2] == 0) {
				if (board [x][y+2] != 0) {
					column = (y+2);
					return column;
				}
			}
			if (board [x][y+3] == board [x+1][y+2] && board [x+1][y+2] == board [x+2][y+1]  && board [x][y+3] == token  && board [x][y] != 0 && board [x+3][y] == 0) {
				if ((board [x][y] != 0 && board [x+1][y] != 0 && board [x+2][y] != 0) || (board [x+1][y] != 0 && board [x+2][y] != 0) || (board [x+2][y] != 0)) {
					column = y;
					return column;
				}
			}
		}
	}
	
	// CHECK FOR OPPONENT WINS\
		
	//vertical check
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 7; y++) {
			if (board [x][y] == board [x+1][y] && board [x+1][y] == board [x+2][y] && board [x][y] == otoken && board [x][y] != 0 && board [x+3][y] == 0) {
				column = y;
				return column;
			}
		}
	}
	
	//horizontal check
	for (int x = 0; x < 6; x++) {
		for (int y = 0; y < 4; y++) {
			if (board [x][y] == board [x][y+1] && board [x][y+1] == board [x][y+2] && board [x][y] == otoken && board [x][y] != 0 && board [x][y+3] == 0) {
				if (x == 0 || (x == 1 && board [x-1][y+3] != 0) || (x == 2 && board [x-1][y+3] != 0 && board [x-2][y+3] != 0) || (x == 3 && board [x-1][y+3] != 0 && board [x-2][y+3] != 0 && board [x-3][y+3] != 0) || (x == 4 && board [x-1][y+3] != 0 && board [x-2][y+3] != 0 && board [x-3][y+3] != 0 && board [x-4][y+3] != 0) || (x == 5 && board [x-1][y+3] != 0 && board [x-2][y+3] != 0 && board [x-3][y+3] != 0 && board [x-4][y+3] != 0 && board [x-5][y+3] != 0)) {
					column = (y+3);
					return column;
				}
			}
			if (board [x][y+1] == board [x][y+2] && board [x][y+2] == board [x][y+3] && board [x][y+1] == otoken && board [x][y+1] != 0 && board [x][y] == 0) {
				if (x == 0 || (x == 1 && board [x-1][y] != 0) || (x == 2 && board [x-1][y] != 0 && board [x-2][y] != 0) || (x == 3 && board [x-1][y] != 0 && board [x-2][y] != 0 && board [x-3][y] != 0) || (x == 4 && board [x-1][y] != 0 && board [x-2][y] != 0 && board [x-3][y] != 0 && board [x-4][y] != 0) || (x == 5 && board [x-1][y] != 0 && board [x-2][y] != 0 && board [x-3][y] != 0 && board [x-4][y] != 0 && board [x-5][y] != 0)) {
					column = y;
					return column;
				}
			}
			if (board [x][y] == board [x][y+1] && board [x][y+1] == board [x][y+3] && board [x][y] == otoken && board [x][y] != 0 && board [x][y+2] == 0) {
				if (x == 0 || (x == 1 && board [x-1][y+2] != 0) || (x == 2 && board [x-1][y+2] != 0 && board [x-2][y+2] != 0) || (x == 3 && board [x-1][y+2] != 0 && board [x-2][y+2] != 0 && board [x-3][y+2] != 0) || (x == 4 && board [x-1][y+2] != 0 && board [x-2][y+2] != 0 && board [x-3][y+2] != 0 && board [x-4][y+2] != 0) || (x == 5 && board [x-1][y+2] != 0 && board [x-2][y+2] != 0 && board [x-3][y+2] != 0 && board [x-4][y+2] != 0 && board [x-5][y+2] != 0)) {
					column = (y+2);
					return column;
				}
			}
			if (board [x][y] == board [x][y+2] && board [x][y+2] == board [x][y+3] && board [x][y] == otoken && board [x][y] != 0 && board [x][y+1] == 0) {
				if (x == 0 || (x == 1 && board [x-1][y+1] != 0) || (x == 2 && board [x-1][y+1] != 0 && board [x-2][y+1] != 0) || (x == 3 && board [x-1][y+1] != 0 && board [x-2][y+1] != 0 && board [x-3][y+1] != 0) || (x == 4 && board [x-1][y+1] != 0 && board [x-2][y+1] != 0 && board [x-3][y+1] != 0 && board [x-4][y+1] != 0) || (x == 5 && board [x-1][y+1] != 0 && board [x-2][y+1] != 0 && board [x-3][y+1] != 0 && board [x-4][y+1] != 0 && board [x-5][y+1] != 0)) {
					column = (y+1);
					return column;
				}
			}
		}
	}
	
	//rdiagonal check
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 4; y++) {
			if (board [x][y] == board [x+1][y+1] && board [x+1][y+1] == board [x+2][y+2] && board [x][y] == otoken && board [x+3][y+3] == 0) {
				if (board [x+2][y+3] != 0) {
					column = (y+3);
					return column;
				}
			}
			if (board [x][y] == board [x+1][y+1] && board [x+1][y+1] == board [x+3][y+3] && board [x][y] == otoken && board [x+2][y+2] == 0) {
				if (board [x+1][y+2] != 0) {
					column = (y+2);
					return column;
				}
			}
			if (board [x+1][y+1] == board [x+2][y+2] && board [x+2][y+2] == board [x+3][y+3] && board [x+1][y+1] == otoken && board [x][y] == 0) {
				column = y;
				return column;
			}
			if (board [x][y] == board [x+2][y+2] && board [x+2][y+2] == board [x+3][y+3] && board [x][y] == otoken && board [x+1][y+1] == 0) {
				if (board [x][y+1] != 0) {
					column = (y+1);
					return column;
				}
			}
		}
	}
	
	//ldiagonal check
	for (int x = 0; x < 3 ; x++) {
		for (int y = 0; y < 4; y++) {
			if (board [x+1][y+2] == board [x+2][y+1] && board [x+2][y+1] == board [x+3][y]  && board [x+1][y+2] == otoken && board [x+1][y+2] != 0 && board [x][y+3] == 0 && x >=0 && y >= 0 && ((x+3) <= 5) && ((y+3) <= 6)) {
				column = (y+3);
				return column;
			}
			if (board [x][y+3] == board [x+1][y+2] && board [x+1][y+2] == board [x+3][y] && board [x][y+3] == otoken && board [x][y+3] != 0 && board [x+2][y+1] == 0 && x >=0 && y >= 0 && ((x+3) <= 5) && ((y+3) <= 6)) {
				if (board [x+1][y+1] != 0) {
					column = (y+1);
					return column;
				}
			}
			if (board [x][y+3] == board [x+2][y+1] && board [x+2][y+1] == board [x+3][y] && board [x][y+3] == otoken && board [x][y+3] != 0 && board [x+1][y+2] == 0 && x >=0 && y >= 0 && ((x+3) <= 5) && ((y+3) <= 6)) {
				if (board [x][y+2] != 0) {
					column = (y+2);
					return column;
				}
			}
			if (board [x][y+3] == board [x+1][y+2] && board [x+1][y+2] == board [x+2][y+1] && board [x][y+3] == otoken && board [x][y+3] != 0 && board [x+3][y] == 0 && x >=0 && y >= 0 && ((x+3) <= 5) && ((y+3) <= 6)) {
				if (board [x+2][y] != 0) {
					column = y;
					return column;
				}
			}
		}
	}
	column = 0 + rand () % (6-0+1);
	while (board [5][column] != 0) {
		column = 0 + rand () % (6-0+1); 
	}
	return column;
}

int compgame(int players, char board [][7], int rows) {
	
	ofstream outfile;
	outfile.open("gamelog01.txt");
	
	while (players ==2) {
		int player1 = 1;
		int player2 = 2;
		int column;
		int row;
		char token;
		int vw = 0;
		int hw = 0;
		int rdw = 0;
		int ldw = 0;
		
		while (player1 = 1) {
			token = 'X';
			
			column = compmove(players, board, 6, token);
						
			if (board [5][column] != 0)
				continue;
			
			else {
				for (row = 5; row >= 0; row--) {
					if (board [row][column] != 0)
						break;
					
				}
				outfile << "Computer 1 plays in column " << column << endl; 
				board [row+1][column] = token;
				cout << "Computer 1 plays in column " << column << endl;
				drawcolorboard(cout, board, 6, 7);
				drawboard(outfile, board, 6, 7);
				int moverow = row+1;
				int movecolumn = 0;
				vw = verticalwin (board, 6, moverow, movecolumn);
				hw = horizontalwin (board, 6, moverow, movecolumn);
				rdw = rdiagonalwin (board, 6, moverow, movecolumn);
				ldw = ldiagonalwin (board, 6, moverow, movecolumn);
				if ((vw == 1) || (hw == 1) || (rdw == 1) || (ldw == 1))				
					return 1;
				break;
			}
		}	
		
		while (player2 = 2) {
			token = 'O';
			
			column = compmove(players, board, 6, token);
						
			if (board [5][column] != 0)
				continue;
			
			else {
				for (row = 5; row >= 0; row--) {
					if (board [row][column] != 0)
					break;
				}
				outfile << "Computer 2 plays in column " << column << endl; 
				board [row+1][column] = token;
				cout << "Computer 2 plays in column " << column << endl;
				drawcolorboard(cout, board, 6, 7);
				drawboard(outfile, board, 6, 7);
				int moverow = row+1;
				int movecolumn = 0;
				vw = verticalwin (board, 6, moverow, movecolumn);
				hw = horizontalwin (board, 6, moverow, movecolumn);
				rdw = rdiagonalwin (board, 6, moverow, movecolumn);
				ldw = ldiagonalwin (board, 6, moverow, movecolumn);
				if ((vw == 1) || (hw == 1) || (rdw == 1) || (ldw == 1))				
					return 1;
				break;
			}
		}	
	}
}
