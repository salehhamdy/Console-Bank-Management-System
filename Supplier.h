#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <string>
#include <iostream>
#include "LinkedList.h"

class SparePart; // Forward declaration

class Supplier {
private:
    std::string supplierName;
    int supplierCode;
    std::string address;
    std::string telephone;
    std::string email;
    LinkedList<SparePart*> spareParts; // Linked list of pointers to spare parts

public:
    Supplier();
    Supplier(std::string name, int code, std::string addr, std::string tel, std::string mail);

    void getdata();
    void putdata() const;
    void modifydata();

    int getSupplierCode() const;
    int getKey() const; // Added for Tree compatibility

    // SparePart management
    void addSparePart(SparePart* part);
    void displaySpareParts() const;
};

#endif // SUPPLIER_H
