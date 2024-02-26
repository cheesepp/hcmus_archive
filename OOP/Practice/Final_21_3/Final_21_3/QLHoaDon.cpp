#include "QLHoaDon.h"

QLHoaDon::QLHoaDon()
{
	cap = 100;
	size = 0;
	listHD = new KhachHang * [cap];
}

QLHoaDon::~QLHoaDon()
{
	delete[] listHD;
}

void QLHoaDon::inputList()
{
	cout << "Nhap so luong khach hang: ";
	cin >> size;
	for (int i = 0; i < size; i++) {
		int opt;
		do {
			cout << "Nhap 1 trong 2 loai KH sau:\n";
			cout << "  1: Khach hang Viet Nam\n";
			cout << "  2: Khach hang nuoc ngoai\n";
			cout << "Vui long nhap: ";
			cin >> opt;
		} while (opt != 1 && opt != 2);
		
		if (opt == 1) {
			listHD[i] = new KHVietNam();
			listHD[i]->input();
		}
		else if (opt == 2) {
			listHD[i] = new KHNuocNgoai();
			listHD[i]->input();
		}
	}
}

void QLHoaDon::outputList()
{
	for (int i = 0; i < size; i++) {
		listHD[i]->output();
	}
}

void QLHoaDon::avgThanhTien()
{
	double tongKHVN = 0;
	double tongKHNN = 0;
	int soKHVN = 0;
	int soKHNN = 0;
	for (int i = 0; i < size; i++) {
		if (dynamic_cast<KHVietNam*>(listHD[i]) != nullptr) {
			tongKHVN += listHD[i]->thanhTien();
			soKHVN++;
		}
		else if (dynamic_cast<KHNuocNgoai*>(listHD[i]) != nullptr) {
			tongKHNN += listHD[i]->thanhTien();
			soKHNN++;
		}
	}

	tongKHVN = tongKHVN * 1.0 / soKHVN;
	tongKHNN = tongKHNN * 1.0 / soKHNN;

	cout << "Trung binh thanh tien giao dich nha: " << tongKHVN << endl;
	cout << "Trung binh thanh tien giao dich dat: " << tongKHNN << endl;
}

bool chuaCoDT(vector<int> listDT, int loaiDT) {
	for (int i = 0; i < listDT.size(); i++) {
		if (listDT[i] == loaiDT) {
			return false;
		}
	}
	return true;
}

void QLHoaDon::timHDLonNhatMoiDoiTuong()
{
	vector<int> listDT(0);
	vector<float> maxBill(0);
	int loaiDT = -1;
	double max = -INT_MAX * 1.0;
	for (int i = 0; i < size; i++) {
		if (dynamic_cast<KHVietNam*>(listHD[i]) != nullptr) {
			loaiDT = static_cast<KHVietNam*>(listHD[i])->getLoaiDT();
			if (chuaCoDT(listDT, loaiDT) && loaiDT > 0) {
				if (max < listHD[i]->thanhTien()) {
					max = listHD[i]->thanhTien();
				}
			}

		}
		if (chuaCoDT(listDT, loaiDT) && loaiDT > 0) {
			listDT.push_back(loaiDT);
			maxBill.push_back(max);
		}
		max = -INT_MAX * 1.0;
		loaiDT = -1;
	}


	for (int i = 0; i < listDT.size(); i++) {
		for (int j = 0; j < size; j++) {
			if (dynamic_cast<KHVietNam*>(listHD[i]) != nullptr) {
				if (static_cast<KHVietNam*>(listHD[j])->getLoaiDT() == listDT[i]) {
					if (maxBill[i] < listHD[j]->thanhTien()) {
						maxBill[i] = listHD[j]->thanhTien();
					}
				}
			}
		}
	}

	for (int i = 0; i < listDT.size(); i++) {
		if (listDT[i] == 1) {
			cout << "So tien lon nhat cua doi tuong sinh hoat la: " << maxBill[i] << endl;
		}
		
		if (listDT[i] == 2) {
			cout << "So tien lon nhat cua doi tuong kinh doanh la: " << maxBill[i] << endl;
		}
		
		if (listDT[i] == 3) {
			cout << "So tien lon nhat cua doi tuong san xuat la: " << maxBill[i] << endl;
		}
	}
}

int QLHoaDon::getSize()
{
	return size;
}

void QLHoaDon::setSize(int _size)
{
	size = _size;
}

void QLHoaDon::readFile(string filename)
{
	int count = 0;
	ifstream fin(filename, ios::binary);
	if (fin.is_open()) {
		fin.read(reinterpret_cast<char*>(&count), sizeof(int));
		size = count;
		for (int i = 0; i < count; i++) {
			int type = -1;
			fin.read(reinterpret_cast<char*>(&type), sizeof(int));
			if (type == 0) {
				listHD[i] = new KHVietNam();
				fin.read(reinterpret_cast<char*>(listHD[i]), sizeof(KHVietNam));
			}
			else if (type == 1) {
				listHD[i] = new KHNuocNgoai();
				fin.read(reinterpret_cast<char*>(listHD[i]), sizeof(KHNuocNgoai));
			}
		}
		cout << "Doc file thanh cong!\n";
	}
	else {
		cout << "Khong the mo file!\n";

	}
}

void QLHoaDon::KHCoSoDienNhoHon150(string filename)
{
	ofstream fout(filename, ios::binary);
	if (fout.is_open()) {
		int count = 0;
		for (int i = 0; i < size; i++) {
			if (listHD[i]->getSoLuong() < 150) {
				count++;
			}
		}
		fout.write(reinterpret_cast<const char*>(&count), sizeof(int));
		for (int i = 0; i < count; i++) {
			int type = -1;
			if (listHD[i]->getSoLuong() < 150) {
				if (dynamic_cast<KHVietNam*>(listHD[i]) != nullptr) {
					type = 0;
					fout.write(reinterpret_cast<const char*>(&type), sizeof(int));
					fout.write(reinterpret_cast<const char*>(listHD[i]), sizeof(KHVietNam));

				}
				else {
					type = 1;
					fout.write(reinterpret_cast<const char*>(&type), sizeof(int));
					fout.write(reinterpret_cast<const char*>(listHD[i]), sizeof(KHNuocNgoai));
				}
			}
		}
		cout << "Ghi file thanh cong!\n";
	}
	else {
	cout << "Khong the mo file!\n";

	}
}

void QLHoaDon::sapXepLoaiDT()
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (stol(listHD[i]->getMaKH()) > stol(listHD[j]->getMaKH())) {
				KhachHang* temp;
				temp = listHD[i];
				listHD[i] = listHD[j];
				listHD[j] = temp;
			}
		}
	}
}


void QLHoaDon::themKH(KhachHang* &p)
{

	int opt;
	do {
		cout << "Nhap 1 trong 2 loai KH sau:\n";
		cout << "  1: Khach hang Viet Nam\n";
		cout << "  2: Khach hang nuoc ngoai\n";
		cout << "Vui long nhap: ";
		cin >> opt;
	} while (opt != 1 && opt != 2);

	if (opt == 1) {
		p = new KHVietNam();
		p->input();
	}
	else if (opt == 2) {
		p = new KHNuocNgoai();
		p->input();
	}

	size = size + 1;
	int greaterIndex = -1;
	for (int i = 0; i < size - 1; i++) {
		if (stol(p->getMaKH()) >= stol(listHD[i]->getMaKH())) {

			greaterIndex = i - 1;
		}
	}

	for (int i = greaterIndex + 1; i < size - 1; i++) {
		listHD[i + 1] = listHD[i];
	}
	listHD[greaterIndex + 1] = p;
}