//
// Created by angel on 3/2/2026.
//

#ifndef CLION_PROJECTS_BANKACCOUNT_H
#define CLION_PROJECTS_BANKACCOUNT_H

#include <string>

class BankAccount {
private:
    int  accountNumber;
    char* accountHolderName; // using dynamic memory for the name
    double balance;

public:
    // constructor
    BankAccount(int accNum, const std::string& name, double bal);

    // --- RULE OF THREE ---
    ~BankAccount(); // destructor
    BankAccount(const BankAccount& other); // copy constructor
    BankAccount& operator=(const BankAccount& other); // copy assignment

    // --- OVERLOADED OPERATORS ---
    BankAccount& operator +=(double amount); // deposit
    BankAccount& operator -=(double amount); // withdrawal
    bool operator==(const BankAccount& other) const;
    bool operator<(const BankAccount& other) const;
    bool operator>(const BankAccount& other) const;

    // --- STATIC UTILITY FUNCTIONS ---
    static void printAccount(const BankAccount& account);
    static BankAccount createAccountFromInput();

    // -- GETTERS ---
    double getBalance() const { return balance; }
};

#endif //CLION_PROJECTS_BANKACCOUNT_H