#ifndef SPAREPART_H
#define SPAREPART_H

#include <string>
#include <iostream>
#include "LinkedList.h"

class Supplier; // Forward declaration

class SparePart {
private:
    std::string partName;
    int partNumber;
    double cost;
    int existingParts;
    LinkedList<Supplier*> suppliers; // Linked list of pointers to suppliers

public:
    SparePart();
    SparePart(std::string name, int number, double cost, int existing);

    void getdata();
    void putdata() const;
    void modifydata();

    int getPartNumber() const;
    int getKey() const; // Added for Tree compatibility

    // Supplier management
    void addSupplier(Supplier* supplier);
    void displaySuppliers() const;
};

#endif // SPAREPART_H
