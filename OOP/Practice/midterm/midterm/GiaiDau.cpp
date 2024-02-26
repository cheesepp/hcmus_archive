#include "DoiBong.cpp"
#include <vector>
class GiaiDau {
private:
	char* tenGiai;
	int muaGiai;
	vector<DoiBong> danhSach;
public:

	GiaiDau() {
		tenGiai = new char[100];
		muaGiai = 0;

	}

	GiaiDau(char* ten, int mua) {
		tenGiai = new char[100];
		strcpy(tenGiai, ten);
		muaGiai = mua;
	}

	/*~GiaiDau() {
		delete[]tenGiai;
	}*/

	void input() {
		cout << "Nhap so luong doi bong: ";
		int size;
		cin >> size;
		cout << "Nhap danh sach doi bong: ";
		for (int i = 0; i < size; i++) {
			DoiBong db;
			db.input();
			danhSach.push_back(db);
		}
	}

	GiaiDau(const GiaiDau& other) {
		strcpy(tenGiai, other.tenGiai);
		muaGiai = other.muaGiai;
		danhSach = other.danhSach;
	}

	void themDoiBong() {
		DoiBong db;
		db.input();
		danhSach.push_back(db);

	}

	void bangXepHang() {
		cout << "\n================= BANG XEP HANG " << tenGiai << " MUA GIAI THU " << muaGiai << "==================\n";
		for (int i = 0; i < danhSach.size(); i++) {
			for (int j = i + 1; j < danhSach.size(); j++) {
				if (danhSach[i].tinhDiem() < danhSach[j].tinhDiem()) {
					DoiBong temp( danhSach[i]);
					danhSach[i] = danhSach[j];
					danhSach[j] = temp;
				}
				else if (danhSach[i].tinhDiem() == danhSach[j].tinhDiem() && danhSach[i].hieuSo() < danhSach[j].hieuSo()) {
					DoiBong temp(danhSach[i]);
					danhSach[i] = danhSach[j];
					danhSach[j] = temp;
				}
			}
		}

		for (int i = 0; i < danhSach.size(); i++) {
			cout << "Hang " << i + 1 << ": \n";
			danhSach[i].print();
		}
	}

	GiaiDau& operator=(const GiaiDau& other) {
		strcpy(tenGiai, other.tenGiai);
		muaGiai = other.muaGiai;
		danhSach = other.danhSach;

		return *this;
	}
};