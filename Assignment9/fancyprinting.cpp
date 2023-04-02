#include <iostream>
using namespace std;
// Same checking position function we've used before
bool checkPosition(int q[], int c){
    for(int i = 0; i < c; i++){
        if(q[i] == q[c] || (c-i) == abs(q[c] - q[i]))
        return false;
    }
    return true;
}
// This is the function that basically gives us the fancy printing of the chess board
void printSolutions(int q[]){
    // Initializing the variables and making a typedef variable of the boxes for bb and wb which is equivalent to the black and white boxes
    int i, j, k, l;
    typedef char box[5][7];
    box bb, wb, *board[8][8];
    // This is to initialize the white and black board and fill them out respectively
    for(i = 0; i < 5; i++)
        for(j = 0; j < 7; j++){
            wb[i][j] = ' ';
            bb[i][j] = char(219);
        }
    // Both bq and wq is mean to represent the queen piece whenever it is able to do so
    box bq ={{char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
             {char(219),' '      ,char(219),' '      ,char(219),' '      ,char(219)},
             {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
             {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
             {char(219),char(219),char(219),char(219),char(219),char(219),char(219)}};

    box wq ={{' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      },
             {' '      ,char(219),' '      ,char(219),' '      ,char(219),' '      },
             {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
             {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
             {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      }};
    // This is meant to place the white and black queen respectively to their box as well as the boxes being filled with their respective pointer position to the respective solution
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            if((i+j)%2==0 && q[j] == i){
                board[i][j]= &wq;
            }
            else if((i+j)%2!=0 && q[j] == i){
                board[i][j]= &bq;
            }
            else if((i+j)%2==0){
                board[i][j]=&wb;
            }
            else board[i][j]= &bb;{
                cout<<" ";
            }
    //This is mean to act as the line borders outside of the chessboard
    for(i=0;i<7*8;i++){ 
        cout<<'_';
    }
    cout<< endl;
    // After all of the previous positions have been placed, they are then printed out into this for loop 
    for(i=0;i<8;i++)
        for(k=0;k<5;k++){
            cout<<" "<< char(179);
        for(j=0;j<8;j++)
            for(l=0;l<7;l++){
                // (*board[i][j])[j][l] is meant to be a culmination of the box pointers to their respective row and column
                cout << (*board[i][j])[k][l];

            }
                cout<<char(179)<<endl;
            }
                cout << " ";
    // This is mean to act as the border agains as well but for the rest of the chessboard, specifically the lower border     
    for(i=0;i<7*8;i++){
        cout<<char(196);
    }             
    cout <<endl;          
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