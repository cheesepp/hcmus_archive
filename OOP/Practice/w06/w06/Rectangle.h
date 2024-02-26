#pragma once
#include "Shape.h"
// Lớp hình chu nhat
class Rectangle : public Shape {
protected:
	Point X;
	double W, H;
public:
	//Constructors
	Rectangle();
	Rectangle(const Rectangle&);
	~Rectangle();
	bool IsSelectedPoint(Point);
	Shape* Clone();
	void input();
	void print();
	float dienTich();
	// others
};

