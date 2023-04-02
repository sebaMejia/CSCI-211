#include<iostream>
#include <algorithm>
#include <cctype>
#include <functional>
#include <string>
using namespace std;


string removeRepetition(string a) {
    string str = a;

    // Essentially sorts the string to common conventions.
    sort(begin(str), end(str));
    // Used to remove the duplicates associated with the string.
    auto last = unique(begin(str), end(str));
    str.erase(last, end(str));
    return str;
}
//This function acts as just obtaining the number of teams there are.
int numberOnTeam(string a, int b){
    int x;
    x= a.length()/b;
    return x;
}

int main() {
    
   while(true){     
    string charInput;
    int counter, numTeam, numRunners = 0;
    char teamLetter[numTeam];
    double teamScores[numTeam];
    double count,sum = 0;
    double average = 0;
    
    
    cout << "This game is a race where we have a certain number of teams that are represented with uppercase letters.\nPlease give an input with letters from A-Z.\nIn order to quit please type 'done'.\nInput: ";
    cin >> charInput;
    //This is the input check to see if it's done which will send them to return 0 and end the program.
    if(charInput == "done" || charInput == "DONE"){
        goto label1;
    }

    // This is for uppercasing the input regardless if it was lowercased.
    std::transform(charInput.begin(), charInput.end(), charInput.begin(), ::toupper);

    string x = removeRepetition(charInput);
    // The following two for loops are meant to check and see if the string inputed has the same amount fo runners for their respective team and how to handle it.
    for (int i=0; i<charInput.length(); i++) {
        if (charInput[i] == x[0]) {
            numRunners++;
        }
    }
    
    for (int i=0; i < x.length(); i++) {
        
        int checkRunners = 0;
        for (int j=0; j < charInput.length(); j++) {
            if (charInput[j] == x[i]) {
                checkRunners++;
            }
        
        }
            // Essentially acts as a way to terminate the program if there is more or less than the runners for their respective teams.
        
            if (checkRunners != numRunners) {
            cout << "There aren't enough runners or there is more runners than the respective teams";
            goto label2;
            }
        
    }
    // Refer to the function for further explanation
    numTeam = numberOnTeam(charInput, numRunners);
    // Outputting the values.
    cout << "There are " << numTeam << " teams.\t";
    cout << "Each team has " << numRunners << " runners.\t";
    
    

    // This portion I did find assistance from outside sources as I was stuck on this portion on how to implement the for loop with other resources.
    // Essentially this is the portion that calculates the scores of the respective teams and then averages it out.
    for (int i=0; i < x.length(); i++) {
        teamLetter[i] = x[i];
        sum = 0, count = 0, average = 0;
        for (int j=0; j < charInput.length(); j++) {
            if(charInput[j] == x[i]) {
                sum = sum + j + 1;
            }
        }
        average = sum/numRunners;
        teamScores[i] = average;
    }
    // This is the output for the team and scores that have been already calculated previously and assigning them to their respective team and position.
    cout << "\nTeam\tScore" << endl;
    for(int i = 0; i < numTeam; i++){
    cout << teamLetter[i] << "\t" << teamScores[i] << endl;
    }
    // This is used to display the actual value of the winner with the lowest element to indicate their position in the race.

    int raceWinner = distance(teamScores, min_element(teamScores, teamScores + numTeam));
    
    cout << "The winning team is team " << teamLetter[raceWinner] << " with a score of " << teamScores[raceWinner] << ".\n";
        
    
   }

    label1:
    label2:
    return 0;
}
