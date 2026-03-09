#include "BankAccount.cpp"
#include <iostream>
using namespace std;

int main() {
    cout << "--- Create your account ---\n";
    BankAccount myAcc = BankAccount::createAccountFromInput();

    int choice = 0;
    while (choice != 4) {
        cout << "\n1. Deposit\n2. Withdraw\n3. View Details\n4. Exit\n Choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number (1-4).\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                double amount;
                cout << "Enter deposit amount: ";
                cin >> amount;
                myAcc += amount;
                break;
            }
            case 2: {
                double amount;
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                myAcc -= amount;
                break;
            }
            case 3: {
                BankAccount::printAccount(myAcc);
                break;
            }
            case 4: {
                cout << "Exiting now, goodbye!\n";
                break;
            }
            default: {
                cout << "Invalid input, please choose a number (1-4).\n";
                break;
            }
        }
    }
}