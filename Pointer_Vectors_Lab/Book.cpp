//
// Created by angel on 3/23/2026.
//

#include "Book.h"
#include <iostream>

Book::Book(std::string title, std::string author, double price) {
    this->title = title;
    this->author = author;
    this->price = price;
}

void Book::displayInfo() const {
    std::cout << "Title: " << title << " | Author: " << author << " | Price: " << price << std::endl;
}

