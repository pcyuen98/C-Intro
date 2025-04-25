#include <iostream>
#include <string>
using namespace std;

struct Team {
    string name;     // Name of the Australian Rules Football team
    int goals;      // Number of goals scored by the team
    int behinds;    // Number of behinds scored by the team

    // Calculates the total score of the team
    int getScore() {
        return goals * 6 + behinds; // Goals are worth 6 points, behinds are worth 1 point
    }

    // Prints the team's name and score breakdown
    void printScore() {
        cout << "Team Name-->" << name << ": " << goals << ", " << behinds << ", " << getScore() << endl;
    }
};

int main() {
    Team team1, team2; // Declare two variables of the Team struct

    cout << "Welcome to the AFL score calculator!\n";

    // Initialize Team 1 using manual variable assignment
    team1.name = "Kangaroos";
    team1.goals = 10;
    team1.behinds = 5;

    // Initialize Team 2 using manual variable assignment
    team2.name = "Eagles";
    team2.goals = 8;
    team2.behinds = 12;

    // Print the scores of both teams
    team1.printScore();
    team2.printScore();

    // exercise. Create a function here to print the winning team

    //void printResult(Team & team1, Team & team2) {
    //    cout << "\nCalculating details...\n";
    //    if (team1.getScore() > team2.getScore())
    //        cout << "The " << team1.name << " are winning\n";
    //    else if (team2.getScore() > team1.getScore())
    //        cout << "The " << team2.name << " are winning\n";
    //    else
    //        cout << "It is currently a draw!\n";

    //}


    return 0; // Indicate successful program execution
}