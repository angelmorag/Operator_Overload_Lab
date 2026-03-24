//
// Created by angel on 3/23/2026.
//

#ifndef POINTER_VECTORS_LAB_INVENTORY_H
#define POINTER_VECTORS_LAB_INVENTORY_H

#include <vector>
#include "Book.h"


class Inventory {
private:
    std::vector<Book*> books;

public:
    ~Inventory();

    void addBook(Book* book);
    void displayAll() const;
    void removeBook(int index);

};


#endif //POINTER_VECTORS_LAB_INVENTORY_H