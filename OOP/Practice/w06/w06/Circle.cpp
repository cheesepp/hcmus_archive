#include "Circle.h"

Circle::Circle() {
	C.setX(0);
	C.setY(0);
	R = 0;
}

Circle::Circle(const Circle& c) {
	C = c.C;
	R = c.R;
}

Circle::~Circle() {}

bool Circle::IsSelectedPoint(Point p) {
	double distance = sqrt((p.getX() - C.getX()) * (p.getX() - C.getX()) + (p.getY() - C.getY()) * (p.getY() - C.getY()));
	return distance <= R;
}

Shape* Circle::Clone() {
	return new Circle(*this);
}

void Circle::input() {
	cout << "Nhap toa do: \n";
	cin >> C;
	cout << "Nhap ban kinh: ";
	cin >> R;
}

void Circle::print() {
	cout << "\n======== HINH TRON ========\n";
	cout << "Toa do: ";
	cout << C << endl;
	cout << "Ban kinh: ";
	cout << R << endl;
}

float Circle::dienTich() {
	return R * R * 3.14;
}
