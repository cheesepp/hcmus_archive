#include "QLEBook.h"

void QLEBook::readFile(string filename) {
	ifstream fin(filename);
	if (!fin) {
		cout << "Khong mo duoc file!";
		return;
	}
	cout << "Mo thanh cong!\n";
	while (!fin.eof()) {
		vector<string> temp;
		for (int i = 0; i < 7; i++) {
			string buff = "";
			getline(fin, buff, '\n');
			temp.push_back(buff);
		}
		CEBook ebook;
		ebook.setISBN(temp[0]);
		ebook.setTen(temp[1]);
		ebook.setTacGia(temp[2]);
		int ngay = stoi(temp[3].substr(0, temp[3].find_first_of('/')));
		int thang = stoi(temp[3].substr(temp[3].find_first_of('/') + 1, temp[3].find_last_of('/')));
		int nam = stoi(temp[3].substr(temp[3].find_last_of('/') + 1));
		CMyDate date(ngay, thang, nam);
		std::time_t t = std::time(0);   // get time now
		std::tm* now = std::localtime(&t);
		CMyDate curDate(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
		if (date > curDate) {
			cout << "Sach co ID " << temp[0] << " co ngay san xuat khong hop le!\n";
			continue;
		}
		ebook.setNgayXB(date);
		ebook.setTheLoai(temp[4]);
		ebook.setNhaXB(temp[5]);
		ebook.setGia((long double)stof(temp[6]));
		list.push_back(ebook);
	}

	fin.close();
}

void QLEBook::writeFile(string filename, int type) {
	ofstream fout(filename);
	if (!fout) {
		cout << "Khong mo duoc file!\n";
		return;
	}
	cout << "Mo file thanh cong!\n";
	if (type == 2) {
		fout << "Danh sach cac sach cac ebook co ma so cuoi la 730: " << endl;
		for (int i = 0; i < list.size(); i++) {
			fout << list[i].getISBN() << endl;
			fout << list[i].getTen() << endl;
			fout << list[i].getTacGia() << endl;
			fout << list[i].getNgayXB().getNgay() << "/" << list[i].getNgayXB().getThang() << "/" << list[i].getNgayXB().getNam() << endl;
			fout << list[i].getTheLoai() << endl;
			fout << list[i].getNhaXB() << endl;
			fout << list[i].getGia() << endl;
		}
	}
	else if (type == 1) {
		fout << "Danh sach cac ebook giam dan theo gia: " << endl;
		for (int i = 0; i < list.size(); i++) {
			fout << list[i].getISBN() << " " << list[i].getGia() << endl;
		}
	}
	else {
		fout << "Danh sach cac ebook tang dan theo ngay san xuat: " << endl;
		for (int i = 0; i < list.size(); i++) {
			fout << list[i].getISBN() << " " << list[i].getNgayXB().getNgay() << "/" << list[i].getNgayXB().getThang() << "/" << list[i].getNgayXB().getNam() << endl;
		}
	}

	fout.close();
}

void QLEBook::sapXepGiaSachGiamDan() {
	for (int i = 0; i < list.size(); i++) {
		for (int j = i + 1; j < list.size(); j++) {
			if (list[i] < list[j]) {
				CEBook temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
	}

	writeFile("SAPXEPTHEOGIA.txt", 1);
}


void QLEBook::thongKeISBN() {

	vector<CEBook> EBookFilter;
	for (int i = 0; i < list.size(); i++) {
		int j = list[i].getISBN().length() - 1;
		if (list[i].getISBN()[j] == '0' && list[i].getISBN()[j - 1] == '3' && list[i].getISBN()[j - 2] == '7') {
			EBookFilter.push_back(list[i]);
		}
	}

	writeFile("THONGKEISBN.txt", 2);

}

void QLEBook::sapXepSachTangTheoNgay() {
	for (int i = 0; i < list.size(); i++) {
		for (int j = i + 1; j < list.size(); j++) {
			if (list[i].getNgayXB() > list[j].getNgayXB()) {
				CEBook temp = list[j];
				list[j] = list[i];
				list[i] = temp;
			}
		}
	}

	writeFile("SAPXEPTHEONGAY.txt", 3);
}