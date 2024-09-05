/*
I. Winner of the election

Write a C++ program that allows the user to enter the last names of five candidates
in a local election and the number of votes received by each candidate.
The program should then output each candidate’s name, the number of votes received,
and the percentage of the total votes received by the candidate. Your program should also output the winner of the election.

Example:
enter candidates last name, there are five candidates
enter candidate 0 last name
Peter
enter no of votes received by candidate 0
30
enter candidate 1 last name
Roy
enter no of votes received by candidate 1
20
enter candidate 2 last name
Ali
enter no of votes received by candidate 2
40
enter candidate 3 last name
Hales
enter no of votes received by candidate 3
60
enter candidate 4 last name
John
enter no of votes received by candidate 4
10
result of the election.............
name of candidate       vote received   percentage
Peter                   30              18%
Roy                     20              12%
Ali                     40              25%
Hales                   60              37%
John                    10              6%
The winner is Hales


Note:
- Program must be written in C++ and must use a class
- Use \t when displaying candidate name, vote received and percentage

*/

#include <stdio.h>
#include <string>
#include <iostream>
#include <cmath> // to truncate
#include <iomanip> // for setprecision
using namespace std;

class Candidate{
    public:  
        // Class variables  
        string lastName;
        int votesReceived; // needs to be accessed from main
        double percentage;
        // Class functions
        void getCandidateDetails(int candidateNumber) {
            cout << "enter candidate " << candidateNumber << " last name\n";
            cin >> lastName;
            cout << "enter no of votes received by candidate " << candidateNumber << "\n";
            cin >> votesReceived;
        }

        void calculatePercentage(int totalVotes) {
            percentage = (static_cast<double>(votesReceived) / totalVotes)*100;
            percentage = trunc(percentage);
        }

        void displayCandidateDetails() {
            cout << setw(15) << lastName << "\t" << setw(15) << votesReceived << "\t" << setw(10) << fixed << setprecision(0) << percentage << "%" << endl;
        }
};

int main() {
    // Declare variables
    const int numCandidates = 5;
    Candidate candidates[numCandidates];
    int totalVotes = 0;

    // Get input for candidate details
    for(int i = 0; i < numCandidates; i++){
        candidates[i].getCandidateDetails(i);
        totalVotes += candidates[i].votesReceived;
    }

    // Calculate vote percentage and display results
    cout << "result of the election............." << endl;
    cout << "name of Candidate\tvote received\tpercentage" << endl;
    for(int i = 0; i < numCandidates; i++){
        candidates[i].calculatePercentage(totalVotes);
        candidates[i].displayCandidateDetails();
    }

    // Determine the winner of the election
    int winnerIndex = 0;
    for(int i = 1; i < numCandidates; i++){
        if(candidates[i].votesReceived > candidates[winnerIndex].votesReceived){
            winnerIndex = i;
        }
    }
    cout << "The winner is " << candidates[winnerIndex].lastName << endl;

    return 0;
}
