#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

int ReadFile(const char* filename) {
	ifstream fin(filename);
	if (!fin) {
		return 0;
	}
	cout << "Da mo " << filename;
	int n;
	fin >> n;
	fin.ignore();
	char name[30];
	fin.getline(name, 30);
	char code[30];
	fin.getline(code, 30);
	char NgaySinh[30];
	fin.getline(NgaySinh, 30);
	char* ngay;
	ngay = strtok(NgaySinh, "/");
	char* thang = strtok(NULL, "/");
	char* nam = strtok(NULL," ");
	float marks[3];
	fin >> marks[0] >> marks[1] >> marks[2];
	return 1;

}
int main() {
	ReadFile("INPUT.txt");
}