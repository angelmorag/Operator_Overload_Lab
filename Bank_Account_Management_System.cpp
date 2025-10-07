//Angel Mora Guttierez
//6-October-2025
//Operator Overloading Assignment
//MCSCI-272
//Professor Vaughn

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    // constructors
    BankAccount();
	BankAccount(string accNum, string accHolder, double initialBalance);

	// rule of three: copy constructor, copy assignment operator, destructor
    BankAccount(const BankAccount& other);
	BankAccount& operator=(const BankAccount& other);
	~BankAccount();

    // accessors
    string getAccountNumber() const;
    string getAccountHolderName() const;
    double getBalance() const;

    // mutator
    void setAccountHolderName(const string& name);
    
    // actions
    void deposit(double amount);
	void withdraw(double amount);
	void printAccountInfo() const;

    // operator overloads
    BankAccount operator+(const BankAccount& other) const;
	BankAccount operator-(const BankAccount& other) const;
	BankAccount& operator+=(double amount);
	BankAccount& operator-=(double amount);
	bool operator==(const BankAccount& other) const;
	bool operator<(const BankAccount& other) const;
	bool operator>(const BankAccount& other) const;

    //static utility functions
	static void printAccount(const BankAccount& account);
    static BankAccount createAccountFromInput();

    // friend function for printing
    friend ostream& operator<<(ostream& os, const BankAccount& account);
};

// default constructor
BankAccount::BankAccount() {
    accountNumber = "000000";
    accountHolderName = "Default Name";
    balance = 0.0;
}

// parameterized constructor
BankAccount::BankAccount(string accNum, string accHolder, double initialBalance){
    accountNumber = accNum;
    accountHolderName = accHolder;
    balance = (initialBalance >= 0) ? initialBalance : 0.0;
}

// rule of three
BankAccount::BankAccount(const BankAccount& other) {
	*this = other;
}

BankAccount& BankAccount::operator=(const BankAccount& other) {
    if (this != &other) {
        accountNumber = other.accountNumber;
        accountHolderName = other.accountHolderName;
        balance = other.balance;
    }
    return *this;
}
BankAccount::~BankAccount() {
    // No dynamic memory to free
}

// getters
string BankAccount::getAccountNumber() const {
    return accountNumber;
}

string BankAccount::getAccountHolderName() const {
    return accountHolderName;
}

double BankAccount::getBalance() const {
    return balance;
}

// setter
void BankAccount::setAccountHolderName(const string& name) {
    accountHolderName = name;
}

// deposit and withdraw methods
void BankAccount::deposit(double amount) {
    *this += amount; // using overloaded += operator
}
void BankAccount::withdraw(double amount) {
    *this -= amount; // using overloaded -= operator
}

// print account information
void BankAccount::printAccountInfo() const {
	cout << *this; // using overloaded << operator
}

// ----- Operator Overloading -----

// addition of balances of two accounts
BankAccount BankAccount::operator+(const BankAccount& other) const {
	BankAccount temp = *this;
	temp.balance += other.balance;
    return temp;
}

// subtraction of balances of two accounts
BankAccount BankAccount::operator-(const BankAccount& other) const {
    BankAccount temp = *this;
    if (temp.balance >= other.balance) {
        temp.balance -= other.balance;
    } else {
        cout << "Insufficient funds for subtraction!" << endl;
    }
    return temp;
}

// add amount to balance
BankAccount& BankAccount::operator+=(double amount) {
    if (amount > 0) {
        balance += amount;
    } else {
        cout << "Deposit amount must be positive!" << endl;
    }
    return *this;
}

// subtract amount from balance
BankAccount& BankAccount::operator-=(double amount) {
    if (amount > 0 && balance >= amount) {
        balance -= amount;
    } else {
        cout << "Insufficient funds or invalid withdrawal amount!" << endl;
    }
    return *this;
}

// compare two accounts based on account number
bool BankAccount::operator==(const BankAccount& other) const {
    return (accountNumber == other.accountNumber);
}

// compare two accounts based on balance
bool BankAccount::operator<(const BankAccount& other) const {
    return (balance < other.balance);
}
bool BankAccount::operator>(const BankAccount& other) const {
    return (balance > other.balance);
}

// friend function to print account details
ostream& operator<<(ostream& os, const BankAccount& account) {
    os << "Account Number: " << account.accountNumber << "\n";
    os << "Account Holder: " << account.accountHolderName << "\n";
    os << "Balance: $" << account.balance << "\n";
    return os;
}

// static utility functions
void BankAccount::printAccount(const BankAccount& account) {
    cout << account; // using overloaded << operator
}

BankAccount BankAccount::createAccountFromInput() {
    string accNum, accHolder;
    double initialBalance;
    cout << "Enter Account Number: ";
    cin >> accNum;
    cout << "Enter Account Holder Name: ";
    cin.ignore(); // To ignore the newline character left in the buffer
    getline(cin, accHolder);
    cout << "Enter Initial Balance: ";
    cin >> initialBalance;
    return BankAccount(accNum, accHolder, initialBalance);
}

// Menu Driven Interface
void displayMenu() {
    cout << "\nBank Account Management System\n";
    cout << "1. Create Account\n";
    cout << "2. View Accounts\n";
    cout << "3. Deposit\n";
    cout << "4. Withdraw\n";
    cout << "5. Combine First Two Accounts\n";
	cout << "6. Compare First Two Accounts\n";
    cout << "7. Exit\n";
    cout << "Choose an option: ";
}


int main() {
	vector<BankAccount> accounts; // vector to store multiple accounts
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: { // create account
            accounts.push_back(BankAccount::createAccountFromInput());
            cout << "Account created successfully!" << endl;
            break;
        }
        case 2: { // view accounts
            cout << "\nList of Accounts:\n";
            for (size_t i = 0; i < accounts.size(); ++i) {
                cout << i + 1 << ".\n";
                accounts[i].printAccountInfo();
            }
            break;
        }
        case 3: { // deposit
            int index;
            double amount;
            cout << "Enter account index: ";
            cin >> index;
            if (index >= 1 && index <= accounts.size()) {
                cout << "Enter amount to deposit: ";
                cin >> amount;
                accounts[index - 1] += amount;
            }
            else {
                cout << "Invalid account index!" << endl;
            }
            break;
        }
        case 4: { // withdraw
            int index;
            double amount;
            cout << "Enter account index: ";
            cin >> index;
            if (index > 0 && index <= accounts.size()) {
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                accounts[index - 1] -= amount;
            }
            else {
                cout << "Invalid account index!" << endl;
            }
            break;
        }
        case 5: { // combine first two accounts
            if (accounts.size() >= 2) {
                BankAccount combined = accounts[0] + accounts[1];
                cout << "Combined Account:\n";
				BankAccount::printAccount(combined);
            } else {
                cout << "Not enough accounts to combine!" << endl;
            }
            break;
		}
        case 6: { // compare first two accounts
            if (accounts.size() >= 2) {
                if (accounts[0] == accounts[1]) {
                    cout << "Account 1 < Account 2?" << (accounts[0] < accounts[1]) << endl;
                    cout << "Account 1 > Account 2?" << (accounts[0] > accounts[1]) << endl;
                    cout << "Account 1 == Account 2?" << (accounts[0] == accounts[1]) << endl;
                }
                else {
                    cout << "Need at least 2 accounts to compare!" << endl;
                }
            }
		case 7: // exit
            cout << "Exiting program." << endl;
            break;
		default: // invalid choice
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}