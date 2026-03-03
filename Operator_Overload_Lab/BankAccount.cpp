//
// Created by angel on 3/2/2026.
//
#include "BankAccount.h"
#include <iostream>
#include <cstring>
using namespace std;

// Constructor
BankAccount::BankAccount(int accNum, const string& name, double bal)
    : accountNumber(accNum), balance(bal) {
    accountHolderName = new char[name.length() + 1];
    strcpy(accountHolderName, name.c_str());
}

// Destructor
BankAccount::~BankAccount() {
    delete[] accountHolderName;
}

// Copy Constructor
BankAccount::BankAccount(const BankAccount& other) {
    accountNumber = other.accountNumber;
    balance = other.balance;
    accountHolderName = new char[strlen(other.accountHolderName) +1];
    strcpy(accountHolderName, other.accountHolderName);
}

// Copy Assignment Operator
BankAccount& BankAccount::operator=(const BankAccount& other) {
    if (this == &other) return *this;

    delete[] accountHolderName; // free existing memory

    accountNumber = other.accountNumber;
    balance = other.balance;
    accountHolderName = new char[strlen(other.accountHolderName) +1];
    strcpy(accountHolderName, other.accountHolderName);

    return *this;
}

// Deposit Operator +=
BankAccount& BankAccount::operator+=(double amount) {
    if (amount > 0) {
        balance += amount;
    }
    return *this;
}

// Withdraw Operator -=
BankAccount& BankAccount::operator-=(double amount) {
    if (amount > 0 && balance >= amount) {
        balance -= amount;
    } else {
        cout << "Insufficient funds or invalid amount.\n";
    }
    return *this;
}
//Comparison Operators
bool BankAccount::operator==(const BankAccount& other) const {
    return accountNumber == other.accountNumber;
}

bool BankAccount::operator<(const BankAccount& other) const {
    return balance < other.balance;
}

bool BankAccount::operator>(const BankAccount& other) const {
    return balance > other.balance;
}

// Static: Print Account
void BankAccount::printAccount(const BankAccount &account) {
    cout << "Account #: " << account.accountNumber
         << " | Holder: " << account.accountHolderName
         << " | Balance: " << account.balance << endl;
}

//Static: Create from Input
BankAccount BankAccount::createAccountFromInput() {
    int id;
    string name;
    double bal;

    cout << "Enter account number: ";
    cin >> id;
    cin.ignore();
    cout << "Enter holder name: ";
    getline(cin, name);
    cout << "Enter balance: ";
    cin >> bal;
    cin.ignore(1000, '\n');

    return BankAccount(id, name, bal);
}
