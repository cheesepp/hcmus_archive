#include "person.h"

Person::Person() {
	identity = 100000001;
}
// Parameter constructor
Person::Person(long id)
	: identity(id)
{
	
	assert(identity >= 100000000 && identity <= 999999999);
}

Person::~Person() {
	identity = 0;
}

Person::Person(const Person& person) {
	identity = person.identity;
}

long Person::getId() const {
	return identity;
}

void Person::setId(long id) {
	identity = id;
}

void Person::input() {
	cout << "Nhap ID: ";
	cin >> identity;
}

void Person::print() {
	cout << "ID: " << identity << endl;
}

Person& Person::operator= (const Person& person) {
	this->identity = person.identity;
	return *this;
}
