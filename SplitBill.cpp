#include <iostream>
#include <stdexcept>
#include <cmath>

// Calculates the equal split amount for a given total bill and number of people
double splitBill(double totalAmount, int numberOfPeople) {
    if (numberOfPeople <= 0) {
        throw std::invalid_argument("Number of people must be greater than 0");
    }
    return std::round((totalAmount / numberOfPeople) * 100.0) / 100.0;
}

// Displays the split result to the user
void displaySplitResult(double totalAmount, int numberOfPeople) {
    try {
        double amountPerPerson = splitBill(totalAmount, numberOfPeople);
        std::cout << "Total bill: $" << totalAmount << std::endl;
        std::cout << "Number of people: " << numberOfPeople << std::endl;
        std::cout << "Each person owes: $" << amountPerPerson << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

// Reads the total bill amount and number of people from user input
void readBillInput(double& totalAmount, int& numberOfPeople) {
    std::cout << "Enter total bill amount: $";
    std::cin >> totalAmount;

    std::cout << "Enter number of people: ";
    std::cin >> numberOfPeople;
}

int main() {
    double totalAmount = 0.0;
    int numberOfPeople = 0;

    readBillInput(totalAmount, numberOfPeople);
    displaySplitResult(totalAmount, numberOfPeople);

    return 0;
}