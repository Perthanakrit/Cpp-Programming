#include <iostream>
using namespace std;

class BankAccount
{
private:
    string name;
    string accountNumber;
    double balance;

public:
    BankAccount(std::string name, std::string accountNumber, double balance)
    {
        this->name = name;
        this->accountNumber = accountNumber;
        this->balance = balance;
    }
    void deposit(double amount)
    {
        balance += amount;
    }
    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
        }
        else
        {
            std::cout << "Insufficient balance" << std::endl;
        }
    }
    void display()
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Balance: " << balance << std::endl;
    }
};