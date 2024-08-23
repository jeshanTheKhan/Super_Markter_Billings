#include <bits/stdc++.h>
#include <vector>
#include <iomanip>

using namespace std;

// Define a struct to represent a product
struct Product {
    int id;
    string name;
    double price;
};

// Function to display the product list
void displayProducts(const vector<Product>& products) {
    cout << "ID         Product Name       Price" << endl;
    cout << "---------------------------------" << endl;
    for (const Product& product : products) {
        cout << setw(3) << product.id << " " << setw(16) << product.name << " " << setw(6) << fixed << setprecision(2) << product.price << endl;
    }
    cout << "---------------------------------" << endl;
}

// Function to calculate the total price
double calculateTotalPrice(const vector<Product>& products, const vector<int>& quantities) {
    double total = 0.0;
    for (size_t i = 0; i < products.size(); ++i) {
        total += products[i].price * quantities[i];
    }
    return total;
}

int main() {
    vector<Product> products = {
        {1, "Bread", 80},
        {2, "Milk", 60},
        {3, "Eggs", 40},
        {4, "Apple", 65},
        {5, "Drinks(Tiger)", 30},
        {6, "Drinks(Pepsi)", 30},
        {5, "Banana", 20}
    };

    vector<int> quantities(products.size(), 0);

    char choice;
    do {
        cout << "Supermarket Billing System" << endl;
        cout << "--------------------------" << endl;
        cout << "1. Display Products" << endl;
        cout << "2. Add Product to Cart" << endl;
        cout << "3. View Cart" << endl;
        cout << "4. Checkout" << endl;
        cout << "5. Exit" << endl;
        cout << "--------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                displayProducts(products);
                break;
            case '2':
                int productId, quantity;
                cout << "Enter the product ID: ";
                cin >> productId;
                cout << "Enter the quantity: ";
                cin >> quantity;
                if (productId >= 1 && productId <= static_cast<int>(products.size())) {
                    quantities[productId - 1] += quantity;
                    cout << "Added " << quantity << " " << products[productId - 1].name << "(s) to your cart." << endl;
                } else {
                    cout << "Invalid product ID." << endl;
                }
                break;
            case '3':
                cout << "Cart Contents:" << endl;
                for (size_t i = 0; i < products.size(); ++i) {
                    if (quantities[i] > 0) {
                        cout << products[i].name << ": " << quantities[i] << " @ $" << products[i].price << " each" << endl;
                    }
                }
                break;
            case '4':
                cout << "Total Price: TK-" << calculateTotalPrice(products, quantities)   << endl;
                break;
            case '5':
                cout << "Exiting the program. Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != '5');

    return 0;
}
