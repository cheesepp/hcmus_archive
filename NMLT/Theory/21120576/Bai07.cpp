#include <iostream>
using namespace std;

int main() {

	int popA, popB;
	float grA, grB;
	
	do {
		cout << "Nhap dan so va toc do tang dan so cua thi tran A: ";
		cin >> popA >> grA;
		cout << "Nhap dan so va toc do tang dan so cua thi tran B: ";
		cin >> popB >> grB;
	} while (popA <= 0 || popB < 0|| grA < 0.0 || grB < 0.0);
	
	int year = (popB - popA) / (grA - grB);

	if (year >= 0) {
		cout << "So nam can thiet de dan so thi tran A bang dan so thi tran B: " << year;
	}
	else {
		cout << "So dan thi tran A khong gio bang so dan thi tran B";
	}

	return 0;
}