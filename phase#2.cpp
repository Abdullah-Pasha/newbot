#include <iostream>
#include <string>

using namespace std;
void addProduct(int productIds[], string productNames[], string productDescriptions[], int quantities[], double prices[], int& productCount);
void displayProducts(int productIds[], string productNames[], string productDescriptions[], int quantities[], double prices[], int productCount);
void updateProduct(int productIds[], string productNames[], int quantities[], double prices[], int productCount);

const int MAX_PRODUCTS = 50;
const int MAX_VENDORS = 10;

int main() {
    char choice;
    
	int productIds[MAX_PRODUCTS];
    string productNames[MAX_PRODUCTS];
    string productDescriptions[MAX_PRODUCTS];
    int quantities[MAX_PRODUCTS];
    double prices[MAX_PRODUCTS];
    int productCount = 0;

   

    do {
        cout << "Store management system:" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Display Products" << endl;
        cout << "3. Update Product" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                addProduct(productIds, productNames, productDescriptions, quantities, prices, productCount);
                break;
            case '2':
                displayProducts(productIds, productNames, productDescriptions, quantities, prices, productCount);
                break;
            case '3':
                updateProduct(productIds, productNames, quantities, prices, productCount);
                break;
            case '4':
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != '4');

    return 0;
}


void addProduct(int productIds[], string productNames[], string productDescriptions[], int quantities[], double prices[], int& productCount) {
    cout << "Enter product ID: ";
    cin >> productIds[productCount];
    
    cout << "Enter product name: ";
    cin.ignore(); 
    getline(cin, productNames[productCount]);
    
    cout << "Enter product description: ";
    getline(cin, productDescriptions[productCount]);
    
    cout << "Enter quantity on hand: ";
    cin >> quantities[productCount];
    
    cout << "Enter price: ";
    cin >> prices[productCount];

    productCount++;
}

void displayProducts(int productIds[], string productNames[], string productDescriptions[], int quantities[], double prices[], int productCount) {
    for (int i = 0; i < productCount; ++i) {
        cout << "Product ID: " << productIds[i] << endl;
        cout << "Name: " << productNames[i] << endl;
        cout << "Description: " << productDescriptions[i] << endl;
        cout << "Quantity on Hand: " << quantities[i] << endl;
        cout << "Price: $" << prices[i] << endl << endl;
    }
}

void updateProduct(int productIds[], string productNames[], int quantities[], double prices[], int productCount) {
    int productId;
    cout << "Enter the product ID to update: ";
    cin >> productId;

    int index = -1;
    for (int i = 0; i < productCount; ++i) {
        if (productIds[i] == productId) {
            index = i;
            break;
        }
    }

    if (index != -1) 
	{
        cout << "Enter new quantity on hand: ";
        cin >> quantities[index];

        cout << "Enter new price: ";
        cin >> prices[index];

        cout << "Product information updated successfully." << endl;
    }
	 else {
        cout << "Product not found." << endl;
    }
}



