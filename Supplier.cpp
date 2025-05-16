#include "Supplier.h"
#include "SparePart.h"

Supplier::Supplier()
    : supplierName(""), supplierCode(0), address(""), telephone(""), email("") {}

Supplier::Supplier(std::string name, int code, std::string addr, std::string tel, std::string mail)
    : supplierName(name), supplierCode(code), address(addr), telephone(tel), email(mail) {}

void Supplier::getdata() {
    std::cout << "================================================\n";
    std::cout << "Enter Supplier Name: ";
    std::cin >> supplierName;
    std::cout << "Enter Supplier Code: ";
    std::cin >> supplierCode;
    std::cout << "Enter Address: ";
    std::cin >> address;
    std::cout << "Enter Telephone: ";
    std::cin >> telephone;
    std::cout << "Enter Email: ";
    std::cin >> email;
}

void Supplier::putdata() const {
    std::cout << "================================================\n";
    std::cout << "Supplier Name: " << supplierName << std::endl;
    std::cout << "Supplier Code: " << supplierCode << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Telephone: " << telephone << std::endl;
    std::cout << "Email: " << email << std::endl;
}

void Supplier::modifydata() {
    std::cout << "================================================\n";
    std::cout << "Modify Supplier Name (" << supplierName << "): ";
    std::cin >> supplierName;
    std::cout << "Modify Address (" << address << "): ";
    std::cin >> address;
    std::cout << "Modify Telephone (" << telephone << "): ";
    std::cin >> telephone;
    std::cout << "Modify Email (" << email << "): ";
    std::cin >> email;
}

int Supplier::getSupplierCode() const {
    return supplierCode;
}

int Supplier::getKey() const {
    return supplierCode; // Unique identifier for the tree
}

void Supplier::addSparePart(SparePart* part) {
    spareParts.insertAtEnd(part);
}

void Supplier::displaySpareParts() const {
    std::cout << "Spare Parts supplied by Supplier Code " << supplierCode << ":\n";
    spareParts.display();
}
