#include "Rectangle.h"

Rectangle::Rectangle() {
	X.setX(0);
	X.setY(0);
	W = 0;
	H = 0;
}

Rectangle::Rectangle(const Rectangle& c) {
	X = c.X;
	W = c.W;
	H = c.H;
}

Rectangle::~Rectangle() {}

bool Rectangle::IsSelectedPoint(Point p) {
	if (p.getX() >= X.getX() && p.getX() <= X.getX() + W && p.getY() >= X.getY() && p.getY() <= X.getY() + H)
		return true;
	return false;
}

Shape* Rectangle::Clone() {
	return new Rectangle(*this);
}

void Rectangle::input() {
	cout << "Nhap toa do: \n";
	cin >> X;
	cout << "Nhap chieu rong: ";
	cin >> W;
	cout << "Nhap chieu dai: ";
	cin >> H;
}

void Rectangle::print() {
	cout << "\n======== HINH CHU NHAT ========\n";
	cout << "Toa do: ";
	cout << X << endl;
	cout << "Chieu rong: ";
	cout << W << endl;
	cout << "Chieu dai: ";
	cout << H << endl;
}

float Rectangle::dienTich() {
	return H * W;
}