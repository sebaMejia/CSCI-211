// Sebastian Mejia 
// CSCI211 Lab 21B 

#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

int main(){
    int b[8][8] = {0}; // This is just setting up the board into an 8x8
    int r = 0, c = 0; // Initializing the values for the rows and columns 
    b[0][0] = 1; // From the lecture, we started with the queen piece at the top left corner until all solutions were completed
    
    nc: // the goto label for the next column whenever it's called to then start the new column with the c++.
    c++;
    if(c==8) goto print; // once it's completed with the for loops it jumps to the print label below to print out the board with the solution.
    // If it doesn't equal to 8 in the column then it moves to the new column and resets the row at the start of the new column.
    r= -1;

    nr:// works the same way as the new column but just switching it around with the row.  
    r++;
    // Below is the backtrack goto that basically works similarly to the column if statement but moves it to decrease the 
    if(r==8) goto backtrack;
    // Below is the row test that basically sees if there's any conflicts and see if there's already a queen in the row and if there is then it moves on to the next
    for(int i = 0; i < c; i++)
        if(b[r][i]==1) goto nr;
    
    // This is to check upward direction diagonals to make sure that the queen piece is not conflicting with other queens from their relative position; if it does then it moves to the next
    for(int i = 1; (r-i) >= 0 && (c-i)>=0; i++)
        if(b[r-i][c-i]==1) goto nr;
    
    // This is to check the downward direction diagonals, same as before. 
    for(int i = 1; (r+i) < 8 && (c-i) >= 0; i++)
        if(b[r+i][c-i]==1) goto nr;
    // This is assigning the queen piece to that row and column position after testing to see if any of the conflicts occur. 
    b[r][c]=1;
    goto nc;

    backtrack: 

    // This is meant to move back a column, hence the backtracking to reset onto the new board once more.
    c--;
    // Basically once all solutions have been found then there's nothing more left to do and the program is exited. 
    if(c == -1) return 0;        

    // It's setting the row with the while loop trying to find the queen in there and setting the other values as 0 that doesn't have the queen
    r=0;
    
    while(b[r][c]!=1) r++;
    

    // This is meant to remove the queen from the position it was in so that it can then move onto the next row.    
    b[r][c] = 0;
    goto nr;
    // Once everything has been finihsed, this is meant to print the pieces so that it can start all over again. 
    print:
    cout << " ";
    for(int i = 0; i <8; i++){
        for(int j = 0; j < 8; j++){
            cout << b[i][j] << "\t";

        }
         cout << endl;   
    }
    goto backtrack;
}
