#include "SpaceCraft.h"

SpaceCraft::SpaceCraft()
{
	cosparID = "";
	name = "";
	mission = "";
	speed = 0;
	launchDate;
}

SpaceCraft::SpaceCraft(string _cosparID, string _name, string _mission, float _speed, Date _launchDate)
{
	cosparID = _cosparID;
	name = _name;
	mission = _mission;
	speed = _speed;
	launchDate = _launchDate;
}

void SpaceCraft::input()
{
	cout << "Nhap ma tau: ";
	cin >> cosparID;
	cout << "Nhap ten tau: ";
	cin >> name;
	cout << "Nhap ten nhiem vu: ";
	cin >> mission;
	cout << "Nhap toc do: ";
	cin >> speed;
	cout << "Nhap ngay phong: ";
	cin >> launchDate;
}

void SpaceCraft::output()
{
	cout << "ID: " << cosparID << endl;
	cout << "Name: " << name << endl;
	cout << "Mission: " << mission << endl;
	cout << "Speed: " << speed << endl;
	cout << "Launch Date: " << launchDate << endl;
}

Date::Date()
{
	day = 0;
	month = 0;
	year;
}

Date::Date(int _d, int _m, int _y)
{
	day = 0;
	month = 0;
	year = 0;
}

int Date::getDay() const
{
	return day;
}

int Date::getMonth() const
{
	return month;
}

int Date::getYear() const
{
	return year;
}

istream& operator>>(istream& in, Date& date)
{
	in >> date.day >> date.month >> date.year;
	return in;
}

ostream& operator<<(ostream& out, Date& date)
{
	out << date.day << "/" << date.month << "/" << date.year;
	return out;
}
