#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double price, discount;

    cout << "Enter the item price: ";
    cin >> price;
    cout << "Enter the discount percentage (0-100): ";
    cin >> discount;

    if (!cin || price <= 0 || discount < 0 || discount > 100) {
        cout << "Invalid input. Price must be above 0 and discount between 0 and 100." << endl;
        return 1;
    }

    double finalPrice = price - (price * discount / 100);

    cout << fixed << setprecision(2);
    cout << "Final price after discount: $" << finalPrice << endl;
    return 0;
}