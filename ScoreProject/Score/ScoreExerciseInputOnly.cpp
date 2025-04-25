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
        cout  << "score is ===>" << name << ": " << goals << ", " << behinds << ", " << getScore() << endl;
    }
};

int main() {
    Team team1, team2;
    int option;

    cout << "Welcome to the AFL score calculator!\n";

    // Input team 1
    cout << "\nEnter team 1 details:\n";
    cout << "name: ";
    cin >> team1.name;
    cout << "goals: ";
    cin >> team1.goals;
    cout << "behinds: ";
    cin >> team1.behinds;
    
    team1.printScore();

    return 0;
}