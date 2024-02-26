#pragma once
#include "Shape.h"
// Lớp Circle
class Circle : public Shape {
protected:
	Point C;
	double R;
public:
	// Constructors
	Circle();
	Circle(const Circle&);
	~Circle();
	bool IsSelectedPoint(Point);
	Shape* Clone();
	void input();
	void print();
	float dienTich();
};

