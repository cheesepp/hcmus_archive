// testFreopen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main()
{
	int a[3][4];
	FILE* f1 = freopen("input.txt", "r", stdin);
	
	if (!f1) {
		cout << "Khong mo duoc!";
		exit(1);
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> a[i][j];
		}
	}
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	fclose(f1);
	int a2[3][4];
	FILE* f2 = freopen("input1.txt", "r", stdin);
	if (!f2) {
		cout << "Khong mo duoc!";
		exit(1);
	}
	cout << "Mo thanh cong!\n";
	cin.clear();
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> a2[i][j];
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << a2[i][j] << " ";
		}
		cout << endl;
	}
}
////
////// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
////// Debug program: F5 or Debug > Start Debugging menu
////
////// Tips for Getting Started: 
//////   1. Use the Solution Explorer window to add/manage files
//////   2. Use the Team Explorer window to connect to source control
//////   3. Use the Output window to see build output and other messages
//////   4. Use the Error List window to view errors
//////   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//////   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
//
//#include <iostream>
//#include <ctime>
//
//using namespace std;
//class Person {
//private:
//    string name;
//    int age;
//public:
//    Person(string _name, int _age) {
//        name = _name;
//        age = _age;
//    }
//    virtual void print() {
//        cout << name << endl;
//        cout << age << endl;
//    }
//};
//
//class Student : public Person {
//private:
//    float gpa;
//public:
//    Student(string _name, int _age, float _gpa) : Person(_name, _age) {
//        gpa = _gpa;
//    }
//
//    void print() {
//        Person::print();
//        cout << gpa << endl;
//    }
//
//
//};
//
//int main() {
//    Person* p = new Student(
//        "chip", 20, 9.8);
//    p->print();
//
//}
