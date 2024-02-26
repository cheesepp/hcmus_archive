#include <iostream>
#include <cassert>
using namespace std;

class Person {
private:
    string name;
    string address;
public:
    Person(string, string);
    string getName() const;
    void setName(string);
    string getAddress() const;
    void setAddress(string);
    virtual void display() = 0;
};

Person::Person(string _name, string _address) {
    name = name;
    address = _address;
}

string Person::getName() const {
    return name;
}

void Person::setName(string name) {
    this->name = name;
}

string Person::getAddress() const {
    return address;
}

void Person::setAddress(string addr) {
    this->address = addr;
}