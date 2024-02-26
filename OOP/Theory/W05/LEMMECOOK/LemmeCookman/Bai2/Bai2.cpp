//#define _CRT_SECURE_NO_WARNINGS
//#include <string>
//#include <iostream>
//#include <vector>
//#include <sstream>
//using namespace std;
//
//class CauThu {
//protected:
//	string SoAo;
//	string ViTri;
//	int SucLuc;
//public:
//	string getSoAo();
//	string getViTri() {
//		return ViTri;
//	}
//	int getSucLuc() {
//		return SucLuc;
//	}
//	void setSoAo(string);
//
//	void Nhap();
//	void Xuat();
//};
//
//string CauThu::getSoAo() {
//	return SoAo;
//}
//void CauThu::Nhap() {
//	cin >> SoAo;
//}
//
//void CauThu::setSoAo(string soAo) {
//	SoAo = soAo;
//}
//
//void CauThu::Xuat() {
//	cout << SoAo << " " << ViTri << " " << SucLuc;
//}
//
//class CTDuBi : public CauThu {
//public:
//	void Nhap();
//	void Xuat();
//	void setSoAo(string);
//};
//
//void CTDuBi::setSoAo(string soAo) {
//	CauThu::setSoAo(soAo);
//}
//void CTDuBi::Nhap() {
//	//CauThu::Nhap();
//	string buffer;
//	int pos = 0;
//	getline(cin, buffer);
//	ViTri = "";
//	for (int i = 0; i < buffer.size(); ++i) {
//		if (buffer[i] >= '0' && buffer[i] <= '9') {
//			pos = i;
//			break;
//		}
//		ViTri += buffer[i];
//	}
//	for (int i = 0; i < ViTri.size() - 1; ++i) {
//		ViTri[i] = ViTri[i + 1];
//	}
//	ViTri.resize(ViTri.size() - 2);
//	buffer = buffer.substr(pos);
//	SucLuc = stoi(buffer);
//}
//void CTDuBi::Xuat() {
//	cout << SoAo << " " << ViTri << " " << SucLuc;
//
//}
//
//class CTThiDau : public CauThu {
//private:
//	int Chuyen;
//	int Sut;
//public:
//	void Nhap();
//	void Xuat();
//	void setSoAo(string);
//};
//
//void CTThiDau::setSoAo(string soAo) {
//	CauThu::setSoAo(soAo);
//}
//
//void CTThiDau::Nhap() {
//	//CauThu:Nhap();
//	string buffer;
//	int pos = 0;
//	getline(cin, buffer);
//	ViTri = "";
//	for (int i = 0; i < buffer.size(); ++i) {
//		if (buffer[i] >= '0' && buffer[i] <= '9') {
//			pos = i;
//			break;
//		}
//		ViTri += buffer[i];
//	}
//	for (int i = 0; i < ViTri.size() - 1; ++i) {
//		ViTri[i] = ViTri[i + 1];
//	}
//	ViTri.resize(ViTri.size() - 2);
//	buffer = buffer.substr(pos);
//	stringstream s(buffer);
//	s >> Chuyen;
//	s >> Sut;
//	s >> SucLuc;
//}
//
//void CTThiDau::Xuat() {
//	cout << SoAo << " " << ViTri;
//	cout << " " << Chuyen << " " << Sut << " " << SucLuc;
//}
//class MangCauThu {
//private:
//	vector <CTThiDau> lthiDau;
//	vector <CTDuBi> lduBi;
//	vector <CauThu> lcauThu;
//public:
//	void Nhap();
//	void Xuat();
//	void TopDoiHinh();
//};
//
//void MangCauThu::Nhap() {
//	int i = 0;
//	while (!cin.eof()) {
//		CauThu temp;
//		temp.Nhap();
//		string soAo = temp.getSoAo();
//		if (soAo[0] == 'D') {
//			CTDuBi t;
//			t.setSoAo(soAo);
//			t.Nhap();
//			lduBi.push_back(t);
//			lcauThu.push_back(t);
//			cout << "Doc xong cau thu " << ++i;
//		}
//		else if (soAo[0] == 'C') {
//			CTThiDau t;
//			t.setSoAo(soAo);
//			t.Nhap();
//			lthiDau.push_back(t);
//			lcauThu.push_back(t);
//			cout << "Doc xong cau thu " << ++i;
//		}
//	}
//	//a+b+c>!50
//}
//
//void MangCauThu::Xuat() {
//	for (CTDuBi c : lduBi) {
//		c.Xuat();
//		cout << endl;
//	}
//	for (CTThiDau c : lthiDau) {
//		c.Xuat();
//		cout << endl;
//	}
//
//}
//void MangCauThu::TopDoiHinh() {
//	vector <vector<CauThu>> list(3);
//	int soDoi = 1;
//	for (int i = 0; i < lcauThu.size() - 2; ++i) {
//		for (int j = i + 1; j < lcauThu.size() - 1; ++j) {
//			for (int k = j + 1; k < lcauThu.size(); k++) {
//				if (lcauThu[i].getSucLuc() + lcauThu[j].getSucLuc() + lcauThu[k].getSucLuc() > 150) {
//					cout << soDoi << endl;
//					if (lcauThu[i].getSoAo()[0] == 'D') {
//						lcauThu[i].setSoAo('C' + lcauThu[i].getSoAo().substr(1));
//					}
//					if (lcauThu[j].getSoAo()[0] == 'D') {
//						lcauThu[j].setSoAo('C' + lcauThu[j].getSoAo().substr(1));
//					}
//					if (lcauThu[k].getSoAo()[0] == 'D') {
//						lcauThu[k].setSoAo('C' + lcauThu[k].getSoAo().substr(1));
//					}
//				}
//			}
//		}
//	}
//}
//int main() {
//	freopen("INPUT.txt", "r", stdin);
//	MangCauThu lcauThu;
//	lcauThu.Nhap();
//	freopen("OUTPUT.txt", "w", stdout);
//	lcauThu.Xuat();
//
//}