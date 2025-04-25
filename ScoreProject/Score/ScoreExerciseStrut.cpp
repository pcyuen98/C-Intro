#include <iostream>
#include <string>
using namespace std;

struct Team {
    string name;     // Name of the Australian Rules Football team
    int goals;      // Number of goals scored by the team

    // Prints the team's name and score breakdown
    void printScore() {
        cout << "Team Name-->" << name << ": " << goals << endl;
    }
};

int main() {
    Team team1, team2; // Declare two variables of the Team struct

    cout << "Welcome to the AFL score calculator!\n";

    // Initialize Team 1 using manual variable assignment
    team1.name = "Kangaroos";
    team1.goals = 10;

    // Initialize Team 2 using manual variable assignment
    team2.name = "Eagles";
    team2.goals = 8;

    // Print the scores of both teams
    team1.printScore();

    return 0; // Indicate successful program execution
}