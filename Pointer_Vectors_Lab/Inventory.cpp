//
// Created by angel on 3/23/2026.
//

#include "Inventory.h"
#include <iostream>

Inventory::~Inventory() {
    std::cout<< "\n [System] Inventory destructor called. Cleaning up memory..." << std::endl;
    for (Book* ptr : books) {
        delete ptr;
    }
    books.clear();
    std::cout << "[System] All books safely deleted. No memory leaks!" << std::endl;
}

void Inventory::addBook(Book* bookPtr) {
    books.push_back(bookPtr);
    std::cout << "Book added to inventory successfully." << std::endl;
}

void Inventory::displayAll() const {
    if (books.empty()) {
        std::cout << "The inventory is currently empty." << std::endl;
        return;
    }

    for (size_t i = 0; i < books.size(); i++) {
        std::cout << "[" << i << "] ";
        books[i]->displayInfo();
    }
}

void Inventory::removeBook(int index) {
    if (index >= 0 && index < books.size()) {
        delete books[index];
        books.erase(books.begin() + index);
        std::cout << "Book at index" << index << "remove and deleted." << std::endl;
    } else {
        std::cout << "Error: Invalid index" << std::endl;
    }
}
