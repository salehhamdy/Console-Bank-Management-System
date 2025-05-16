#include "SparePart.h"
#include "Supplier.h"

SparePart::SparePart() : partName(""), partNumber(0), cost(0.0), existingParts(0) {}

SparePart::SparePart(std::string name, int number, double cost, int existing)
    : partName(name), partNumber(number), cost(cost), existingParts(existing) {}

void SparePart::getdata() {
    std::cout << "================================================\n";
    std::cout << "Enter Part Name: ";
    std::cin >> partName;
    std::cout << "Enter Part Number: ";
    std::cin >> partNumber;
    std::cout << "Enter Cost: ";
    std::cin >> cost;
    std::cout << "Enter Existing Parts Quantity: ";
    std::cin >> existingParts;
}

void SparePart::putdata() const {
    std::cout << "================================================\n";
    std::cout << "Part Name: " << partName << std::endl;
    std::cout << "Part Number: " << partNumber << std::endl;
    std::cout << "Cost: " << cost << std::endl;
    std::cout << "Existing Parts: " << existingParts << std::endl;
}

void SparePart::modifydata() {
    std::cout << "================================================\n";
    std::cout << "Modify Part Name (" << partName << "): ";
    std::cin >> partName;
    std::cout << "Modify Cost (" << cost << "): ";
    std::cin >> cost;
    std::cout << "Modify Existing Parts Quantity (" << existingParts << "): ";
    std::cin >> existingParts;
}

int SparePart::getPartNumber() const {
    return partNumber;
}

int SparePart::getKey() const {
    return partNumber; // Unique identifier for the tree
}

void SparePart::addSupplier(Supplier* supplier) {
    suppliers.insertAtEnd(supplier);
}

void SparePart::displaySuppliers() const {
    std::cout << "Suppliers for Part Number " << partNumber << ":\n";
    suppliers.display();
}
