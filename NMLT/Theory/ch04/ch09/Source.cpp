//#include <iostream>
//using namespace std;
//
//struct PhanSo {
//	int tu;
//	int mau;
//};
//
//void inputFraction(PhanSo a[], int &n) {
//	cout << "Nhap mang phan so: ";
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cout << "Nhap phan so " << i + 1 << ": ";
//		cin >> a[i].tu >> a[i].mau;
//	}
//}
//
//void printFraction(PhanSo p) {
//	cout << p.tu << "/" << p.mau << endl;
//}
//
//void outputFraction(PhanSo a[], int n) {
//	for (int i = 0; i < n; i++) {
//		printFraction(a[i]);
//	}
//}
//
//int UCLN(PhanSo p) {
//	while (p.tu != p.mau) {
//		if (p.tu > p.mau) {
//			p.tu = p.tu - p.mau;
//		}
//		else {
//			p.mau = p.mau - p.tu;
//		}
//	}
//
//	return p.tu;
//}
//
//void reduceFractions(PhanSo a[], int n) {
//	for (int i = 0; i < n; i++) {
//		int ucln = UCLN(a[i]);
//		a[i].tu /= ucln;
//		a[i].mau /= ucln;
//	}
//}
//
//void countNeg_PosFractions(PhanSo a[], int n) {
//	int countNe = 0;
//	int countPo = 0;
//	for (int i = 0; i < n; i++) {
//		if (a[i].tu * a[i].mau < 0) {
//			countNe++;
//		}
//		else {
//			countPo++;
//		}
//	}
//	cout << "So phan so am: " << countNe << endl;
//	cout << "So phan so duong: " << countPo << endl;
//}
//
//void findLar_SmaFraction(PhanSo a[], int n) {
//	PhanSo minF = a[0];
//	PhanSo maxF = a[0];
//	for (int i = 1; i < n; i++) {
//		if (minF.tu * 1.0 / minF.mau > a[i].tu * 1.0 / a[i].mau) {
//			minF = a[i];
//		}
//		if (maxF.tu * 1.0 / maxF.mau < a[i].tu * 1.0 / a[i].mau) {
//			maxF = a[i];
//		}
//	}
//	cout << "Phan so be nhat la: ";
//	printFraction(minF);
//	cout << "Phan so lon nhat la: ";
//	printFraction(maxF);
//
//}
//
//void swap(PhanSo& a, PhanSo& b) {
//	PhanSo temp = a;
//	a = b;
//	b = temp;
//}
//
//void sortAscending(PhanSo a[], int n) {
//	for (int i = 0; i < n; i++) {
//		for (int j = i + 1; j < n; j++) {
//			if (a[i].tu * 1.0 / a[i].mau > a[j].tu * 1.0 / a[j].mau) {
//				swap(a[i], a[j]);
//			}
//		}
//	}
//}
//
//
//int main() {
//
//	PhanSo a[100];
//	int n;
//	inputFraction(a, n);
//	outputFraction(a, n);
//	countNeg_PosFractions(a, n);
//	findLar_SmaFraction(a, n);
//	sortAscending(a, n);
//	outputFraction(a, n);
//	return 0;
//}