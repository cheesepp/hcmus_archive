#include "Date.h"

Date::Date()
{
	_day = 0;
	_month = 0;
	_year = 0;
}

Date::Date(int day, int month, int year) {
	this->_day = day;
	this->_month = month;
	this->_year = year;
}

Date::Date(const Date& d) {
	this->_day = d._day;
	this->_month = d._month;
	this->_year = d._year;
}

void Date::setDay(int day)
{
	this->_day = day;
}

void Date::setMonth(int month) {
	this->_month = month;
}

void Date::setYear(int year) {
	this->_year = year;
}

int Date::getDay() {
	return _day;
}

int Date::getMonth() {
	return _month;
}

int Date::getYear() {
	return _year;
}

vector<int> Date::getDate() {
	vector<int> _date;
	_date.push_back(_day);
	_date.push_back(_month);
	_date.push_back(_year);
	return _date;
}

istream& operator>>(istream& is, Date& d)
{

	cout << "\nInput the day: "; is >> d._day;
	cout << "Input the month: "; is >> d._month;
	cout << "Input the year: "; is >> d._year;
	return is;
}

ostream& operator<<(ostream& os, const Date& d)
{
	os << d._day << "/" << d._month << "/" << d._year;
	return os;
}

Date Date::operator=(const Date& date) {
	_day = date._day;
	_month = date._month;
	_year = date._year;

	return *this;
}


