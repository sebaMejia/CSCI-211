/**
 * @file nqueen.cpp
 * @author Sebastian Mejia
 * N Queens Problem
 */
#include <iostream>
#include <cmath>
using namespace std;
/***
 * Same checker as before for the position checking.
*/
bool ok(int q[], int c){
    for(int i = 0; i < c; i++){
        if(q[c]==q[i] || (c - i) == abs(q[c]-q[i])){
            return false;
        }
    }
    return true;
}
/***Basically works the same way as the previous iterations of the eight queen problem, by using the applied 
 * properties stated in the sheet and the implemented backtracking system that was used before.
***/ 
int printSolutions(int x){
    int *q = new int[x];
    q[0] = 0; 
    int i = 0, solution = 0;
    while(i >= 0){
        if(i == x - 1){
            solution++;
            --i;
        }
        else q[++i] = -1;
        while (i >= 0){
            ++q[i];
            if(q[i] == x)
            --i;
            else if (ok(q,i))
            break;
        }
        
    }
    delete[] q;
    return solution;
}

int main(){
    int n;
    cout << "Please enter a number: ";
    cin >> n;
    for(int i = 1; i <= n; i++){
        cout << "There are " << printSolutions(i) << " solutions to the " << i << " queens problem." << endl;
    }
    return 0;
}