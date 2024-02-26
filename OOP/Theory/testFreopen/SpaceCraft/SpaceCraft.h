#pragma once
#include <iostream>
#include <string>
using namespace std;

class Date {
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(int _d, int _m, int _y);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	friend istream& operator>>(istream& in, Date& date);
	friend ostream& operator<<(ostream& out, Date& date);
};
class SpaceCraft
{
protected:
	string cosparID;
	string name;
	string mission;
	float speed;
	Date launchDate;
public:
	SpaceCraft();
	SpaceCraft(string _cosparID, string _name, string _mission, float _speed, Date _launchDate);
	virtual void input();
	virtual void output();
};

