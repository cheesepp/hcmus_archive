#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Person.h"

class Employee : public Person {
private:
    int salary;
public:
    Employee(string, string, int);
    void display();
};

Employee::Employee(string name, string address, int _salary) : Person(name, address) {
    this->salary = _salary;
}

void Employee::display() {
    cout << "Name: " << Person::getName() << endl;
    cout << "Address: " << Person::getAddress() << endl;
    cout << "Salary: " << salary << endl;
}

#endif // !EMPLOYEE_H
