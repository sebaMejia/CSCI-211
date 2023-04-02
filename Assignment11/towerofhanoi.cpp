/**
 * @file towerofhanoi.cpp
 * @author Sebastian Mejia
 */

#include <iostream>
#include<vector>
using namespace std;

int main(){
    // This is to initialize the actual towers for the pieces to move in.
    vector <int> t[3]; 
    // Initialize the respective variables
    int n, c, to, from, move = 0;
    cout << "Please enter a number of rings to move: ";
    cin >> n;
    cout << endl;
    // This is to initalize the towers by the push_back method that inserts any new element at the end of the vector that'll be declared
    for(int i = n + 1; i >= 1; i--)
        t[0].push_back(i);
    
    t[1].push_back(n+1);
    t[2].push_back(n+1);
    
    from = 0;
    
    if((n % 2) == 1)
        to = 1;
    else
        to = 2;
    
    c = 1;
    // The while loop basically has the measure to make sure that the size of the ring doesn't surpass the threshold and as such, it'll work in a way to push the rings from and to the 
    // respective towers that are needed to complete the tower
    while(t[1].size() < n + 1){
        // The char(x+65) is to assign the respective tower from A-C
        cout << "Number " << ++move << ": \n Transfer ring " <<c<<  " from tower " << char(from+65) << " to tower " << char(to+65) << endl << endl;
        t[to].push_back(t[from].back());
        t[from].pop_back();
        if((n % 2) == 1){
            if(t[(to+1) % 3].back() < t[(to+2) % 3].back())
                from = (to+1) % 3;
            else
                from = (to+2) % 3;
            if(t[from].back() < t[(from+1) % 3].back())
                to = (from+1) % 3;
            else
                to = (from+2) % 3;
            c = (t[from].back());
        }
        else {
            if(t[(to+1) % 3].back() < t[(to+2) % 3].back())
                from = (to+1) % 3;
            else
                from = (to+2) % 3;
            if(t[from].back() < t[(from+2) % 3].back())
                to = (from+2) % 3;
            else
                to = (from+1) % 3;
            c = (t[from].back());
        }
    }
}
