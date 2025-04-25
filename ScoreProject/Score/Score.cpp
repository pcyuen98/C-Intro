#include <iostream>
#include <string>
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
    getline(cin, team1.name);
    cout << "goals: ";
    cin >> team1.goals;
    cout << "behinds: ";
    cin >> team1.behinds;

    cin.ignore(); // flush newline

    // Input team 2
    cout << "\nEnter team 2 details:\n";
    cout << "name: ";
    getline(cin, team2.name);
    cout << "goals: ";
    cin >> team2.goals;
    cout << "behinds: ";
    cin >> team2.behinds;

    printResult(team1, team2);

    while (true) {
        cout << "\nMenu:\n";
        cout << "1: Update " << team1.name << " goals\n";
        cout << "2: Update " << team1.name << " behinds\n";
        cout << "3: Update " << team2.name << " goals\n";
        cout << "4: Update " << team2.name << " behinds\n";
        cout << "5: Print details\n";
        cout << "6: Quit\n";
        cout << "\nOption: ";
        cin >> option;

        int val;
        switch (option) {
        case 1:
            cout << "Please enter a whole number: ";
            cin >> val;
            team1.goals = val;
            break;
        case 2:
            cout << "Please enter a whole number: ";
            cin >> val;
            team1.behinds = val;
            break;
        case 3:
            cout << "Please enter a whole number: ";
            cin >> val;
            team2.goals = val;
            break;
        case 4:
            cout << "Please enter a whole number: ";
            cin >> val;
            team2.behinds = val;
            break;
        case 5:
            printResult(team1, team2);
            break;
        case 6: {
            string confirm;
            cout << "Are you sure you want to quit? (Y/n): ";
            cin >> confirm;
            if (confirm == "Y" || confirm == "y") {
                cout << "Bye!\n";
                return 0;
            }
            break;
        }
        default:
            cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
