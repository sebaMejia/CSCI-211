#include <iostream>
#include <cmath>
using namespace std;

/*
*Sebastian Mejia CSCI 211
*Eight Queen Problem 1D Array without GOTOs
*/

// The function below is basically using two for loops to read the q[] and then seeing if it's equal to the i value so that it can be placed there
// If it can't then it'll be indicated with a 0
void printSolutions(int q[]){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(q[j] == i) cout << 1 << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool checkPosition(int q[], int c){
    for(int i = 0; i < c; i++){
        // These are just to check if there's going to be any conflicts within the array so that it can then be returned to false
        if(q[c] == q[i] || ((c-i) == abs(q[i] - q[c]))){
            return false;
        }
        if(q[c] == 8){
        return false;
        }
    }
    // If there aren't any conflicts then it'll return true to then move onto the next solution set.
    return true;
}


int main(){
    // intergerizing the values
    int q[8] = {}, c =0, solutionNum = 0;
    // starting position at 0 
    q[0] = 0;
    while(c >= 0){
        //Starting a new column, hence the while loop
        c++;

        // Once the column reached 8 then it'll be printed.
        if(c > 7){
            printSolutions(q);
            // Raising the solutionNum everytime a solution is printed 
            solutionNum++;
            cout << "Solution: " << solutionNum << endl;
            c--;
        }
        // It'll start to move into rows by first going to the one before it 
        else 
        q[c] = -1;
        // With the start of the first row, since c is theorethically equal to 0 it'll move into this while loop
        while(c >= 0){

            q[c]++; // Starts the new row 

            if(q[c] == 8){
                // It'll start to backtrack 
                c--;
            }
            // Once this row is checked to see if there are any conflicts then it'll break from this while loop and back to the original one
            else if(checkPosition(q,c) == true) 
            break;
        }
    }
    return 0;

}

