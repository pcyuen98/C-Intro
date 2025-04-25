#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Structure to store team data
struct Team {
    string name;
    int goals = 0;
    int behinds = 0;

    // Calculates total score for the team (1 goal = 6 points)
    int getScore() const {
        return goals * 6 + behinds;
    }

    // Displays the team details including total score
    void printDetails() const {
        cout << name << ": " << goals << ", " << behinds << ", " << getScore() << endl;
    }
};

// Prompts user to enter a whole number, re-prompts if input is invalid
int getWholeNumber(string prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (!cin.fail()) {
            return value;
        }
        else {
            cout << "Please enter a whole number" << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    }
}

// Gets a yes/no response from the user
char getYesNo(string prompt) {
    string input;
    while (true) {
        cout << prompt;
        cin >> input;
        if (input == "y" || input == "Y") return 'y';
        if (input == "n" || input == "N") return 'n';
        cout << "Please enter y or n" << endl;
    }
}

// Initializes both teams with user input
void initializeTeams(Team& team1, Team& team2) {
    cout << "Welcome to the AFL score calculator!\n\n";

    // Input for team 1
    cout << "Enter team 1 details:\n";
    cout << "name: ";
    cin >> team1.name;
    team1.goals = getWholeNumber("goals: ");
    team1.behinds = getWholeNumber("behinds: ");

    // Input for team 2
    cout << "\nEnter team 2 details:\n";
    cout << "name: ";
    cin >> team2.name;
    team2.goals = getWholeNumber("goals: ");
    team2.behinds = getWholeNumber("behinds: ");
}

// Displays the menu and gets user's choice
int displayMenuAndGetOption(const Team& team1, const Team& team2) {
    int option;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1: Update " << team1.name << " goals\n";
        cout << "2: Update " << team1.name << " behinds\n";
        cout << "3: Update " << team2.name << " goals\n";
        cout << "4: Update " << team2.name << " behinds\n";
        cout << "5: Print details\n";
        cout << "6: Quit\n";
        cout << "Option: ";
        cin >> option;

        if (!cin.fail()) {
            return option;
        }

        cout << "Please enter a whole number" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Processes user's menu selection and updates team data accordingly
bool handleMenuOption(int option, Team& team1, Team& team2) {
    switch (option) {
    case 1:
        // Update team 1 goals
        team1.goals = getWholeNumber("goals: ");
        break;
    case 2:
        // Update team 1 behinds
        team1.behinds = getWholeNumber("behinds: ");
        break;
    case 3:
        // Update team 2 goals
        team2.goals = getWholeNumber("goals: ");
        break;
    case 4:
        // Update team 2 behinds
        team2.behinds = getWholeNumber("behinds: ");
        break;
    case 5:
        // Show current score status and which team is winning
        cout << "\nCalculating details...\n";
        if (team1.getScore() > team2.getScore())
            cout << "The " << team1.name << " are winning\n";
        else if (team2.getScore() > team1.getScore())
            cout << "The " << team2.name << " are winning\n";
        else
            cout << "It is currently a draw!\n";

        team1.printDetails();
        team2.printDetails();
        break;
    case 6:
        // Confirm exit
        if (getYesNo("Are you sure you want to quit? [Y/n]: ") == 'y') {
            cout << "\nBye!" << endl;
            return true; // Signal to exit loop
        }
        break;
    default:
        cout << "Please enter a number between 1 and 6" << endl;
        break;
    }
    return false; // Continue program
}

// Main game loop: displays current scores, handles menu and updates
void runScoreTracker(Team& team1, Team& team2) {
    while (true) {
        // Display who's currently winning or if it's a draw
        cout << "\nCalculating details...\n";
        int score1 = team1.getScore();
        int score2 = team2.getScore();

        if (score1 > score2)
            cout << "The " << team1.name << " are winning\n";
        else if (score2 > score1)
            cout << "The " << team2.name << " are winning\n";
        else
            cout << "It is currently a draw!\n";

        team1.printDetails();
        team2.printDetails();

        // Get user menu choice
        int option = displayMenuAndGetOption(team1, team2);

        // Handle menu action, break loop if user chooses to quit
        if (handleMenuOption(option, team1, team2))
            break;
    }
}

// Entry point of the program
int main() {
    Team team1, team2;
    initializeTeams(team1, team2);  // Get team names and starting scores
    runScoreTracker(team1, team2);  // Start tracking and interacting
    return 0;
}
