#ifndef Person_HEADER
#define Person_HEADER
#include <iostream>
#include <string>
using namespace std;

class Date {
private:
	int D;
	int M;
	int Y;
public:
	Date();
	friend istream& operator>> (istream& in, Date& d);
	friend ostream& operator<< (ostream& out, Date d);

};

Date::Date() {
	D = Y = M = 0;
}
istream& operator>> (istream& in, Date& d) {
	cout << "Enter the day: ";
	in >> d.D;
	cout << "Enter the month: ";
	in >> d.M;
	cout << "Enter the year: ";
	in >> d.Y;
	return in;
}
ostream& operator<< (ostream& out, Date d) {
	out << d.D << "/" << d.M << "/" << d.Y;
	return out;
}
class Person {
protected:
	string Name;
	Date date;
public:
	Person();
	friend istream& operator>> (istream& in, Person& p);
	friend ostream& operator<< (ostream& out, const Person& p);
	virtual float salary() = 0;

};



Person::Person() {
	Name = "";
}
istream& operator>> (istream& in, Person& p) {
	cout << "Enter name: ";
	getline(in, p.Name, '\n');
	cout << "Enter day of birth." << endl;
	in >> p.date;
	return in;
}

ostream& operator<< (ostream& out, const Person& p) {
	out << p.Name << ", " << p.date;
	return out;
}

#endif // !1
