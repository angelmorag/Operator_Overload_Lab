//
// Created by angel on 3/23/2026.
//

#ifndef POINTER_VECTORS_LAB_BOOK_H
#define POINTER_VECTORS_LAB_BOOK_H

#include <string>


class Book {
private:
    std::string title;
    std::string author;
    double price;

public:
    Book(std::string title, std::string author, double price);

    void displayInfo() const;
};


#endif //POINTER_VECTORS_LAB_BOOK_H