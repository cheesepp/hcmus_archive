#define _CRT_SECURE_NO_WARNINGS
#pragma once
#ifndef __DATE_H__
#include<iostream>
#include <string.h>
#include <string>
#include<vector>
using namespace std;

class Date {
private:
	int _day;
	int _month;
	int _year;

public:
	Date();
	Date(int day, int month, int year);
	Date(const Date& d);

	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);

	int getDay();
	int getMonth();
	int getYear();
	vector<int>getDate();

	friend istream& operator>>(istream& is, Date& d);
	friend ostream& operator<<(ostream& os, const Date& d);
	Date operator=(const Date&); 
};

#endif