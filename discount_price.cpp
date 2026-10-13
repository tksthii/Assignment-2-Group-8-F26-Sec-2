#include <iostream>
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

    cout << "Price: " << price << ", Discount: " << discount << "%" << endl;
    return 0;
}