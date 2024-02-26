#include "Person.h"
#pragma once

class Student : public Person {
private:
	string Class;
	float Math;
	float Phys;
	float Chem;
public:
	Student();
	friend istream& operator>>(istream& in, Student& s);
	friend ostream& operator<< (ostream& out, Student s);
	float salary();
};

Student::Student() : Person() {
	Class = "";
	Math = Phys = Chem = 0;
}
istream& operator>>(istream& in, Student& s) {
	Person* p = &s;
	in >> *p;
	in.ignore(1);
	cout << "Enter name of class: ";
	getline(in, s.Class, '\n');
	cout << "Enter Math mark: ";
	in >> s.Math;
	cout << "Enter Phys mark: ";
	in >> s.Phys;
	cout << "Enter Chem mark: ";
	in >> s.Chem;
	return in;
}
ostream& operator <<(ostream& out, Student s) {
	Person* p = &s;
	out << *p;
	out << ", " << s.Class << ", " << s.Math << ", " << s.Phys << ", " << s.Chem << endl;
	return out;
}

float Student::salary() {
	return 0;
}

