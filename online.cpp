#include <iostream>
#include <fstream>

using namespace std;

void drawboard(ostream &, char [][7], int, int);
int humanmove(int player, char board [][7], int rows, int columns);
int verticalwin(char board[][7], int rows, int columns, int moverow, int movecolumn);

int main () {

  ofstream outfile;
  outfile.open("gamelog01.txt");
	
  char board[6][7] = {0};
	
  //board[0][0] = 'O';
  //board[2][4] = 'X';
	
  // WRITE YOUR MENU PART HERE!!!
  
  int player;
  int row;
  int col;
  int times;
  bool win; 	
  int moverow;
  int movecolumn;
  
  //cout << "How many players (up to 2): " ;
  //cin >> players;
  
  drawboard(cout, board,6,7);
  
 while (player = 1){
  humanmove(player, board, 6, 7);
  verticalwin(board, 6, 7, moverow, movecolumn);
  
  
  player = 2;
  humanmove(player, board, 6, 7);
  verticalwin(board, 6, 7, moverow, movecolumn);
}
    //}
	//while (times <= 42) {
  // This is a sample use of the drawboard function.
  // It prints out the board to the screen.
  // The second drawboard command prints the game board
  // to the output file called gamelog01.txt
  //drawboard(cout, board,6,7);
  //drawboard(outfile, board,6,7);

  outfile.close();
  return 0;
} // end main

// This function prints the board to the indicated ostream object.
// The values in the board are 'X' for player 1, 'O' (the letter) for
// player 2, and the ASCII value of 0 (zero) for an empty space.
void drawboard(ostream & out, char b[][7], int r, int c) {
  out << endl;
  for (int x = r-1; x >= 0; x--) {
    out << "  |";
    for (int y = 0; y < c-1; y++)
      out << "----";
    out << "---|" << endl << x << " |";
    for (int y = 0; y < c-1; y++)
      if (b[x][y] == 0)
	out << "   |";
      else
	out << " " << b[x][y] << " |";
    if (b[x][c-1] == 0)
      out << "   |" << endl;
    else
      out << " " << b[x][c-1] << " |" << endl;
  }
	
  out << "  |";
  for (int y = 0; y < c-1; y++)
    out << "----";
  out << "---|" << endl; 
  
  out << " ";
  for (int y = 0; y < c; y++)
    out << "   " << y;
    
  out << endl;
} // end drawboard function

int humanmove(int player, char board[][7], int rows, int columns){
 
  char symbol;

  if(player == 1)
    symbol = 'X';
  else
    symbol = 'O';

  int col;	
  cout << "What column would Player " << player << " like to play in?: " ;
  cin >> col;	
	
  while ((col < 0) || (col >= columns)){
    cout << "Invalid selection. There aren't that many columns. Please enter a different column number: ";
    cin >> col;
  }	
 
  int row;
  for(row = 5; row >= 0; row--){ 
    if(board[row][col] != 0)
      break;
  }  

  board[row+1][col] = symbol;
  if (row == 'X' || row == 'O'){
		cout << "Column " << col << " is full. Please choose another: ";
		cin >> col;
	}else{
	drawboard(cout, board, 6, 7);
	}
 } 
  
int verticalwin(char board[][7], int rows, int columns, int moverow, int movecolumn){




	
	
	
}
