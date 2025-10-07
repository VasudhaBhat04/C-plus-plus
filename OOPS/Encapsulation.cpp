/*Encapsulation is wrapping up of data & member functions in a single unit called class.
Encapsulation limits direct access to certain of the object's parts, enabling management and data security.
Data hiding --> sensitive info. make it private
Access Modifiers 
Private:data & methods are accessible inside class(default)
Public:data & methods accessible to everyone.
Protected:data & methods accessible inside class & to its derived class.

setter -- set values of private attributes.
getter -- get values of private attributes.
*/

/*Constructor-->Special method invoked automatically at the time of onject creation.
Used for intialization(defaultly initiated by the computer)
.Same name as class
.Doesn't have a return type
.Only called once(automatically)at the time of object creation.
.Memory allocation happens when constructor is called.
Types 
|--->Non-parameterized
|--->Parameterized
|--->Copy constructor
*/
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    //  Private variables (cannot be accessed directly outside class)
    string accountHolder;
    double balance;

public:
    //  Constructor
    BankAccount(string name, double initialBalance) {
        accountHolder = name;
        balance = initialBalance;
    }

   //  Setter
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    //  Setter
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Invalid withdrawal!" << endl;
        }
    }

    //  Getter (safe way to access private data)
    double getBalance() {
        return balance;
    }

    string getAccountHolder() {
        return accountHolder;
    }
};

int main() {
    // Create an object with encapsulation
    BankAccount acc("SpongeBob", 5000.0);

    cout << "Account Holder: " << acc.getAccountHolder() << endl;
    cout << "Initial Balance: " << acc.getBalance() << endl;

    acc.deposit(2000);  // increases balance
    acc.withdraw(1000); // decreases balance

    cout << "Final Balance: " << acc.getBalance() << endl;

    //  Direct access not allowed
    // acc.balance = 999999; // ERROR (balance is private)

    return 0;
}
