#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"

class Customer : public Person {
private:
    int balance;
public:
    Customer(string, string, int);
    void display();
};

Customer::Customer(string name, string address, int _balance) : Person(name, address) {
    this->balance = _balance;
}

void Customer::display() {
    cout << "Name: " << Person::getName() << endl;
    cout << "Address: " << Person::getAddress() << endl;
    cout << "Balance: " << balance << endl;
}
#endif // !CUSTOMER_H
