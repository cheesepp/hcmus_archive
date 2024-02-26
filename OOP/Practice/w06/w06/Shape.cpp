#include "Shape.h"

Point::Point() {
	x = 0;
	y = 0;
}

double Point::getX() const {
	return x;
}

double Point::getY() const {
	return y;
}

void Point::setX(double _x) {
	x = _x;
}

void Point::setY(double _y) {
	y = _y;
}

Point& Point::operator=(const Point& p) {
	x = p.x;
	y = p.y;

	return *this;
}

istream& operator>>(istream& in, Point& p) {
	cout << "Nhap x: ";
	in >> p.x;
	cout << "Nhap y: ";
	in >> p.y;
	return in;
}

ostream& operator<<(ostream& os, const Point& p) {
	os << "(" << p.x << ", " << p.y << ") ";
	return os;
}
