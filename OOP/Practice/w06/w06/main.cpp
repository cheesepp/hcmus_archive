#include "ComplexShape.h"

int main() {

	ComplexShape cs;
	cs.input();
	cs.print();

	int numCir = cs.circle_Num();
	int numRec = cs.rectangle_Num();

	Point p;
	cout << "Tim hinh chua diem p: ";
	cin >> p;
	bool coChua = cs.IsSelectedPoint(p);
	if (coChua) {
		cout << "Da giac chua p\n";
	}
	else {
		cout << "Da giac khong chua p\n";
	}

	cout << "So hinh tron: " << numCir << endl;
	cout << "So hinh chu nhat: " << numRec << endl;

	Shape* s = cs.Clone();
	s->print();

	cout << endl << "Tong dien tich da giac: " << s->dienTich();
	return 0;
}