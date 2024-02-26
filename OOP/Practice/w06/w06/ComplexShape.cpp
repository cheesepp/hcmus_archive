#include "ComplexShape.h"

ComplexShape::ComplexShape() {
	sz = 0;
	Children = nullptr;
}

ComplexShape::ComplexShape(const ComplexShape& c) {
	sz = c.sz;
	
	Children = new Shape * [sz];
	for (int i = 0; i < sz; i++) {
		Children[i] = c.Children[i];
	}
}

bool ComplexShape::IsSelectedPoint(Point p) {
	for (int i = 0; i < sz; i++) {
		if (Children[i]->IsSelectedPoint(p)) {
			return true;
		}
	}
	return false;
}

Shape* ComplexShape::Clone() {

	return new ComplexShape(*this);
}

void ComplexShape::input() {
	cout << "Nhap so luong da giac: ";
	cin >> sz;
	Children = new Shape * [sz];
	for (int i = 0; i < sz; i++) {
		Children[i] = nullptr;
	}

	for (int i = 0; i < sz; i++) {

		int opt;
		cout << "\n============= NHAP DANH SACH CAC HINH =============\n";
		do {
		
			cout << "Chon 1 trong cac tuy chon sau: ";
			cout << "\n========================\n";
			cout << "||1. Hinh tron          ||\n";
			cout << "||2. Hinh chu nhat      ||\n";
			cout << "========================\n";
			cout << "Vui long chon: ";
			cin >> opt;
			if (opt != 1 && opt != 2) {
				cout << "Chi duoc chon 1 trong 2! Vui long nhap lai!\n";
			}
		} while (opt != 1 && opt != 2);

		if (opt == 1) {
			Children[i] = new Circle();
			Children[i]->input();
		}
		else {
			Children[i] = new Rectangle();
			Children[i]->input();
		}
	}

	
}

void ComplexShape::print() {
	cout << "\n=========== SO DA GIAC ============\n";
	for (int i = 0; i < sz; i++) {
		Children[i]->print();
	}
}

int ComplexShape::circle_Num() {
	int count = 0;
	for (int i = 0; i < sz; i++) {
		if (dynamic_cast<Circle*>(Children[i]) != nullptr) {
			count++;
		}
	}
	return count;
}

int ComplexShape::rectangle_Num() {
	int count = 0;
	for (int i = 0; i < sz; i++) {
		if (dynamic_cast<Rectangle*>(Children[i]) != nullptr) {
			count++;
		}
	}
	return count;
}

float ComplexShape::dienTich() {
	float tong = 0;
	for (int i = 0; i < sz; i++) {
		tong += Children[i]->dienTich();
	}
	return tong;
}
ComplexShape::~ComplexShape() {
	for (int i = 0; i < sz; i++) {
		delete Children[i];
	}
	delete[]Children;
 }
