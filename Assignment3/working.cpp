/*
  This is a 2 dimentional array of 8 queens problem.
  with "GoTo" to jump around the codes as well.
  r = row c = column.
  It prints out the 92 solutions as a 8x8 board layout.
*/

#include <iostream>
using namespace std;

int main(){

  int q[8][8] = {};// Initialize the board to 0
  int r = 0, c = 0;// Start in the 1st row, 1st column
  q[r][c] = 1; // Place the first queen on the upper left corner

nextCol:
  // Move to the next column
  c++;
  // If you passed the last column
      //goto print
  if (c == 8) goto print;
  // Otherwise start at the "TOP" of the column TOP is -1.
  r = -1;

nextRow:
  // Move to the next row
  r++;
  if (r == 8) goto backtrack;
  // row test ---------------------
  for (int i = 0; i < c; i++){
    if (q[r][i] == 1) goto nextRow;
  }
  // up diagonal test -------------
  for (int i = 1; ((r-i)>=0 && (c-i)>=0); i++){
    if (q[r-i][c-i] == 1) goto nextRow;
  }
  // down diagonal test -----------
  for (int i = 1; ((r+i)<=7 && (c-i)>=0); i++){
    if (q[r+i][c-i] == 1) goto nextRow;
  }
  q[r][c] = 1;
  goto nextCol;

backtrack:
  // Move to the previous column
  c--;
  //if (you have moved to the left of the chessboard)
        //exit the program
  if (c == -1){
    cout << "No more solutions.\n";
    return 0;
  }
  // Find the square in the column with a queen in it and set r to the row number of that square
  r = 0;
  while (q[r][c] != 1){
    r++;
  }
  // Remove the queen from the current square
  q[r][c] = 0;
  //goto nextRow;
  goto nextRow;

print:
  static int numSolutions = 0;
  cout << "Solution #" << ++numSolutions << ":\n";
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      cout << q[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  goto backtrack;
}