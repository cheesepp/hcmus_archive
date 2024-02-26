#include "DaThuc.h"

DaThuc::DaThuc() {
	daThuc = NULL;
	n = 0;
}

DaThuc::DaThuc(int size) {

	daThuc = new DonThuc[size + 1];
	n = size;
	for (int i = 0; i <= n; i++) {
		daThuc[i].setterBac(i);
		daThuc[i].setterHeso(0);
	}
}

void DaThuc::nhap() {
	cout << "Nhap so luong da thuc (tinh tu 0 -> n): ";
	int m = 0;
	cin >> m;
	vector<DonThuc> temp(m + 1);
	for (int i = 0; i <= m; i++) {
		cout << "Nhap don thuc " << i << ":" << endl;
		temp[i].nhap();
	}

	int maxBac = 0;
	for (int i = 0; i <= n; i++) {
		if (maxBac < temp[i].getterBac()) {
			maxBac = temp[i].getterBac();
		}
	}

	daThuc = new DonThuc[maxBac + 1];
	n = maxBac;
	for (int i = 0; i <= n; i++) {
		daThuc[i].setterBac(i);
		daThuc[i].setterHeso(0);
	}



	for (int i = 0; i <= m; i++) {
		daThuc[temp[i].getterBac()] = daThuc[temp[i].getterBac()] + temp[i];
	}

}

void DaThuc::xuat() const {
	for (int i = 0; i <= n; i++) {
		if (daThuc[i].getterHeso() != 0)
			daThuc[i].xuat();
		if (i != n && daThuc[i].getterHeso() != 0)
			cout << " + ";

	}
}

DaThuc& DaThuc::operator= (const DaThuc& b) {


	n = b.n;
	daThuc = new DonThuc[n + 1];
	for (int i = 0; i <= b.n; i++) {
		daThuc[i] = b.daThuc[i];
	}
	return *this;
}

float DaThuc::tinhDaThuc(float x) {
	double res = 0;
	for (int i = 0; i <= n; i++) {
		res += daThuc[i].tinhGiaTri(x);
	}
	return res;
}

DaThuc DaThuc::congDaThuc(const DaThuc& b) {
	DaThuc res(n + b.n);
	int i = 0, j = 0, k = 0;
	while (i <= n && j <= b.n) {
		if (daThuc[i].getterBac() == b.daThuc[j].getterBac()) {
			res.daThuc[k++] = daThuc[i++] + b.daThuc[j++];
		}
		else if (daThuc[i].getterBac() > b.daThuc[j].getterBac()) {
			res.daThuc[k++] = daThuc[i++];
		}
		else {
			res.daThuc[k++] = b.daThuc[j++];
		}
	}
	while (i <= n) {
		res.daThuc[k++] = daThuc[i++];
	}
	while (j <= b.n) {
		res.daThuc[k++] = b.daThuc[j++];
	}
	return res;
}

DaThuc DaThuc::truDaThuc(const DaThuc& b) {
	DaThuc res(n + b.n);
	int i = 0, j = 0, k = 0;
	while (i <= n && j <= b.n) {
		if (daThuc[i].getterBac() == b.daThuc[j].getterBac()) {
			res.daThuc[k++] = daThuc[i++] - b.daThuc[j++];
		}
		else if (daThuc[i].getterBac() > b.daThuc[j].getterBac()) {
			res.daThuc[k++] = daThuc[i++];
		}
		else {
			res.daThuc[k++] = b.daThuc[j++] * (DonThuc(-1, 0));
		}
	}
	while (i <= n) {
		res.daThuc[k++] = daThuc[i++];
	}
	while (j <= b.n) {
		res.daThuc[k++] = b.daThuc[j++] * (DonThuc(-1, 0));
	}
	return res;
}

DaThuc DaThuc::nhanDaThuc(const DaThuc& b) {
	DaThuc res(n + b.n);

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= b.n; j++) {
			DonThuc temp = daThuc[i] * b.daThuc[j];
			res.daThuc[i + j] = res.daThuc[i + j] + temp;
			res.daThuc[i + j].setterBac(i + j);
		}
	}
	return res;
}

void DaThuc::reset() {
	for (int i = 0; i <= n; i++) {
		daThuc[i] = DonThuc(0, i);
	}
}

DaThuc DaThuc::chiaDaThuc(const DaThuc& b) {
	DaThuc res(n - b.n);
	int thisMaxBac = n;
	DaThuc tam = *this;
	DaThuc kqTemp(n - b.n);

	while (thisMaxBac >= b.n) {

		DonThuc temp = tam.daThuc[thisMaxBac] / b.daThuc[b.n];
		res.daThuc[temp.getterBac()] = temp;
		kqTemp.daThuc[temp.getterBac()] = temp;
		DaThuc tempDT = kqTemp.nhanDaThuc(b);
		tam = tam.truDaThuc(tempDT);
		kqTemp.reset();
		int max = 0;
		for (int i = 0; i <= thisMaxBac; i++) {
			if (max < tam.daThuc[i].getterBac() && (tam.daThuc[i].getterHeso() != 0))
			{
				max = tam.daThuc[i].getterBac();
			}
		}
		thisMaxBac = max;
	}

	return res;
}

DonThuc* DaThuc::getterDaThuc() {
	return daThuc;
}

DaThuc::~DaThuc() {
	delete[] daThuc;
}