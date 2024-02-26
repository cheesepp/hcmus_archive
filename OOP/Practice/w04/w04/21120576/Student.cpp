#include "student.h"

Student::Student() {
	gpa = 0;
}

// Parameter constructor
// Person(id), thua ke tu lop Person
Student::Student(long id, double gp)
	: Person(id), //call constructor of Person class
	gpa(gp)
{
	assert(gpa >= 0.0 && gpa <= 10.0);
}

Student::Student(const Student& student): Person(student) {
	gpa = student.gpa;
}

Student::~Student() {
	gpa = 0;
}

double Student::getGpa() const {
	return gpa;
}

void Student::setGpa(double gpa) {
	this->gpa = gpa;
}

void Student::input() {
	Person::input();
	cout << "Nhap GPA: ";
	cin >> gpa;
}

void Student::print() {
	Person::print();
	cout << "GPA: " << gpa << endl;
}

Student& Student::operator= (const Student& std) {
	this->setId(std.getId());
	//Person::operator=(std);
	gpa = std.gpa;

	return *this;
}	


