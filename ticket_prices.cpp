#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <limits>
using namespace std;

int readNumber(string prompt, string errorMessage, int maximum) {
    string input;
    int value;
    char extra;
    while (true) {
        cout << prompt;
        if (!getline(cin, input)) return 0;
        istringstream check(input);
        if ((check >> value) && !(check >> extra) && value > 0 && value <= maximum)
            return value;
        cout << errorMessage << '\n';
    }
}

int main() {
    string sections[] = {"Behind the Goal", "Upper Sideline", "Lower Sideline", "VIP"};
    double prices[] = {50, 75, 100, 150};
    cout << fixed << setprecision(2);
    cout << "STADIUM TICKET PRICES - Sample prices in CAD\n";
    for (int i = 0; i < 4; i++)
        cout << i + 1 << ". " << sections[i] << " - $" << prices[i] << '\n';
    int section = readNumber("Choose a section (1-4): ",
                            "Invalid section. Enter a whole number from 1 to 4.", 4);
    if (section == 0) return 0;
    int quantity = readNumber("Enter number of tickets: ",
                             "Invalid quantity. Enter a positive whole number.",
                             numeric_limits<int>::max());
    if (quantity == 0) return 0;
    cout << "\nSection: " << sections[section - 1] << '\n';
    cout << "Price per ticket: $" << prices[section - 1] << '\n';
    cout << "Tickets: " << quantity << '\n';
    cout << "Total cost: $" << prices[section - 1] * quantity << " CAD\n";
}