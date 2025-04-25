#include <iostream>
#include <string>
#include <limits> // Required for numeric_limits
using namespace std;

struct Team {
    string name;
    int goals;
    int behinds;

    int getScore() {
        return goals * 6 + behinds;
    }

    void printScore() {
        cout << name << ": " << goals << ", " << behinds << ", " << getScore() << endl;
    }
};

// Function to get and validate integer input
int getValidInteger(const string& prompt) {
    int value;
    cout << prompt;
    while (!(cin >> value)) {
        cout << "Invalid input. Please enter an integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // consume the newline
    return value;
}

void printResult(Team& team1, Team& team2) {
    cout << "\nCalculating details...\n";
    if (team1.getScore() > team2.getScore())
        cout << "The " << team1.name << " are winning\n";
    else if (team2.getScore() > team1.getScore())
        cout << "The " << team2.name << " are winning\n";
    else
        cout << "It is currently a draw!\n";

    team1.printScore();
    team2.printScore();
}

int main() {
    Team team1, team2;
    int option;

    cout << "Welcome to the AFL score calculator!\n";

    // Input team 1
    cout << "\nEnter team 1 details:\n";
    cout << "name: ";
    getline(cin >> ws, team1.name);
    team1.goals = getValidInteger("goals: ");
    team1.behinds = getValidInteger("behinds: ");

    // Input team 2
    cout << "\nEnter team 2 details:\n";
    cout << "name: ";
    getline(cin >> ws, team2.name);
    team2.goals = getValidInteger("goals: ");
    team2.behinds = getValidInteger("behinds: ");

    printResult(team1, team2);

    return 0;
}