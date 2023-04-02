/*
Sebastian Mejia
CSCI 211 LabB
Stable Marriage Problem
*/

#include <iostream>
using namespace std;
    static int mp[3][3] = {{0,2,1},{0,2,1},{1,2,0}}; // Men's Preferences
    static int wp[3][3] = {{2,1,0},{0,1,2},{2,0,1}}; // Women's Preferences
// This function basically prints the solutions
void printSolutions(int q[], int x){
    cout << "Solution: " << x << "\nMan" << "\tWoman\n";
    for(int i =0; i <3; i++){
        cout << i << "\t" << q[i] << "\n";
    }
}

bool okay(int q[], int c){
    
    // current = i and new = c 
    for(int i = 0; i < c; i++){
        // This checks to see if there's any instabilities introduced with any of the existing couples
        if(q[i] == q[c]){
            return false;
        }
        // Current man prefers the new woman to his partner and if the new woman prefers the current man to her partner; otherwise it'd return false
        else if(mp[i][q[i]] > mp[i][q[c]] && wp[q[c]][c] > wp[q[c]][i]){
            return false;
        }
        // New man prefers the current woman to his partner and if the current woman prefers the new man to her partner; otherwise it'd return false
        else if(mp[c][q[c]] > mp[c][q[i]] && wp[q[i]][i] > wp[q[i]][c])
        
            return false;
        } 
        // If there aren't any instabilities then we return true
        return true;
}


int main(){
    // intergerizing the values
    int q[3] = {}; 
    int c =0, solutionNum = 0;
    
    while(c >= 0){
        // Once the column reached 2 then it'll be printed.
        if(c == 2){
            printSolutions(q, solutionNum);
            // Raising the solutionNum everytime a solution is printed 
            solutionNum++;
            c--;
        }
        // It'll start to move into rows by first going to the one before it 
        else 
        q[++c] = -1;
        // With the start of the first row, since c is theorethically equal to 0 it'll move into this while loop
        while(c >= 0){

            q[c]++; // Starts the new row 

            if(q[c] == 3){
                // It'll start to backtrack 
                c--;
            }
            // Once this row is checked to see if there are any conflicts then it'll break from this while loop and back to the original one
            else if(okay(q,c)) 
            break;
        }
    }
    return 0;
}