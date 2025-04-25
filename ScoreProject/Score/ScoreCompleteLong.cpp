#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Team {
    string name;
    int goals = 0;
    int behinds = 0;

    int getScore() const {
        return goals * 6 + behinds;
    }

    void printDetails() const {
        cout << name << ": " << goals << ", " << behinds << ", " << getScore() << endl;
    }
};

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
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

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

int main() {
    Team team1, team2;

    // Team 1 input
    cout << "Welcome to the AFL score calculator!\n\n";
    cout << "Enter team 1 details:\n";
    cout << "name: ";
    cin >> team1.name;
    team1.goals = getWholeNumber("goals: ");
    team1.behinds = getWholeNumber("behinds: ");

    // Team 2 input
    cout << "\nEnter team 2 details:\n";
    cout << "name: ";
    cin >> team2.name;
    team2.goals = getWholeNumber("goals: ");
    team2.behinds = getWholeNumber("behinds: ");

    while (true) {
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

        cout << "\nMenu:\n";
        cout << "1: Update " << team1.name << " goals\n";
        cout << "2: Update " << team1.name << " behinds\n";
        cout << "3: Update " << team2.name << " goals\n";
        cout << "4: Update " << team2.name << " behinds\n";
        cout << "5: Print details\n";
        cout << "6: Quit\n";
        cout << "Option: ";

        int option;
        cin >> option;

        if (cin.fail()) {
            cout << "Please enter a whole number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (option) {
        case 1:
            team1.goals = getWholeNumber("goals: ");
            break;
        case 2:
            team1.behinds = getWholeNumber("behinds: ");
            break;
        case 3:
            team2.goals = getWholeNumber("goals: ");
            break;
        case 4:
            team2.behinds = getWholeNumber("behinds: ");
            break;
        case 5:
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
            if (getYesNo("Are you sure you want to quit? [Y/n]: ") == 'y') {
                cout << "\nBye!" << endl;
                return 0;
            }
            break;
        default:
            cout << "Please enter a number between 1 and 6" << endl;
            break;
        }
    }
}
