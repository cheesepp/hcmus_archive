#include "Person.h"
#pragma once
class Employee : public Person
{
private:
	string Corp;
	int Day;
public:
	Employee();
	friend istream& operator>> (istream& in, Employee& e);
	friend ostream& operator<< (ostream& out, Employee e);
	float salary();

};
Employee::Employee() :Person() {
	Corp = "";
	Day = 0;
}
istream& operator>> (istream& in, Employee& e) {
	Person* p = &e;
	in >> *p;
	in.ignore(1);
	cout << "Enter corp: ";
	getline(in, e.Corp, '\n');
	cout << "Enter day: ";
	in >> e.Day;
	return in;
}
ostream& operator<< (ostream& out, Employee e) {
	Person* p = &e;
	out << *p;
	out << ", " << e.Corp << ", " << e.Day << endl;
	return out;
}

float Employee::salary() {
	return 200000 * Day;
}


