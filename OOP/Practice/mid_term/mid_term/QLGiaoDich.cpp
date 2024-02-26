#include "QLGiaoDich.h"

QLGiaoDich::QLGiaoDich()
{
	capacity = 100;
	sz = 0;
	list = new GiaoDich * [capacity];
	for (int i = 0; i < capacity; i++) {
		list[i] = nullptr;
	}
}

QLGiaoDich::QLGiaoDich(int cap)
{
	capacity = cap;
	sz = 0;
	list = new GiaoDich * [capacity];
	for (int i = 0; i < capacity; i++) {
		list[i] = nullptr;
	}
}

QLGiaoDich::QLGiaoDich(const QLGiaoDich& other)
{
	capacity = other.capacity;
	sz = other.sz;
	list = new GiaoDich * [capacity];
	for (int i = 0; i < capacity; i++) {
		list[i] = nullptr;
	}
	for (int i = 0; i < sz; i++) {
		list[i] = other.list[i];
	}
}

void QLGiaoDich::nhap()
{
	cout << "Nhap so luong giao dich: ";
	cin >> sz;
	int opt;
	for (int i = 0; i < sz; i++) {
	do {
		cout << "1. Giao dich tien te: \n";
		cout << "2. Giao dich vang: \n";
		cout << "Vui long nhap: ";
		cin >> opt;
		if (opt == 1) {
			list[i] = new GDTienTe();
			list[i]->nhap();
			
		}
		if (opt == 2) {
			list[i] = new GDVang();
			list[i]->nhap();
		}
	} while (opt != 1 && opt != 2);
		}
}

void QLGiaoDich::xuat()
{
	for (int i = 0; i < sz; i++) {
		list[i]->xuat();
	}
}

void QLGiaoDich::tongSoLuong()
{
	double tongSLGDV = 0;
	double tongSLGDTT = 0;
	for (int i = 0; i < sz; i++) {
		if (dynamic_cast<GDVang*>(list[i]) != nullptr) {
			tongSLGDV += list[i]->getSoLuong();
		}
		else if (dynamic_cast<GDTienTe*>(list[i]) != nullptr){
			tongSLGDTT += list[i]->getSoLuong();
		}
	}

	cout << "Tong so luong giao dich vang: " << tongSLGDV << endl;
	cout << "Tong so luong giao dich tien te: " << tongSLGDTT << endl;
}

void QLGiaoDich::maxGDTienTe()
{

	double maxUSD = 0;
	GiaoDich* usd = nullptr;
	double maxVND = 0;
	GiaoDich* vnd = nullptr;
	double maxEUR = 0;
	GiaoDich* eur = nullptr;
	for (int i = 0; i < sz; i++) {
		if (dynamic_cast<GDTienTe*>(list[i]) != nullptr) {
			if (static_cast<GDTienTe*>(list[i])->getLoaiTT() == "usd") {
				if (maxUSD < list[i]->getDonGia()) {
					maxUSD = list[i]->getDonGia();
					usd = list[i];
				}
			}
			else if (static_cast<GDTienTe*>(list[i])->getLoaiTT() == "eur") {
				if (maxEUR < list[i]->getDonGia()) {
					maxEUR = list[i]->getDonGia();
					eur = list[i];
				}
			}
			else {
				if (maxVND < list[i]->getDonGia()) {
					maxVND = list[i]->getDonGia();
					vnd = list[i];
				}
			}
		}
	}

	cout << "\n======= GIAO DICH TIEN TE CAO NHAT THEO TUNG LOAI TIEN =======\n";
	usd->xuat();
	vnd->xuat();
	eur->xuat();
	
}

void QLGiaoDich::GDT1N2021()
{
	for (int i = 0; i < sz; i++) {
		if (list[i]->getNgay().getThang() == 1 && list[i]->getNgay().getNam() == 2021) {
			list[i]->xuat();
		}
	}
}


