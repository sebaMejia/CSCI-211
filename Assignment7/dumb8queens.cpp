/*
Sebastian Mejia
CSCS211 Dumb 8 Queens Assignment
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
/*
Relatively the same concept with the eight number 1D assignment and the backtracking included from c until one of the tests comes out false or returns true.
*/
bool ok(int q[8]){
    for(int c = 7; c > 0 ; c--){
        int r = 0;
        r = q[c];

        for(int i = 1; i <= c; i++){
            if(q[c-i] == r)
                return false;
            
            else if(q[c-i] == r-i)
                return false;
            
            else if(q[c-i] == r+i)
                return false;
        }
        
    }
    return true;
}
/*
Print solutions for the 1D array into a new 2D array solution that will be printed out. 
*/
void printSolutions(int q[8], int c){
    cout << "Solution: " << c << endl;
    int qSolution[8][8] = {0};

    for(int j = 0; j < 8; j++){
        qSolution[q[j]][j] = 1;
    }

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << qSolution[i][j] << " ";
        }
        cout << endl;
        }
    
    cout << endl;
}



int main(){
    int q[8] = {0};
    int counter = 1;
    for(int a = 0; a < 8; a++){
        for(int b = 0; b < 8; b++){
            for(int c = 0; c < 8; c++){
                for(int d = 0; d < 8; d++){
                    for(int e = 0; e < 8; e++){
                        for(int f = 0; f < 8; f++){
                            for(int g = 0; g < 8; g++){
                                for(int h = 0; h < 8; h++)
                                {
                                q[0] = a;
                                q[1] = b;
                                q[2] = c;
                                q[3] = d;
                                q[4] = e;
                                q[5] = f;
                                q[6] = g;
                                q[7] = h;
                                if(ok(q))
                                    printSolutions(q, counter++);
                                
                                q[0] = -1;
                                q[1] = -1;
                                q[2] = -1;
                                q[3] = -1;
                                q[4] = -1;
                                q[5] = -1;
                                q[6] = -1;
                                q[7] = -1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}