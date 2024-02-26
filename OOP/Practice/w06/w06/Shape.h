#pragma once
#include <iostream>

using namespace std;
class Point {
private:
	double x;
	double y;
public:
	Point();
	double getX() const;
	double getY() const;
	void setX(double);
	void setY(double);
	Point& operator= (const Point&);
	friend istream& operator>>(istream& is, Point&);
	friend ostream& operator<<(ostream& os, const Point&);
};

// Lop doi tuong hinh ve tong quat 'Shape'
class Shape {
public:
	// Constructors
	Shape() {}
	~Shape(){}
	/* Se cai dat lai trong tung lop dan xuat */
	virtual Shape* Clone() = 0;
	virtual bool IsSelectedPoint(Point p) = 0;
	virtual float dienTich() = 0;
	virtual void print() = 0;
	virtual void input() = 0;
	// others
};

