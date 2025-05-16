#include <iostream>
#include "SparePart.h"
#include "Supplier.h"
#include "Stack.h"
#include "Queue.h"
#include "Tree.h"

int main() {
    Tree<SparePart> sparePartTree;
    Tree<Supplier> supplierTree;
    Stack interactionStack;
    Queue processingQueue;

    int sparePartCount = 0;
    int supplierCount = 0;

    // Input Spare Parts
    std::cout << "================================================\n";
    std::cout << "Enter number of spare parts (up to 100): ";
    std::cin >> sparePartCount;
    for (int i = 0; i < sparePartCount; ++i) {
        SparePart part;
        part.getdata();

        // Check for duplicates before inserting
        if (sparePartTree.search(part.getKey()) == nullptr) {
            sparePartTree.insert(part);
            interactionStack.push("User entered data for Spare Part number " + std::to_string(part.getPartNumber()));
            processingQueue.enqueue("Spare Part " + std::to_string(part.getPartNumber()) + " data processing in progress.");
        } else {
            std::cout << "Duplicate Part Number detected. Entry skipped.\n";
        }
    }

    // Input Suppliers
    std::cout << "================================================\n";
    std::cout << "Enter number of suppliers (up to 20): ";
    std::cin >> supplierCount;
    for (int i = 0; i < supplierCount; ++i) {
        Supplier supplier;
        supplier.getdata();

        // Check for duplicates before inserting
        if (supplierTree.search(supplier.getKey()) == nullptr) {
            supplierTree.insert(supplier);
            interactionStack.push("User entered data for Supplier code " + std::to_string(supplier.getSupplierCode()));
            processingQueue.enqueue("Supplier " + std::to_string(supplier.getSupplierCode()) + " data processing in progress.");
        } else {
            std::cout << "Duplicate Supplier Code detected. Entry skipped.\n";
        }
    }

    // Display Spare Parts
    std::cout << "================================================\n";
    std::cout << "\nSpare Parts Data (In-Order Traversal):\n";
    sparePartTree.display();

    // Display Suppliers
    std::cout << "================================================\n";
    std::cout << "\nSuppliers Data (In-Order Traversal):\n";
    supplierTree.display();

    // Search for a Spare Part
    std::cout << "================================================\n";
    int searchPartNumber;
    std::cout << "\nEnter Part Number to search: ";
    std::cin >> searchPartNumber;
    SparePart* foundPart = sparePartTree.search(searchPartNumber);
    if (foundPart) {
        std::cout << "Spare Part Found:\n";
        foundPart->putdata();
    } else {
        std::cout << "Spare Part with Part Number " << searchPartNumber << " not found.\n";
    }

    // Remove a Supplier
    std::cout << "================================================\n";
    int removeSupplierCode;
    std::cout << "\nEnter Supplier Code to remove: ";
    std::cin >> removeSupplierCode;
    supplierTree.remove(removeSupplierCode);
    std::cout << "Supplier with Code " << removeSupplierCode << " has been removed.\n";

    // Display Suppliers after removal
    std::cout << "================================================\n";
    std::cout << "\nSuppliers Data after Removal (In-Order Traversal):\n";
    supplierTree.display();

    // User Interaction Stack
    std::cout << "================================================\n";
    std::cout << "\nUser Interaction History:\n";
    interactionStack.display();

    // Processing Queue
    std::cout << "================================================\n";
    std::cout << "\nProcessing Queue:\n";
    processingQueue.display();

    return 0;
}
