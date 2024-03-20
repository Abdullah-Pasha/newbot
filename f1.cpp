#include <iostream>
#include <fstream>

const int MAX_PRODUCTS = 100;

void displayCatalog(int pid[], std::string name[], double price[], int size) {
    std::cout << "Catalogue:\n";
    std::cout << "PID\tProduct\t\tPrice\n";
    for (int i = 0; i < size; ++i) {
        std::cout << pid[i] << "\t" << name[i] << "\t\t$" << price[i] << std::endl;
    }
}

void saveBill(int pid[], std::string name[], double price[], int quantity[], int size) {
    std::ofstream outputFile("bill.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Error opening file 'bill.txt'\n";
        return;
    }

    outputFile << "Bill:\n";
    outputFile << "PID\tProduct\t\tPrice\tQuantity\tTotal\n";
    double totalBill = 0.0;
    for (int i = 0; i < size; ++i) {
        double total = price[i] * quantity[i];
        totalBill += total;
        outputFile << pid[i] << "\t" << name[i] << "\t\t$" << price[i] << "\t" << quantity[i] << "\t\t$" << total << std::endl;
    }
    outputFile << "Total Bill: $" << totalBill << std::endl;

    outputFile.close();
}

int main() {
    int pid[MAX_PRODUCTS];
    std::string name[MAX_PRODUCTS];
    double price[MAX_PRODUCTS];
    int quantity[MAX_PRODUCTS];
    int productCount = 0;

    std::ifstream inputFile("product.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file 'product.txt'\n";
        return 1;
    }

    // Read product details from the file
    while (productCount < MAX_PRODUCTS && inputFile >> pid[productCount] >> name[productCount] >> price[productCount]) {
        ++productCount;
    }

    inputFile.close();

    displayCatalog(pid, name, price, productCount);

    char choice;
    do {
        std::cout << "Enter PID and quantity (or 'B' to exit): ";
        std::cin >> choice;

        if (choice != 'B') {
            int selectedPid, selectedQuantity;
            std::cout << "Enter PID: ";
            std::cin >> selectedPid;

            std::cout << "Enter quantity: ";
            std::cin >> selectedQuantity;

            // Assuming PIDs are unique, find the selected product in the catalog
            int index = -1;
            for (int i = 0; i < productCount; ++i) {
                if (pid[i] == selectedPid) {
                    index = i;
                    break;
                }
            }

            if (index != -1) {
                quantity[index] += selectedQuantity;
            } else {
                std::cerr << "Product not found in the catalog.\n";
            }
        }

    } while (choice != 'B');

    saveBill(pid, name, price, quantity, productCount);

    return 0;
}
