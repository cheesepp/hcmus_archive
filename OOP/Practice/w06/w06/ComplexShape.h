#pragma once
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
// Lớp ComplexShape
class ComplexShape : public Shape {
protected:
	// Các hình vẽ thành phần: Circle, rectangle, ...
	int sz; //Number of shapes
	Shape** Children; //Array of <Shape*>
public:
	// Constructors
	ComplexShape();
	ComplexShape(const ComplexShape& c);
	// Destructor
	~ComplexShape();
	bool IsSelectedPoint(Point);
	Shape* Clone();
	void input();
	void print();
	int circle_Num();
	int rectangle_Num();
	float dienTich();
	//others
};

