//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <vector>
//#include <sstream>
//#include <string>
//using namespace std;
//
//class NhanVien {
//private:
//	string Phong;
//	string Ten;
//	float HeSoLuong;
//public:
//	void Nhap();
//	string getTen();
//	string getPhong();
//	float getHSLuong();
//};
//string NhanVien::getTen() {
//	return Ten;
//}
//string NhanVien::getPhong() {
//	return Phong;
//}
//float NhanVien::getHSLuong() {
//	return HeSoLuong;
//}
//void NhanVien::Nhap() {
//	cin >> Phong;
//	string temp;
//	getline(cin,temp,'\n');
//	string name = "";
//	int pos=0;
//	for (int i = 0; i < temp.size(); i++) {
//		if (temp[i] < '0' || temp[i]>'9')
//			name += temp[i];
//		else {
//			pos = i;
//			break;
//		}
//	}
//	HeSoLuong = stof(temp.substr(pos, temp.size()));
//}
//class MangNhanVien {
//private:
//	vector <NhanVien> list;
//	int LCB;
//public:
//	void Nhap();
//	int getLCB();
//	vector<NhanVien> getList();
//	void LuongCaoNhat(int&, string&);
//};
//vector<NhanVien> MangNhanVien::getList() {
//	return list;
//}
//int MangNhanVien::getLCB() {
//	return LCB;
//}
//void MangNhanVien::Nhap() {
//	cin >> LCB;
//	while(!cin.eof()) {
//		NhanVien temp;
//		temp.Nhap();
//		list.push_back(temp);
//	}
//}
//void MangNhanVien::LuongCaoNhat(int& Luong, string& phong) {
//	vector<string> lphong;
//	lphong.push_back(list[0].getPhong());
//	for (int i = 1; i < list.size(); ++i) {
//		bool repeat = false;
//		for (int j = i; j >= 0; --j) {
//			if (list[i].getPhong() == list[j].getPhong()) {
//				repeat = true;
//				break;
//			}
//		}
//		if (!repeat)
//			lphong.push_back(list[i].getPhong());
//	}
//	vector<int> lluong;
//	lluong.resize(lphong.size());
//	for (int i = 0; i < lluong.size(); ++i) {
//		int tong = 0;
//		for (int j = 0; j < list.size(); j++) {
//			if (lphong[i] == list[j].getPhong()) {
//				tong += list[j].getHSLuong() * LCB;
//			}
//		}
//		lluong.push_back(tong);
//	}
//	int max = lluong[0];
//	int pos = 0;
//	for (int i = 1; i < lluong.size(); ++i) {
//		if (lluong[i] > max) {
//			max = lluong[i];
//			pos = i;
//		}
//	}
//	Luong = max;
//	phong = lphong[pos];
//
//}
//int main() {
//
//	freopen("INPUT.TXT", "rt", stdin);
//	MangNhanVien m;
//	m.Nhap();
//	int luong;
//	string phong;
//	m.LuongCaoNhat(luong, phong);
//	freopen("OUTPUT.TXT", "wt", stdout);
//	cout << phong << " " << luong;
//	for (int i = 0; i < m.getList().size(); ++i) {
//		if (m.getList()[i].getPhong() == phong)
//			cout << m.getList()[i].getTen() << endl;
//	}
//}