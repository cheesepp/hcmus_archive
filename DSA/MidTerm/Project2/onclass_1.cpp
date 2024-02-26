//#include<iostream>
//#include<fstream>
//#include<vector>
//#include<string>
//using namespace std;
//
//class Ghe {
//private:
//	// T : thuong
//	// V : vip
//	// D : Doi
//	string type;
//
//public:
//	Ghe();
//	virtual void Nhap(int);
//	virtual void Xuat();
//	virtual void SetType(string a) {
//		type = a;
//	}
//	Ghe& operator=(const Ghe& a) {
//		type = a.type;
//		return *this;
//	}
//	virtual int Gia();
//	
//};
//
//Ghe::Ghe() {
//	type = "";
//}
//
//
//
//void Ghe::Xuat() {
//	if (type == "T"){
//		cout << "T";
//	}
//	else if (type == "V") {
//		cout << "V";
//	}
//	else if (type == "X") {
//		cout << "X";
//	}
//	else {
//		cout << "D";
//	}
//
//}
//
//class GheT :public Ghe{
//private:
//
//public:
//	virtual void Nhap();
//	virtual void Xuat();
//	virtual float GiaT() {
//		return 90;
//	}
//};
//
//void GheT::Nhap() {
//	
//}
//
//void GheT::Xuat() {
//
//}
//
//class GheV :public Ghe {
//private:
//
//public:
//	virtual void Nhap();
//	virtual void Xuat();
//	virtual float GiaV() {
//		return 120;
//	}
//};
//
//void GheV::Nhap() {
//
//}
//
//void GheV::Xuat() {
//
//}
//class GheD :public Ghe {
//private:
//
//public:
//	virtual void Nhap();
//	virtual void Xuat();
//	virtual float GiaD() {
//		return 200;
//	}
//};
//
//void GheD::Nhap() {
//
//}
//
//void GheD::Xuat() {
//
//}
//
//int Ghe::Gia() {
//	if (type == "T") {
//		GheT temp;
//		return temp.GiaT();
//	}
//	else if (type == "V") {
//		GheV temp;
//		return temp.GiaV();
//	}
//	if (type == "D") {
//		GheD temp;
//		return temp.GiaD();
//	}
//}
//
//void Ghe::Nhap(int t) {
//
//	if (t == 1) {
//		GheT temp;
//		*this = temp;
//		type = "T";
//	}
//	else if (t == 2) {
//		GheV temp;
//		*this = temp;
//		type = "V";
//	}
//	else {
//		GheD temp;
//		*this = temp;
//		type = "D";
//	}
//}
//
//class Rap {
//private:
//	vector<vector<Ghe>> list;
//	int row;
//	int col;
//public:
//	void Nhap();
//	void Xuat();
//	void Book();
//	void Gia();
//};
//
//void Rap::Gia() {
//	cout << "Nhap ma so : ";
//	string pos;
//	int sum = stoi(pos);
//	int r = sum / 10;
//	int c = sum % 10;
//
//	cout<<"Gia tien cua ghe da chon : "<<list[r][c].Gia();
//}
//void Rap::Nhap() {
//	cout << "Nhap so hang : ";
//	cin >> row;
//	cout << "Nhap so ghe moi han : ";
//	cin >> col;
//
//	list.resize(row);
//	for (int i = 0; i < row; i++) {
//		list[i].resize(col);
//	}
//
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < col; j++) {
//			Ghe temp;
//			temp.Nhap(1);
//			list[i][j] = temp;
//		}
//	}
//
//	for (int i = 3; i < row - 1 ; i++) {
//		for (int j = 0; j < col; j++) {
//			Ghe temp;
//			temp.Nhap(2);
//			list[i][j] = temp;
//
//		}
//	}
//
//	for (int j = 0; j < col; j++) {
//		Ghe temp;
//		temp.Nhap(3);
//		list[row - 1][j] = temp;
//	}
//
//}
//
//void Rap::Xuat() {
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < col; j++) {
//			list[i][j].Xuat();
//			cout << " ";
//		}
//		cout << endl;
//	}
//}
//
//void Rap::Book() {
//	string pos;
//	cout << "Nhap vi tri muon dat ghe : ";
//	cin.ignore();
//	getline(cin, pos);
//
//	vector<string> Npos;
//	vector<vector<int>> posI;
//	string buffer = "";
//
//	posI.resize(row);
//	for (int j = 0; j < row; j++) {
//		posI[j].resize(col);
//	}
//
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < col; j++) {
//			posI[i][j] = 0;
//		}
//	}
//
//	while (pos.find(' ') != -1) {
//		int space = pos.find_first_of(' ');
//		Npos.push_back(pos.substr(0, space));
//		pos = pos.substr(space + 1,pos.size());
//	}
//	Npos.push_back(pos);
//	
//	for (int i = 0; i < Npos.size(); i++) {
//		int sum = stoi(Npos[i]);
//		int r = sum / 10;
//		int c = sum % 10;
//		posI[r][c] = 1;
//	}
//
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < col; j++) {
//			if (posI[i][j] == 1) {
//				list[i][j].SetType("X");
//			}
//		}
//	}
//	
//}
//
//int main() {
//	
//	Rap a;
//	a.Nhap();
//	//a.Xuat();
//
//
//	//a.Book();
//	//a.Xuat();
//
//	a.Gia();
//}
