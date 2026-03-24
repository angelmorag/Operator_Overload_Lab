#include <iostream>
#include <string>
#include "Inventory.h"
#include "Book.h"

using namespace std;

int main() {
    Inventory store;
    int choice = 0;

    while (choice != 4) {
        cout << "\n========== BOOK INVENTORY ==========" << endl;
        cout << "1. Add New Book" << endl;
        cout << "2. Display All Books" << endl;
        cout << "3. Remove Book" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: " << endl;

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        if (choice == 1) {
            string title, author;
            double price;

            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);

            cout << "Enter author: ";
            getline(cin, author);

            cout << "Enter price: ";
            cin >> price;

            Book* newBook = new Book(title, author, price);
            store.addBook(newBook);
        } else if (choice == 2) {
            store.displayAll();
        } else if (choice == 3) {
            int index;
            cout << "Enter the index of the book to remove: ";
            cin >> index;
            store.removeBook(index);
        } else if (choice == 4) {
            cout << "Exiting program..." << endl;
        } else {
            cout << "Invalid choice. Please select 1-4." << endl;
        }
    }

    return 0;
}