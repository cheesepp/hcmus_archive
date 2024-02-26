#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;

class Ngay {
private:
	string ngay;
	string thang;
	string nam;
public:
	string getNgay();
	string getThang();
	string getNam();
	void setNgay(string);
	void setThang(string);
	void setNam(string);
	Ngay& operator= (const Ngay&);
	friend istream& operator>> (istream&, Ngay&);
	friend ostream& operator<< (ostream&, const Ngay&);
};

string Ngay::getNgay() {
	return ngay;
}

string Ngay::getThang() {
	return thang;
}
string Ngay::getNam() {
	return nam;
}

void Ngay::setNgay(string _ngay) {
	ngay = _ngay;
}
void Ngay::setThang(string _thang) {
	thang = _thang;
}
void Ngay::setNam(string _nam) {
	nam = _nam;
}

Ngay& Ngay::operator=(const Ngay& ngay) {
	this->ngay = ngay.ngay;
	this->thang = ngay.thang;
	this->nam = ngay.nam;;

	return *this;
}

istream& operator>>(istream& in, Ngay& x) {

	in >> x.ngay >> x.nam >> x.thang;
	return in;
}

ostream& operator<<(ostream& out, const Ngay& x) {

	out << x.ngay << "/" << x.thang << "/" << x.nam;
	return out;
}

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
#endif // !PERSON_H
